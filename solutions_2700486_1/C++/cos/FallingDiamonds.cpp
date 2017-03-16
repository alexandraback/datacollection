#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    //puts("");
    solve();
  }
}

ll n, x, y;
double memo[3000][3000];
double calc(int d, int rest, int l, int r) {
  if (r > y) { return 1.0; }
  if (rest == 0) { return 0.0; }
  double &ret = memo[l][r];
  if (!isnan(ret)) { return ret; }
  ret = 0;
  double cnt = 0;
  if (l < 2 * d) { ret += calc(d, rest - 1, l + 1, r); cnt++; }
  if (r < 2 * d) { ret += calc(d, rest - 1, l, r + 1); cnt++; }
  assert(cnt != 0);
  ret /= cnt;
  return ret;
}

void solve() {
  MEMSET(memo, -1);
  scanf("%lld %lld %lld", &n, &x, &y);
  double ans = 0.0;
  {
    if (x == 0 && y == 0) { ans = 1.0; goto end; }
    n--;
    x = abs(x);
    ll d = (x + y) / 2;
    FOR(i, 1, d) { n -= 1 + 4 * i; }
    if (n <= 0) { ans = 0; goto end; }
    if (n >= 1 + 4 * d) { ans = 1.0; goto end; }
    if (x == 0) { goto end; }
    ans = calc(d, n, 0, 0);
  }
end:
  printf("%.10f\n", ans);
}

