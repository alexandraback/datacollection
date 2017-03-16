#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FILE ""

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int K = 5;
int c, d, v;
vector<int> a;
bool f[40];
bool dp[20][40];
int ans;

void rec(int p, int x) {
  dp[0][0] = true;
  for (int i = 1; i <= (int)a.size(); ++i) {
    for (int j = 0; j <= v; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j - a[i - 1] >= 0) {
        dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
      }
    }
  }
  bool ok = true;
  for (int j = 0; j <= v; ++j) {
    if (!dp[(int)a.size()][j]) {
      ok = false;
      break;
    }
  }
  if (ok) {
    ans = min(ans, p);
  }
  if (p < K) {
    for (int i = x; i <= v; ++i) {
      if (!f[i]) {
        f[i] = true;
        a.pb(i);
        rec(p + 1, i + 1);
        a.pop_back();
        f[i] = false;
      }
    }
  }
}

int main() {
#ifdef HOME
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  //freopen(FILE ".in", "r", stdin);
  //freopen(FILE ".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  int ts;
  cin >> ts;
  for (int ti = 0; ti < ts; ++ti) {
    cin >> c >> d >> v;
    a.clear();
    memset(f, 0, sizeof f);
    for (int i = 0; i < d; ++i) {
      int x;
      cin >> x;
      a.pb(x);
      f[x] = true;
    }
    ans = INF;
    rec(0, 1);
    cout << "Case #" << ti + 1 << ": " << ans << "\n";
  }
  return 0;
}
