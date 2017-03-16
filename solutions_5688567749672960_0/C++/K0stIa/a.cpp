#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>
#include <limits>

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

typedef vector<ll> vl;

// 1 -> 19 -> 91 -> 109 -> 9001

ll rev(ll x) {
  ll y = 0;
  while (x > 0) {
    y = y * 10 + x % 10;
    x /= 10;
  }
  return y;
}

void solve1() {
  ll pw = 1;
  vl a = {0, 1};
  FOR(i, 1, 18) {
    pw *= 10;
    a.pb(pw + 9);
    a.pb(9 * pw + 1);
  }
  SORT(a);
  vl moves = {0, 1, 19};
  FOR(i, 3, (int)a.size()) {
    if (i & 1)
      moves.pb(moves.back() + 1);
    else
      moves.pb(a[i] - moves.back());
  }
  ll op = 0;
  ll n;
  cin >> n;
  // normalize
  for (; n > 0;) {
    ll m = rev(n);
    if (n % 10 != 0 && m % 10 == 1) break;
    if (n % 10 == 1) {
      if (m < n) {
        swap(n, m);
      } else {
        --n;
      }
    } else {
      --n;
    }
    ++op;
  }
  auto it = lower_bound(all(a), n);
  int k = int(it - a.begin());
  if (a[k] > n) --k;
  op += moves[k] + n - a[k];
  cout << op;
}

void solve2() {
  ll n;
  cin >> n;
  ll op = 0;
  for (; n > 0;) {
    while (n > 0 && n % 10 != 1) {
      --n;
      ++op;
    }
    if (!n) break;
    if (n == 1) {
      ++op;
      break;
    }
    ll m = rev(n);
    if (m % 10 != 1 && n != m) {
      swap(m, n);
      ++op;
    }
    {
      ll pw = 1;
      while (pw * 10 <= n) pw *= 10;
      ll df = n - pw + 1;
      op += df;
      n -= df;
    }
  }
  cout << op;
}

map<ll, int> cache;

ll F(ll x) {
  if (x < 0) return 0;
  if (x <= 20) return x;
  if (x % 10 == 0) return F(x - 1) + 1;
  ll op = 0;
  if (x % 10 != 1) {
    ll df = x % 10 - 1;
    op += df;
    x -= df;
  }
  VI d;
  for (ll t = x; t > 0; t /= 10) d.pb(t % 10);
  ll m = 1, y = 0;
  ll ans = 1e18;
  for (int t : d) {
    if (y > 1) {
      // ll tmp = op + F(rev(n - y + 1)) + y;
      // if (tmp < ans) ans = tmp;
    }
    y += m * t;
    m *= 10;
  }
  ll tmp = 0;
  throw 0;
}

void solve3() {
  cache.clear();
  ll n;
  cin >> n;
  F(n);
}

int dg(ll n) {
  int cnt = 0;
  while (n > 0) n /= 10, ++cnt;
  return cnt;
}

ll lower(ll x) {
  VI d;
  while (x > 0) d.pb(x % 10), x /= 10;
  int n = (int)d.size();
  n = (n + 1) / 2;
  ll m = 1;
  ll v = 0;
  rep(i, n) {
    v = m * d[i] + v;
    m *= 10;
  }
  return v;
}

void solve() {
  ll n;
  cin >> n;
  ll op = 0;
  while (n > 0) {
    if (n % 10 == 0) {
      --n;
      ++op;
      continue;
    }
    ll m = lower(n);
    if (m > 1) {
      n -= m - 1;
      op += m - 1;
      continue;
    }
    assert(m == 1);
    m = rev(n);
    if (m < n) {
      op++;
      n = m;
      continue;
    }
    --n;
    ++op;
  }
  cout << op;
}

int main() {
#ifdef LOCAL_HOST
  //  freopen("input.txt", "r", stdin);
  freopen("A-small-attempt3.in", "r", stdin);
  freopen("A-small-attempt3.out", "w", stdout);
#endif

  cout.sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": ";
    solve();
    cout << endl;
  }

  return 0;
}
