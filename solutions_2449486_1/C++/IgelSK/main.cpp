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

int tn;
int a[111][111];
int n,m;
int c[111][111];

inline bool can() {
    FI(i,n) {
        bool canFill = true;
        FI(j,m) if (c[i][j]==1) {canFill = false; break;}
        if (canFill) FI(j,m) c[i][j] = 2;
    }
    FI(j,m) {
        bool canFill = true;
        FI(i,n) if (c[i][j]==1) {canFill = false; break;}
        if (canFill) FI(i,n) c[i][j] = 2;
    }
    FI(i,n) FI(j,m) if (c[i][j] == 0) return false;
    return true;
}

void solution() {
    tn = gi();
    FI(it,tn) {
        printf("Case #%d: ",it+1);
        scanf("%d%d",&n,&m);
        FI(i,n) FI(j,m) scanf("%d",&a[i][j]);
        V(int) values;
        FI(i,n) FI(j,m) values.push_back(a[i][j]);
        sort(ALL(values));
        bool possible = true;
        values.resize(unique(ALL(values)) - values.begin());
        for (int k = values.size()-1; k>=0; --k) {
            FI(i,n) FI(j,m) c[i][j] = a[i][j] > values[k];
            if (!can()) {possible = false; break;}
        }
        printf("%s\n",possible?"YES":"NO");
    }
}


// code ends here

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
















