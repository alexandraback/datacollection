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
    
    pair<string, pair<string,string> > dp_according(string s1, string s2, bool more)
    {
        
        
        // if more is false:
        //     solve assuming s1 <= s2, minimize s2 - s1, then s1, then s2
        // if more is true:
        //     solve assuming s1 > s2, minimize s2 - s1, then s1, then s2
        int n = s1.size();
        // why the hell am I using pairs?
        pair<string,pair<string,string>> dp[n+1][2][2];
        
        for (int t = n; t >= 0; t--) {
            const string INF(n - t + 1, ':');
            for (int eq = 0; eq < 2; eq++) {
                for (int last_carry = 0; last_carry < 2; last_carry++) { 
                    dp[t][eq][last_carry] = {INF, {INF,INF} }; 
                    
                    if (t == n) {
                        if (last_carry == 0) {
                            // nothing to do
                            dp[t][eq][last_carry] = {"", {"",""}};
                        } else {
                            //cout<< "FAIL"<<endl;
                        }
                    } else {
                        for (char a = '0'; a <= '9'; a++) {
                            for (char b = '0'; b <= '9'; b++) {
                                for (int carry = 0; carry < 2; carry++) {
                                    if ( s1[t] != '?' && s1[t] != a ) {
                                        continue;
                                    }
                                    if ( s2[t] != '?' && s2[t] != b ) {
                                        continue;
                                    }
                                    char A = a, B = b;
                                    //cout << A << " ~~ " << B << endl;
                                    if (more) {
                                        swap(A,B);
                                    }
                                    // {s_a <= s_b}
                                    int neq = eq;
                                    if (eq) {
                                        if (A > B) {
                                            continue;
                                        } else if (A != B) {
                                            neq = 0;
                                        }
                                    }
                                    
                                    // do
                                    // B - carry - A
                                    char C = char( int(B) - carry - int(A) + '0' );
                                    if (C < '0') {
                                        C += 10;
                                        if (last_carry == 0) {
                                            continue;
                                        }
                                    } else if (last_carry) {
                                        continue;
                                    }
                                    
                                    if (! ('0' <= C && C <= '9') ) {
                                        continue;
                                    }
                                    if (more) {
                                        swap(A,B);
                                    }
                                    auto q = dp[t + 1][neq][carry];
                                    if (q.first[0] != ':') {
                                        q.first = string(1, C) + q.first;
                                        q.second.first = string(1, A) + q.second.first;
                                        q.second.second = string(1, B) + q.second.second;
                                        dp[t][eq][last_carry] = std::min(dp[t][eq][last_carry], q);
                                    }
                                    
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
        
        auto res = dp[0][1][0];
        return res;   
    }

    

    pair<string,string> solve(string s1, string s2)
    {
        auto r1 = dp_according(s1,s2, false);
        auto r2 = dp_according(s1,s2, true);
        
        /*cout << r1.first << ", " << r1.second.first<<" , "<<r1.second.second << endl;
        cout << r2.first << ", " << r2.second.first<<" , "<<r2.second.second << endl;*/
        
        auto r = std::min(r1,r2);
        return r.second;
        
    }
    
    void init() { }
    string s1, s2;
    void read() {
        cin >> s1 >> s2;
    }
    #if MAX_THREADS > 1
        ofstream cout;
    #endif
    void write(int cn) {
        auto q = solve(s1,s2);
        cout << "Case #"<<cn<<": "<<q.first << " " << q.second << endl;
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
