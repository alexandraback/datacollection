#pragma comment(linker, "/STACK:33554432")

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <memory.h>

using namespace std;

#define REP(i,n) for(int i=0;i<n;++i)
#define ABS(n) ((n)<0 ? -(n) : (n))
#define SQR(a) (a)*(a)
#define MIN(a,b) (a<b?a:b)
#define MAX(a,b) (a>b?a:b)
#define MP make_pair
#define PB push_back
#define FILL(a) memset(a,0,sizeof(a));
#define COPY(a,b) memcpy(a,b,sizeof (b));
#define SI(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define y1 yyyyy1
#define prev prevvvvv
#define LL long long
const double PI = 2*acos(0.0);
const double EPS = 1e-8;
const int INF = (1<<30)-1;

double tek[30000], tmp[30000];

LL getDs (LL layer) {
    return layer * (2 * layer - 1);
}

double sumUpto (LL m, LL n) {
    memset (tek, 0, (m+1)*sizeof(double));
    memset (tmp, 0, (m+1)*sizeof(double));
    tek[0] = 1.;
    for (int i = 1; i <= n; ++i) {
        memcpy (tmp, tek, min<int>(i,m+1)*sizeof(double));
        memset (tek, 0, min<int>(i,m+1)*sizeof(double));
        for (int j = i; j > 0; --j) tek[j] = (tmp[j] + tmp[j-1]) / 2.;
        tek[0] = tmp[0] / 2.;
    }
    double ans = 0;
    for (int i = 0; i <= m; ++i) ans += tek[i];
    return ans;
}

double getIt (LL n, LL x, LL y) {
    LL layer = (abs(x) + y) / 2 + 1;
    if (n <= getDs (layer - 1)) return 0.0;
    if (n >= getDs (layer)) return 1.0;
    
    if (y == 2*(layer-1)) return  0.0;

    LL rest = n - getDs (layer - 1);
    LL need = y + 1;
    LL maxOther = rest - need;
    if (maxOther < 0) return 0.0;
    if (maxOther >= 2*(layer-1)) return 1.;

    return sumUpto (maxOther, rest);
}

int main(){
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
    int tc;
    cin >> tc;
    REP(ic,tc) {
        LL n, x, y;
        cin >> n >> x >> y;
        printf ("Case #%d: %.15lf\n", ic+1, getIt (n, x, y));
    }
	return 0;
};