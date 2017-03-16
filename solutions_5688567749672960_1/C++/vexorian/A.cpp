// No idea what I am doing
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
    string N; 
    
    long s2i(const string &s)
    {
        istringstream st(s);
        long res;
        st >> res;
        return res;
    }
    
    long solve()
    {
        vector<long> pow10(20);
        pow10[0] = 1;
        for (int i = 1; i < 20; i++) {
            pow10[i] = pow10[i-1] * 10;
        }
        
        if (N.size() == 1) {
            return N[0]-'0';
        }
        string x = "10";
        long c = 10;
        
        while (x.size() < N.size()) {
            // x =     100..0
            // get to:
            //        1000..0
            int n = x.size();
            int nine = n / 2;
            long movecost = 0;
            for (int i = 1; i <= nine; i++) {
                movecost = movecost * 10 + 9;
            }
            // now we have:
            //    |-- ceil(n/2)  --|| --- floor(n/2) ---|
            // x = 1000000000000..0  999999999999999...9
            // reverse:
            movecost = movecost + 1;
            //    |-- floor(n/2)  --|| --- ceil(n/2) ---|
            // x = 9999999999999..9  000000000000000...1
            long tx = 0;
            for (int i = 1; i <= n/2; i++) {
                tx = tx*10 + 9;
            }
            for (int i = 1; i <= (n - n/2) - 1; i++) {
                tx = tx*10;
            }
            tx = tx*10 + 1;
            movecost += pow10[n] - tx;
            //cout << x << " -> "<<tx<<" -> "<<pow10[n] << " = "<<movecost << endl;
            x = to_string(pow10[n]);
            c += movecost;
        }
        // now x and N have the same lengths
        long finalMove = s2i(N) - s2i(x);
        for (int fix = -1; fix < (int)N.size(); fix++) {
            long ifN = s2i(N);
            if (fix != -1) {
                ifN = s2i(N) - pow10[fix];
            }
            string fN = to_string(ifN);
            //cout << "fix = "<<fN<<endl;
            if (fN.size() < N.size()) {
                continue;
            }
            for (int i = 1; i < N.size(); i++) {
                // 
                string s = fN;
                for (int j = i; j < N.size(); j++) {
                    s[j] = '0';
                }
                s[N.size() - 1] = '1';
                string r = s;
                reverse(r.begin(), r.end());
                if (s > N || r > N) {
                    continue;
                }
                //cout << numeric_limits<long>::max() << endl;
                long cost = s2i(r) - s2i(x) + 1 + s2i(N) - s2i(s);
                finalMove = std::min(finalMove, cost );
                //cout << x << " -> " <<r << " -> " << s <<" -> "<<N<<" = "<<cost<<" ("<<finalMove<<")"<<endl;
            }
        }
        
        
        c += finalMove;
        return c;
    }
    void init() { }
    void read() {
        cin >> N;
    }
    #if MAX_THREADS > 1
        ofstream cout;
    #endif
    void write(int cn) {
        cout << "Case #"<<cn<<": " << solve() << endl;
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
