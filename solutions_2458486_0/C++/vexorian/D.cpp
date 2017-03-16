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
    int N, K;
    
    int initialKeys[40];
    int chests[20][40];
    int chestKeys[20];
    int chestType[20];
    
    vector<int> mem[1<<20]; 
   
    void solve( ostream& cout ) {
        mem[0] = vector<int>(0);
        const int INF = N*(N + 1);
        for (int mask=1; mask <(1<<N); mask++) {
            mem[mask] = vector<int>(1, INF);
            
            map<int, int> keys;
            for (int i = 0; i < K; i++) {
                keys[ initialKeys[i] ]++;
            }
            
            for (int j=0; j < N; j++) {
                if ( !( (1<<j) & mask ) ) {
                    keys[ chestType[j] ]--;
                    for (int k = 0; k < chestKeys[j]; k++) {
                        keys[ chests[j][k] ]++;
                    }
                }
            }
            for (int j=0; j < N; j++) {
                if  ( (1<<j) & mask ) {
                    if (keys[ chestType[j] ] > 0) {
                        vector<int> other = mem[ mask - (1<<j) ];
                        if ( (other.size() == 0) || (other[0] != INF) ) {
                            vector<int> nw( other.size() + 1);
                            nw[0] = j+1;
                            for (int i=1; i<nw.size(); i++) {
                                nw[i] = other[i-1];
                            }
                            mem[mask] = std::min( mem[mask], nw) ;
                        }
                    }
                }
            }
        }
        vector<int> &res = mem[ (1<<N) - 1];
        
        if (res[0] != INF)  {
            cout << res[0];
            for (int i = 1; i < N; i++) {
                cout << " "<<res[i];
            }
        } else {
            cout << "IMPOSSIBLE";
        }
        cout << endl;
    }

    
    void init() {}
    void read(istream& cin) {
        assert(cin >> K >> N);
        for (int i=0; i<K; i++){
            cin >> initialKeys[i];
        }
        for (int i=0; i<N; i++) {
            cin >> chestType[i] >> chestKeys[i];
            for (int j=0; j<chestKeys[i]; j++) {
                cin >> chests[i][j];
            }
        }
    }
    void write(int cn, ostream& cout) {
        cout << "Case #"<<cn<<": ";
        solve(cout);
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
        cout << endl;
    }
    
    return 0;
}
