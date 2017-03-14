#ifdef VX_PRECOMPILED
#include "precomp.h"
typedef mpz_class big;
#else
#include<string>
#include<iostream>
#include<sstream>
#include<.h>
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
const bool ENABLE_MULTI_PROCESS = false;
using namespace std;


//=========================================================
// program:
//
int W, H, D;
char grid[31][31];

int solveHorz(int M, int m0)
{
    return ( (2*m0 <= D) + ( 2*(M - m0) <= D) ); 
}


int gcd(int a, int b)
{
    if (a < 0) {
        return gcd(-a, b);
    } else if (b < 0) {
        return gcd(a, -b);
    } else if (a < b) {
        return gcd(b,a);
    }
    while (b != 0) {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}

int solve00(int W, int H, int x0, int y0)
{
 /*   ____________________
     |
     |
     |
     |          (x0,y0)
     |
     |____________________
   (0,0)
 */
     int total = 0;
     set< pair<int,int> > st;
     for (int bx = 0; bx < 50; bx++) {
         for (int by = 0; by < 50; by++) {
             int dx = bx*W + ( (bx&1) ? (W - x0) : x0 );
             int dy = by*H + ( (by&1) ? (H - y0) : y0 );
             
             //2*sqrt(dx*dx + dy*dy) <= D 
             
             if ( 4*(dx*dx + dy*dy) <= D*D) {
                 int g = gcd(dx,dy);
                 st.insert( make_pair( dx/g, dy/g ) );
                 //cout << dx/g <<", "<<dy/g<<" ( "<<bx<<","<<by<<")"<<endl;
             }
         }
     }


    return st.size();
}

int solveEx(int W, int H, int x0, int y0)
{
     int total = 0;
     set< pair<int,int> > st;
     for (int bx = 0; bx < 50; bx++) {
         for (int by = 0; by < 50; by++) {
             if ( ! bx && !by ) continue;
             int dx = bx*W;
             int dy = by*H;
             
             //2*sqrt(dx*dx + dy*dy) <= D 
             
             if ( 4*(dx*dx + dy*dy) <= D*D) {
                 int g = gcd(dx,dy);
                 st.insert( make_pair( dx/g, dy/g ) );
                 //cout << dx/g <<", "<<dy/g<<" ( "<<bx<<","<<by<<")"<<endl;
             }
         }
     }
     return st.size()*2;;
}

#define sign(x) (x/abs(x))
int solveFinal(int W, int H, int x0, int y0)
{
     int total = 0;
     set< pair<int,int> > st;
     for (int bx = -200; bx < 200; bx++) {
         for (int by = -200; by < 200; by++) {
             if ( !bx && !by ) continue;
             
             
             int dx, dy;
             if (bx & 1) {
                 dx = W * (bx- sign(bx) ) + 2*( (bx >= 0)?x0:(x0-W));
             } else {
                 dx = bx*W;
             }
             if (by & 1) {
                 dy = H * (by - sign(by) ) + 2*( (by >= 0)?y0:(y0-H));
             } else {
                 dy = by*H;
             }
             
             //2*sqrt(dx*dx + dy*dy) <= D 
             
             if ( (dx*dx + dy*dy) <= D*D) {
                 int g = gcd(dx,dy);
                 int tm = st.size();
                 st.insert( make_pair( dx/g, dy/g ) );
                 //if (tm != st.size()) cout << " " << dx/g <<", "<<dy/g<<" ( "<<bx<<","<<by<<")"<<" ( "<<dx<<","<<dy<<")"<<endl;
             }/* else if ( (D==2) && abs(bx)<=2 && abs(by) <= 2) {
                 int g = gcd(dx,dy);
                 //cout << "*" << dx/g <<", "<<dy/g<<" ( "<<bx<<","<<by<<")"<<" ( "<<dx<<","<<dy<<")"<<endl;
             }*/
         }
     }


     return st.size();
}


int solveDiag(int W, int H, int x0, int y0)
{
/*    int a,b,c,d, e;
    int total = 0;
    a= solve00(W, H, x0, y0);
    b= solve00(W, H, x0, H-y0);
    c= solve00(W, H, W-x0, y0);
    d= solve00(W, H, W-x0, H-y0);
    e = solveEx(W, H, x0, y0);
    
    cout<<"da "<<a<<endl;
    cout<<"db "<<b<<endl;
    cout<<"dc "<<c<<endl;
    cout<<"dd "<<d<<endl;
    cout<<"ex "<<e<<endl;
    total = a+b+c+d+e;
    return total ;*/
    int a = solveFinal(W,H, x0, y0);
    //cout << "a "<<a<<endl;
    return a;
}

int solve() {
    int x0,y0;
    for (int i=0; i<W; i++) {
        for (int j=0; j<H; j++) {
            if (grid[i][j] == 'X') {
                x0 = i; y0 = j;
            }
        }
    }
    //cout << W <<", "<<H<<" ; "<<x0<<","<<y0<<" ;; "<<D<<endl;
    //Convert
    x0 = 2*x0 + 1;
    y0 = 2*y0 + 1;
    x0 -= 2;
    y0 -= 2;
    W = 2 * (W - 2);
    H = 2 * (H - 2);
    D *= 2;
    //cout << W <<", "<<H<<" ; "<<x0<<","<<y0<<" ;; "<<D<<endl;
    
    int A = solveDiag(W,H,x0,y0);
    return A;
    int B = solveHorz(W,x0);
    int C = solveHorz(H,y0);
    
    /*cout << endl << "diagonal = "<<A<<endl;
    cout << "horz = "<<B<<endl;
    cout << "vert = "<<C<<endl;*/
    
    return A + B + C;
    
}

inline void init(){}
//=========================================================
// I/O:
//
int main(int argc, const char* argv[])
{
    int mode = 0;
    if(argc >= 2) sscanf(argv[1],"%d",&mode);
    if ( ( mode == 0 ) && ENABLE_MULTI_PROCESS )
    {
        string inputfile = ".input";
        ( system("cat > .input") );
        /* I use a dual core CPU, so for long solutions I might use this
         multi-process thing, splitting the input in halves effectively
         halving execution time of slow solutions. But due to overhead it
         increases the time of fast solutions, so it is optional... */
        mode = 1;
        remove(".finished");
        cerr<<"--Multi process mode--"<<endl;
        //string inputfile = argv[2];
        string command = argv[0];
        command += " 2 < "+inputfile+" > .tem &";
        ( system(command.c_str()) );
        ( freopen(inputfile.c_str(),"r",stdin) );
    }
    
    init();
    int TestCases;
    cin>>TestCases;

    for (int _i=1;_i<=TestCases;_i++) {
        /* read input goes here */
        cin >> W >> H >> D;
        for (int i=0; i<W; i++) {
            for (int j=0; j<H; j++) {
                cin >> grid[i][j];
            }
        }
        
        if( (mode==0) || ( (mode!=2)== (_i*2<=TestCases) ) ) {            
            cerr<<"["<<_i<<" / "<<TestCases<<"]"<<endl;
            /* program call goes here */
            int x = solve();
            /* output result goes here */
            cout<<"Case #"<<_i<<": "<<x<<endl;            
        }
        else if(mode!=2) break;
        
        (cin);
    }
    if(mode==2) {
        ( system("echo done > .finished") );
    } else if(mode==1) {
        struct stat stFileInfo;
        while( stat(".finished",&stFileInfo)!=0);
        ( system("cat .tem") );
    }
    return 0;
}
