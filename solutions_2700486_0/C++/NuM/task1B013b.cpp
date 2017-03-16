#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>

#define pb push_back
#define mp make_pair
#define PI 3.14159265358979
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

const int maxn = 4000;
ld dp[maxn][maxn];

void solve() {
  int n, x, y; scanf("%d%d%d", &n, &x, &y);
  if (x < 0) x = -x;
  int curcnt = 1;
  int level = 0;
  while (n >= curcnt) {
    n-=curcnt;
    ++level;
    curcnt += 4;
  }
  /*int level = 0;
  while ((level+1)*(2*level+1)<=n) ++level;
  --level;
  n -= (level+1)*(2*level+1);
  ++level;*/
  int needlevel = (x+y)/2;
  if (needlevel < level) {printf("1.0\n"); return;}
  if (needlevel > level || x == 0) {printf("0.0\n"); return;}
  int total = level*4;
  forn (i, n+5) forn(j, total/2+5) dp[i][j] = 0;
  dp[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= total/2; ++j) {
      if (j == total/2) dp[i+1][j] += dp[i][j];
      else if (i-j >= total/2) dp[i+1][j+1] += dp[i][j];
      else {
        dp[i+1][j] += .5*dp[i][j];
        dp[i+1][j+1] += .5*dp[i][j];
      }
    }
  }
  ld sum = 1;
  forn(i, y+1) sum -= dp[n][i];
  printf("%.15lf\n", (double)sum);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
  int T; scanf("%d", &T);
  forn(test, T) {
    printf("Case #%d: ", test+1);
    solve();
  }
	return 0;
}