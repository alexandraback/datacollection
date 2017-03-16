#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <limits>
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

int A[66][66];

int main() {
#ifdef LOCAL_HOST
  freopen("B-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  cout.sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  FOR(tt, 1, T + 1) {
    cout << "Case #" << tt << ": ";
    int B;
    ll M;
    cin >> B >> M;
    const ll MAX = 1ll << (B - 2);
    if (M > MAX) {
      cout << "IMPOSSIBLE\n";
      continue;
    }
    cout << "POSSIBLE\n";
    CL(A, 0);
    rep(i, B - 1) {
      FOR(j, i + 1, B - 1) { A[i][j] = 1; }
    }
    if (M == MAX) {
      rep(i, B - 1) A[i][B - 1] = 1;
    } else {
      VI d;
      for (ll t = M; t > 0; t >>= 1) {
        d.pb(t & 1);
      }
      rep(i, (int)d.size()) {
        if (d[i]) {
          A[i + 1][B - 1] = 1;
        }
      }
    }
    rep(i, B) {
      rep(j, B) cout << A[i][j];
      cout << endl;
    }
  }

  return 0;
}
