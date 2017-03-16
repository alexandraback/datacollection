#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const ld EPS = 1e-9;
const int INF = 1e9;

int r, c, w;

int dp[22][22][22];

int calc(int len, int l, int r) {
  int& d = dp[len][l][r];

  if  (d != -1) {
    return d;
  }

  if  (l > r || len < w) {
    return (d = INF);
  }

  if  (len == w || (l == 0 && l < r) || (r == len && l < r) || r - l == w) {
    return (d = (w - (r - l)));
  }

  d = INF;
  forn(i, len) {
    if  (l <= i && i < r) {
      continue;
    }

    int dp1, dp2;
    if  (r - l > 0) {
      dp1 = i < l ? (calc(len, i, r) + (l - i + 1) - 2) : (calc(len, l, i + 1) + (i - r + 1) - 1);
      dp2 = i < l ? calc(len - (i + 1), l - (i + 1), r - (i + 1)) : calc(len - (len - i), l, r);
    } else {
      dp1 = calc(len, i, i + 1);
      dp2 = calc(max(i, len - i - 1), 0, 0) + min(i, len - i - 1) / w;
    }

    int cur = max(dp1 + 1, dp2 + 1);
    d = min(d, cur);
  }

//  printf("%d %d %d -> %d\n", len, l, r, d);
  return d;
}

int solve() {
  int ans = 0;
  while (r > 1) {
    ans += c / w;
    --r;
  }

  memset (dp, -1, sizeof dp);  
  return ans + calc(c, 0, 0);
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  freopen(FILE_NAME ".out", "w", stdout);
#endif

  int T;
  scanf("%d", &T);
  forn(tt, T) {
    scanf("%d%d%d", &r, &c, &w);
    printf("Case #%d: %d\n", tt + 1, solve());
  }

  return 0;
}
