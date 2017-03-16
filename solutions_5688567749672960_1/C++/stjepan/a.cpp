#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1000100;

int dp[MAX];
int f[MAX];

llint rev(llint x) {
  if (x%10 == 0) return x;
  
  static int d[20];
  int n = 0;
  for (; x; x /= 10) d[n++] = x%10;

  llint ret = 0;
  REP(i, n) ret = ret*10 + d[i];
  return ret;
}

llint solve(llint x) {
  if (x < 100) return f[x];

  llint p = 1;
  while (p*p*10 <= x) p *= 10;

  llint y = rev(x);
  if (x % p == 1 && y < x) return solve(y) + 1;
  if (x % p <= 1) return solve(x-1) + 1;

  llint k = x % p - 1;
  return solve(x - k) + k;
}

int main() {
  FOR(x, 1, MAX) {
    dp[x] = dp[x-1] + 1;
    int y = rev(x);
    if (y < x) dp[x] = min(dp[x], dp[y] + 1);
  }

  FOR(x, 1, MAX) {
    f[x] = f[x-1] + 1;
    int y = rev(x);

    if (y < x) {
      llint p = 1;
      while (p*p*10 <= x) p *= 10;
      if (x % p == 1) f[x] = f[y] + 1;
    }
    assert(f[x] == dp[x]);
  }


  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    llint N; scanf("%lld", &N);
    printf("Case #%d: %lld\n", tt, solve(N));
  }
  return 0;
}
