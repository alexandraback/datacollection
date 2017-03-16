#include <set>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define REP(i,t) for(int i=0; i<(t); i++)
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define FORL(i,s,t) for(L i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
#define EPS 1e-6
#define EQ(a, b) (fabs((a) - (b)) <= EPS)
#define POS(a) ((a) >= EPS)
#define NEG(a) ((a) <= -EPS)
#define BG(a, b) ((a) - (b) >= EPS)
#define LS(a, b) ((b) - (a) >= EPS)
#define CLR(a, x) memset( a, x, sizeof( a ) )
#define PI (atan(1.0) * 4)
#define SQ(x) ((x) * (x))
#define DIST(x1, y1, x2, y2) (sqrt(SQ((x1) - (x2)) + SQ((y1) - (y2))))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define LOG2(x) (log(x) / log(2))
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
typedef pair<double, double> Pd;
typedef pair<int, int> Pi;
typedef pair<LL, LL> Pl;

LL e, r, n;
LL a[10010];

LL solve(int p, int q, LL start, LL end) {
  if (p == q)
    return (start - end) * a[p];
  LL m = a[p];
  int mi = p;
  FOR(i, p + 1, q + 1)
    if (a[i] > m) {
      m = a[i];
      mi = i;
    }
  LL tmp1 = min(start + (mi - p) * r, e);
  LL tmp2 = max(0LL, end - (q - mi) * r);

  LL act = tmp1 - tmp2;
  LL ans = m * act;
  if (mi > p)
    ans += solve(p, mi - 1, start, max(0LL, tmp1 - r));
  if (mi < q)
    ans += solve(mi + 1, q, min(e, tmp2 + r), end);
  return ans;
}

int main()
{
  int t;
  cin >> t;
  FOR(tt, 1, t + 1) {
    cin >> e >> r >> n;
    REP(i, n)
      cin >> a[i];
    cout << "Case #" << tt << ": " << solve(0, n - 1, e, 0);
    cout << endl;
  }
  return 0;
}

