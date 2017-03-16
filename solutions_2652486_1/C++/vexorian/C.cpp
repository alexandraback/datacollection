#ifdef VX_PRECOMPILED
    #include "precomp.h"
    typedef mpz_class big;
    // I use 4 cores :)
    #define MAX_THREADS 4
#else
    #include<string>
    #include<iostream>
    #include<fstream>
    #include<sstream>
    #include<assert.h>
    #include<cstdio>
    #include<map>
    #include<algorithm>
    #include<bitset>
    #include<cmath>
    #include<queue>
    #include<functional>
    #include<set>
    #include<sys/stat.h>
    #include<numeric>
    #include<cstdio>
    #include<cstdlib>
    #include<cstring>
    // http://gmplib.org/ (uncomment if solution uses big nums)
    // most likely you'll get an error about mpz_class not being declared...
    //#include "gmpxx.h"
    #define big mpz_class
    // I figure that when other people want to test my solutions they shouldn't
    // get the whole multi-threaded mess that requires and deletes folders and files...
    #define MAX_THREADS 4
#endif

#define for_each(q,s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
typedef long long int64;
#define long int64

using namespace std;

//=========================================================
// program:
//
int N, M, K;
struct solver
{
    int cardProduct[7];
    
    string curr;
    double fact[13];
    double TOTAL;
    
    set< pair< double, string> > possibility;
    set< pair< double, string> > probable;
    
    map<string, map<int, double> > probableProduct;
    
    void rec(int x, char ch)
    {
        if (x == N) {
            // calculate the probability
            double p = fact[N];
            int i = 0; 
            while (i < N) {
                int j = i;
                while ( (j < N) && (curr[j] == curr[i] ) ) {
                    j++;
                }
                p /= fact[j - i];
                i = j;
            }
            p /= TOTAL;
            possibility.insert( make_pair(p, curr) );
        } else {
            for (char b = ch; b <= '0' + M; b++) {
                curr[x] = b;
                rec(x + 1, b);
            }
        }
    }
    
    void init()
    {
        TOTAL = 1;
        for (int i=0; i<N; i++) {
            TOTAL *= M - 1;
        }
        fact[0] = 1;
        for (int i=1; i <= 12; i++) {
            fact[i] = i * fact[i-1];
        }
        curr = string(N, '?');
        rec(0, '2');
        double P = 0.001;
        for_each(q, possibility) {
            P -= q->first;
            if (P < 0) {
                probable.insert( make_pair(q->first, q->second));
                string x = q->second;
                map<int, double> product;
                for (int i=0; i<(1<<N); i++) {
                    int p = 1;
                    for (int j=0; j<N; j++) {
                        if (i & (1<<j)) {
                            p *= x[j] - '0';
                        }
                    }
                    product[p] += p / (double)(1<<N);
                }
                probableProduct[x] = product;
            }
        }
        
    }
    
    string solve()
    {
        pair<double, string> best = make_pair(-1.0, string(N,'2') );
        for_each( q, probable) {
            string x = q->second; //a combination of cards
            double p = q->first; //probability to get those cards
            //calculate the probability to get each product
            map<int, double> & product = probableProduct[x];
            // probability to get all K products
            for (int i=0; i<K; i++) {
                if ( product.count(cardProduct[i])) {
                    p *= product[ cardProduct[i] ];
                } else {
                    p = 0;
                }
                
            }
            best = std::max( best, make_pair(p, x) );

        }
        
        return best.second;
    }
    void read() {
        for (int i=0; i<K; i++) {
            assert(cin >> cardProduct[i]);
        }
    }
    #if MAX_THREADS > 1
        ofstream cout;
    #endif
    void write(int cn) {
        cout << solve() << endl;
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
        int foo; cin >> foo;
        cin >> TestCases >> N >> M >> K;
        solver * theSolver = new solver;
        theSolver->init();
        cout << "Case #1:" << endl;
        for (int i=1; i<= TestCases; i++) {
            theSolver->read();
            theSolver->write(i);
        }
        //delete theSolver;    
    #else
        int foo; cin >> foo;
        cin >> TestCases >> N >> M >> K;
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
        if (mode == 0) {
            cout << "Case #1:" << endl;
        }
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
        //delete theSolver;
    #endif

    
    return 0;
}
