#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef DBG112
    #define dbg(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#else
    #define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const int N = 10;
int dp[1 << N][1 << N];

int solve(int n, int k, int maskShoot, int maskShip) {
  int & res = dp[maskShoot][maskShip];
  if (res != -1) {
    return res;
  }
  bool ok = false;
  for (int i = 0; i + k <= n; ++i) {
    int curMask = (((1 << k) - 1) << i);
    if ((maskShip & curMask) == maskShip && (maskShoot & curMask) == maskShip) {
      ok = true;
    }
  }
  if (!ok) {
    res = -2;
    dbg("dp[%d][%d] = %d\n", maskShoot, maskShip, res);
    return res;
  }
  int cntShip = 0, minShip = n, maxShip = -1;
  for (int i = 0; i < n; ++i) {
    if (maskShip & (1 << i)) {
      ++cntShip;
      minShip = min(minShip, i);
      maxShip = max(maxShip, i);
    }
  }
  if (cntShip == k) {
    assert(minShip + k - 1 == maxShip);
    res = 0;
    for (int i = 0; i < n; ++i) {
      if (maskShoot & (1 << i)) {
        ++res;
      }
    }
    dbg("dp[%d][%d] = %d\n", maskShoot, maskShip, res);
    return res;
  }
  for (int i = minShip; i <= maxShip; ++i) {
    if ((maskShoot & (1 << i)) == 0) {
      return res = solve(n, k, maskShoot | (1 << i), maskShip | (1 << i));
    }
  }
  res = n;
  for (int i = max(0, maxShip - k + 1); i < n && i < minShip + k; ++i) {
    if ((maskShoot & (1 << i)) == 0) {
      int cur = 0;
      cur = max(cur, solve(n, k, maskShoot | (1 << i), maskShip));
      cur = max(cur, solve(n, k, maskShoot | (1 << i), maskShip | (1 << i)));
      res = min(cur, res);
    }
  }
  dbg("dp[%d][%d] = %d\n", maskShoot, maskShip, res);
  return res;
}

void solve() {
  memset(dp, 0xff, sizeof(dp));
  int r, c, w;
  assert(scanf("%d%d%d", &r, &c, &w) == 3);
  assert(r == 1);
  printf("%d\n", solve(c, w, 0, 0));
}

int main()
{
  int tt;
  assert(scanf("%d", &tt) == 1);
  for (int ii = 1; ii <= tt; ++ii) {
    printf("Case #%d: ", ii);
    solve();
  }

  return 0;
}

