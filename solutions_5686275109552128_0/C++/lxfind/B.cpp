#include <set>
#include <bitset>
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
#include <ctime>
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
#define EPS 1e-11
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
#define setmin(a, b) (a = min(a, b))
#define setmax(a, b) (a = max(a, b))
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

int a[10000];

int main()
{
  int t;
  cin >> t;
  FOR(tt, 1, t + 1) {
    int d;
    cin >> d;
    REP(i, d) {
      cin >> a[i];
    }
    int ans = 0;
    while (d) {
      sort(a, a + d);
      int m = a[d - 1];
      int split = 2;
      int maxbene = 0;
      int bestsplit = 0;
      while (1) {
        int sec = (m + split - 1) / split;
        int bene = m - sec - (split - 1);
        int i = d - 2;
        while (i >= 0 && bene > 0 && a[i] > sec) {
          bene -= (a[i] + sec - 1) / sec - 1;
          i--;
        }
        if (bene > maxbene) {
          maxbene = bene;
          bestsplit = split;
        }
        if (bene > 0) {
          split++;
        } else {
          break;
        }
      }
      if (maxbene > 0) {
        int sec = (m + bestsplit - 1) / bestsplit;
        d--;
        while (m > 0) {
          a[d++] = min(sec, m);
          m -= sec;
        }
        ans += bestsplit - 1;
      } else {
        int cur = 0;
        REP(i, d) {
          a[cur] = a[i] - 1;
          if (a[cur] != 0) {
            cur++;
          }
        }
        d = cur;
        ans++;
      }
    }
    cout << "Case #" << tt << ": " << ans << endl;
  }
  return 0;
}
