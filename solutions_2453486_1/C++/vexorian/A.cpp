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
    char board[4][4];
    
    int sign(int x) {
        return ( (x == 0) ? 0 : (x / abs(x) ) );
    }
    bool lineCheck(int x0, int x1, int y0, int y1, char p) {
        map<char, int> c;
        int y = y0;
        int x = x0;
        for (int i=0; i< 4; i++) {
            c[ board[x][y] ]++;
            x += sign(x1 - x0);
            y += sign(y1 - y0);
        }
        return (c['T'] + c[p]) == 4; 
    }
    
    string solve() {
        int e = 0;
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                e += (board[i][j] == '.');
            }
        }
        bool wins[2] = {false, false};
        string p = "XO"; 
        for (int i=0; i<2; i++) {
            wins[i] |= lineCheck(0,4, 0,4, p[i]);
            wins[i] |= lineCheck(3,-1, 0,4, p[i]);
            for (int j=0; j<4; j++) {
                wins[i] |= lineCheck(0,4, j,j, p[i]);
                wins[i] |= lineCheck(j,j, 0,4, p[i]);
            }
        }
        if (wins[0]) {
            return "X won";
        } else if (wins[1]) {
            return "O won";
        } else if (e > 0) {
            return "Game has not completed";
        } else {
            return "Draw";
        }
    }

    
    void init() {}
    void read(istream& cin) {
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                cin >> board[i][j];
            }
        }
    }
    void write(int cn, ostream& cout) {
        cout << "Case #"<<cn<<": "<<solve()<<endl;
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
