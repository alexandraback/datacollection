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

bool solve(int K, int R, int C) {
  if (R < C) swap(R, C);
  if (R*C % K) return false;
  if (K == 1) return true;
  if (K == 2) return R >= 2;
  if (K == 3) return R >= 3 && C >= 2;
  if (K == 4) return R >= 4 && C >= 3;
  if (K == 5) return R >= 5 && C >= 3;
  if (K == 6) return R >= 6 && C >= 4;
  return false;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    int K, R, C; scanf("%d%d%d", &K, &R, &C);
    printf("Case #%d: %s\n", tt, solve(K, R, C) ? "GABRIEL" : "RICHARD");
  }
  return 0;
}
