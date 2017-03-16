#ifdef VX_PRECOMPILED
#include "precomp.h"
typedef mpz_class big;
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
// http://gmplib.org/ (uncomment if solution does not use big nums)
#include "gmpxx.h"
#define big mpz_class
#endif

#define for_each(q,s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
typedef long long int64;
#define long int64
// Number of concurrent processes solving the input
const int MAX_THREADS = 4;
using namespace std;

//=========================================================
// program:
//
struct solver
{
    int A, B;
    int solve(ostream & cout)
    {
        vector<bool> isSquare(B + 1, false);
        isSquare[1] = true;
        int c = 0;
        for (int i=1; i<=B; i++) {
            ostringstream st;
            st << i;
            string s = st.str();
            string t = s;
            reverse(t.begin(), t.end());
            if (s == t) {
                //palindrome
                if (i <= B / i) {
                    isSquare[i*i] = true;
                }
                if (isSquare[i] && (i >= A) ) {
                    c++;
                }
            }
        }
        return c;
    }

    
    void init() {}
    void read(istream& cin) {
        cin >> A >> B;
    }
    void write(int cn, ostream& cout) {
        cout << "Case #"<<cn<<": "<<solve(cout)<<endl;
    }
};

//=========================================================
// I/O:
//


void run(const char* x)
{
    int r = system(x);
    cerr<<x<<" "<<"("<<r<<")"<<endl;
}
int main(int argc, const char* argv[])
{
    int TestCases;
    if (MAX_THREADS == 1) {
        //simple mode
        cin >> TestCases;
        solver* s = new solver;
        s->init();
        for (int i=1; i<=TestCases; i++) {
            cerr << "[" << i <<"/" << TestCases << "]"<< endl;
            s->read(cin);
            s->write(i, cout ) ;
        }
        delete s;
        
        return 0; 
    }
    int mode = 0;
    if(argc >= 2) sscanf(argv[1],"%d",&mode);
    
    if ( ( mode == 0 ) && (MAX_THREADS > 1) ) {
        string inputfile = ".input";
        run("cat > .input");
        assert( freopen(inputfile.c_str(),"r",stdin) );

        cin>>TestCases;
        for (int i=1; i<=TestCases; i++) {
            char fn[200];
            sprintf(fn, ".test.%d", i);
            remove(fn);
            sprintf(fn, ".test.%d.out", i);
            remove(fn);
        }
       

        cerr<<"--Multi process mode--"<<endl;
        for (int i = 1; i < MAX_THREADS; i++) {
            string command = argv[0];
            string ch (1, i + '0');
            command += " "+ch+" < "+inputfile+" > .tem &";
            run(command.c_str());
        }
    } else {
        cin>>TestCases;
    }
    solver * theSolver = new solver;
    theSolver->init();
    for (int i=1; i<= TestCases; i++) {
        theSolver->read(cin);
        ofstream f;
        char fn1[200], fn2[200];
        sprintf(fn1, ".test.%d", i);
        sprintf(fn2, ".test.%d.out", i);
        f.open(fn1, ios_base::out | ios_base::in);
        if ( !f ) {
            f.open(fn1, ios_base::out);
            //good, do it
            cerr << "[" << i << "/"<<TestCases<<"] "<<mode << endl;
            theSolver->write(i, f);
            f.close();
            f.open(fn2);
            f << "1" << endl;
        } 
    }
    delete theSolver;
    if (mode == 0) {
        //time to merge results...
        for (int i=1; i<= TestCases; i++) {
            char fn1[200], fn2[200];
            sprintf(fn1, ".test.%d", i);
            sprintf(fn2, ".test.%d.out", i);
            struct stat stFileInfo;
            while ( stat(fn2, &stFileInfo) !=0 ) {
                sleep(1);
            }
            sprintf(fn1, ".test.%d", i);
            ifstream f(fn1);
            cout << f.rdbuf();
        }
    }
    
    return 0;
}
