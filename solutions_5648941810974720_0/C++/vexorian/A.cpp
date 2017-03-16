#ifdef VX_PRECOMPILED
    #include "precomp.h"
    typedef mpz_class big;
    // I use 4 cores :)
    #define MAX_THREADS 4
#else
    #include <bits/stdc++.h>
    #include<sys/stat.h>
    #include<unistd.h>
    // http://gmplib.org/ (uncomment if solution uses big nums)
    // most likely you'll get an error about mpz_class not being declared...
    //#include "gmpxx.h"
    #define big mpz_class
    // I figure that when other people want to test my solutions they shouldn't
    // get the whole multi-threaded mess that requires and deletes folders and files...
    #define MAX_THREADS 1
#endif

#define for_each(q,s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
typedef long long int64;
#define long int64

using namespace std;

//=========================================================
// program:
//
struct solver
{
    const vector<string> DIGITS = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    
    string remove_letters(string s, char ch, int n)
    {
        multiset<char> S(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            assert(S.find(ch) != S.end());
            S.erase(S.find(ch));
        }
        return string(S.begin(), S.end());
    }
    
    string solve(string s)
    {
        int t = DIGITS.size();
        vector<bool> used(t, false);
        string res = "";
        for (int i = 0; i < t; i++) {
            int pick = -1;
            for (int j = 0; j < t; j++) {
                if (! used[j]) {
                    
                    for (char ch: DIGITS[j]) {
                        bool bad = false;
                        for (int k = 0; k < t; k++) {
                            if (! used[k] && k != j) {
                                if ( count(DIGITS[k].begin(), DIGITS[k].end(), ch) > 0) {
                                    bad = true;
                                }
                            }
                        }
                        if (! bad) {
                            pick = j;
                        }
                    }
                }
            }
            assert(pick != -1);
            used[pick] = true;
            string d = DIGITS[pick];
            
            vector<int> c(d.size(), 0);
            int m = s.size();
            for (int j = 0; j < d.size(); j++) {
                m = std::min<int>(m, count( s.begin(), s.end(),  d[j]) );
            }
            res += string(m, '0' + pick);
            for (int j = 0; j < d.size(); j++) {
                s = remove_letters(s, d[j], m);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
        
    }
    
    
    void init() { }
    string x;
    void read() {
        cin >> x; 
    }
    #if MAX_THREADS > 1
        ofstream cout;
    #endif
    void write(int cn) {
        cout << "Case #"<<cn<<": " << solve(x) << endl;
    }
    
};

//=========================================================
// I/O:
//
#if MAX_THREADS > 1
    void run(const char* x)
    {
        int r = system(x);
        cerr<<x<<" "<<"("<<r<<")"<<endl;
    }
#endif

int main(int argc, const char* argv[])
{
    int TestCases, mode;
    #if MAX_THREADS == 1
        // Simple and straight forward. 
        cin >> TestCases;
        solver * theSolver = new solver;
        theSolver->init();
        for (int i=1; i<= TestCases; i++) {
            theSolver->read();
            theSolver->write(i);
        }
        delete theSolver;    
    #else
        cin>>TestCases;
        //-------------------------------------------
        // Copy the whole input to a file...
        ofstream f;
        f.open("tests/.input");
        f << cin.rdbuf();
        f.close();
        // Yeah...wipe that folder... Cause we will need its files to be empty
        run("rm ./tests/.t*");
        int k = 0;
        mode = 0;
        // We create some extra threads...
        while (k < MAX_THREADS) {
            if ( fork() == 0 ) {
                mode = k + 1;
                break;
            }
            k++;
        }
        // Reopen the input, this happens for each of the threads...
        if (mode != 0) {
            assert( freopen( "tests/.input","r",stdin) );
        }
    
        solver * theSolver = new solver;
        theSolver->init();
        for (int i=1; i<= TestCases; i++) {
            // Yeah, I don't like this much either
            ofstream f;
            char fn1[200], fn2[200];
            sprintf(fn1, "tests/.test.%d", i);
            sprintf(fn2, "tests/.test.%d.done", i);
            if (mode == 0) {
                // main thread shall just join stuff together as it becomes ready
                struct stat stFileInfo;
                // When a thread finishes a test case, it writes the .done file
                // Wait for that...
                while ( stat(fn2, &stFileInfo) !=0 ) {
                    sleep(1);
                }
                // Now copy the output file...
                ifstream f(fn1);
                cout << f.rdbuf();
            } else {
                // The trick is to make each thread read all the inputs, whether
                // it will process it or not...
                theSolver->read();
                // If fn1 exists, it is being processed already. Else process it
                f.open(fn1, ios_base::out | ios_base::in);
                if ( !f ) {
                    theSolver->cout.open(fn1, ios_base::out);
                    cerr << "[" << i << "/"<<TestCases<<"] "<<mode << endl;
                    theSolver->write(i);
                    theSolver->cout.close();
                    f.open(fn2);
                    f << "1" << endl;
                }
            }
        }
        delete theSolver;
    #endif

    
    return 0;
}
