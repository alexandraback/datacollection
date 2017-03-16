#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <numeric>
#include <complex>
#include <string>
#include <ctime>
#include <unordered_set>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pnt;


#define FI(i,a) for (int i=0; i<(a); ++i)
#define FOR(i,s,e) for (LL i=(s); i<(e); ++i)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define V(t) vector < t >
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):(-(a)))
#define ALL(a) a.begin(),a.end()

#define dout(a) cerr << a << endl
#define sout(a) cerr << a << "  "

const double pi = 3.14159265358979323846264338327950288419716939937511;
const double eps = 1e-9;

//*
char ch_ch_ch[1<<20];
inline string gs() {scanf("%s",ch_ch_ch); return string(ch_ch_ch);}
inline string gl() {gets(ch_ch_ch); return string(ch_ch_ch);}
inline int gi() {int x; scanf("%d",&x); return x;}
//*/

//const int inf = 1000000000;

// code starts here


#define X first
#define Y second

int targetX, targetY;
int n;

pnt a[1000];
double ans;

inline bool canLeft(int x, int y, int n) {
    FI(i,n) if (a[i].X == x-1 && a[i].Y == y-1) return false;
    return true;
}

inline bool canRight(int x, int y, int n) {
    FI(i,n) if (a[i].X == x+1 && a[i].Y == y-1) return false;
    return true;
}

inline bool canDown(int x, int y, int n) {
    FI(i,n) {
        if (a[i].X == x && a[i].Y == y-2) return false;
        if (a[i].X == x-1 && a[i].Y == y-1) return false;
        if (a[i].X == x+1 && a[i].Y == y-1) return false;
    }
    return true;
}

void R(int x, int y, int pos, double prob) {
    if (pos == n) {
        FI(i,n) if (a[i].X == targetX && a[i].Y == targetY) ans+=prob;
        return;
    }

    if (y>0)
    {
        if (canDown(x,y,pos)) {
            R(x,y-1,pos,prob);
            return;
        }

        bool cl = canLeft(x,y,pos);
        bool cr = canRight(x,y,pos);
        if (cl && cr) {
            R(x-1,y-1,pos,prob/2.0);
            R(x+1,y-1,pos,prob/2.0);
            return;
        }
        if (cl) {
            R(x-1,y-1,pos,prob);
            return;
        }
        if (cr) {
            R(x+1,y-1,pos,prob);
            return;
        }
    }
    pnt old = a[pos];
    a[pos] = mp(x,y);
    R(0,30,pos+1,prob);
    a[pos] = old;

}


void solution() {
    int tn = gi();
    FI(it,tn) {
        n = gi();
        targetX = gi();
        targetY = gi();
        ans = 0;
        printf("Case #%d: ",it+1);
        R(0,30,0,1.0);
        printf("%.20lf\n",ans);
    }

}



// code endds here

int main(int argc, char** argv) {

#ifdef IGEL_ACM
    freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    clock_t beg_time = clock();
#else
    //freopen(argv[1],"r",stdin);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

#endif

    solution();

#ifdef IGEL_ACM
    fprintf(stderr,"*** Time: %.3lf ***\n",1.0*(clock()-beg_time)/CLOCKS_PER_SEC);
#endif

    return 0;
}
















