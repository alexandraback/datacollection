#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i, a, b) for (int _n(b), i(a); i < _n; i++)
#define rep(i, n) FOR(i, 0, n)
#define CL(a, v) memset((a), (v), sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;

/*** TEMPLATE CODE ENDS HERE */

const int N = 1010;
string a[N], b[N];

int solve_stupid() {
  int n;
  cin >> n;
  rep(i, n) cin >> a[i] >> b[i];
  int ans = 0;
  FOR(mask, 1, 1 << n) {
    set<string> d1, d2;
    rep(i, n) if ((mask >> i) & 1) {
      d1.insert(a[i]);
      d2.insert(b[i]);
    }
    bool can = true;
    rep(i, n) if (!((mask >> i) & 1)) {
      can &= d1.count(a[i]);
      can &= d2.count(b[i]);
    }
    if (can) {
      ans = max(ans, n - __builtin_popcount(mask));
    }
  }
  return ans;
}

int main() {
#ifdef LOCAL_HOST
  freopen("C-small-attempt0.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  FOR(tt, 1, T + 1) {
    cout << "Case #" << tt << ": ";
    cout << solve_stupid();
    cout << endl;
  }

  return 0;
}
