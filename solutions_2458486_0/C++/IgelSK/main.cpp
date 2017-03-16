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


int initKeys[222];
V(V(int)) chest;
V(int) need;
int k,n;



int dp[1<<20];

inline bool can(int mask, int ind) {
    int cnt = initKeys[need[ind]];
    FI(i,n) if ((mask>>i)&1) {
        if (need[i]==need[ind]) cnt--;
        FI(j,chest[i].size()) if (chest[i][j]==need[ind]) cnt++;
    }
    return (cnt>0);
}

int R(int mask) {
    if (mask == (1<<n)-1) return 1;
    int &r = dp[mask];
    if (r!=-1) return r;
    r = 0;
    FI(i,n) if (!((mask>>i)&1) && can(mask,i)) {
        if (R(mask|(1<<i))) return r = 1;
    }
    return r = 0;
}

int order[55];

void Rc(int mask, int p) {
    if (mask == (1<<n)-1) {
        FI(i,p) printf("%d%c",order[i],i+1==p?'\n':' ');
        return;
    }
    FI(i,n) if (!((mask>>i)&1) && can(mask,i)) {
        if (R(mask|(1<<i))) {
            order[p] = i+1;
            Rc(mask|(1<<i),p+1);
            return;
        }
    }
}

void solution() {
    int tn = gi();
    FI(it,tn) {
        printf("Case #%d: ",it+1);
        MEMS(dp,-1);
        MEMS(initKeys,0);
        k = gi();
        n = gi();
        FI(i,k) initKeys[gi()]++;
        chest.clear();
        chest.resize(n);
        need.clear();
        need.resize(n);
        FI(i,n) {
            need[i] = gi();
            int m = gi();
            FI(j,m) chest[i].push_back(gi());
        }
        if (!R(0)) printf("IMPOSSIBLE\n");
        else (Rc(0,0));
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
















