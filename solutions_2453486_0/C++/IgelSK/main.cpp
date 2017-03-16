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
char a[11][11];

// -1 - O wins
// 0 - nobody wins
// 1 - X wins

int chRow(int l) {
    int cnt = 0;
    FI(i,4) if (a[l][i] == 'T' || a[l][i] == 'O') cnt++;
    if (cnt == 4) return -1;
    cnt = 0;
    FI(i,4) if (a[l][i] == 'T' || a[l][i] == 'X') cnt++;
    if (cnt == 4) return 1;
    return 0;
}

int chCol(int l) {
    int cnt = 0;
    FI(i,4) if (a[i][l] == 'T' || a[i][l] == 'O') cnt++;
    if (cnt == 4) return -1;
    cnt = 0;
    FI(i,4) if (a[i][l] == 'T' || a[i][l] == 'X') cnt++;
    if (cnt == 4) return 1;
    return 0;
}

int chD1() {
    int cnt = 0;
    FI(i,4) if (a[i][i] == 'T' || a[i][i] == 'O') cnt++;
    if (cnt == 4) return -1;
    cnt = 0;
    FI(i,4) if (a[i][i] == 'T' || a[i][i] == 'X') cnt++;
    if (cnt == 4) return 1;
    return 0;
}

int chD2() {
    int cnt = 0;
    FI(i,4) if (a[i][3-i] == 'T' || a[i][3-i] == 'O') cnt++;
    if (cnt == 4) return -1;
    cnt = 0;
    FI(i,4) if (a[i][3-i] == 'T' || a[i][3-i] == 'X') cnt++;
    if (cnt == 4) return 1;
    return 0;
}





void solution() {
    cin >> tn;
    FI(it,tn) {
        printf("Case #%d: ",it+1);
        FI(i,4) scanf("%s",&a[i]);
        int filled = 0;
        FI(i,4) FI(j,4) if (a[i][j]!='.') filled++;
        int res = 0;
        FI(i,4) if (res==0) res = chRow(i);
        FI(i,4) if (res==0) res = chCol(i);
        if (res==0) res = chD1();
        if (res==0) res = chD2();
        if (res == 1) printf("X won\n");
        else if (res == -1) printf("O won\n");
        else if (filled == 16) printf("Draw\n");
        else printf("Game has not completed\n");
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
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

#endif

    solution();

#ifdef IGEL_ACM
    fprintf(stderr,"*** Time: %.3lf ***\n",1.0*(clock()-beg_time)/CLOCKS_PER_SEC);
#endif

    return 0;
}
















