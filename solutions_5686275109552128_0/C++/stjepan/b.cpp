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

const int MAX = 1010;

int N;
int a[MAX];

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    scanf("%d", &N);
    REP(i, N) scanf("%d", a+i);

    int ans = 1e9;
    FOR(s, 1, MAX) {
      int sum = s;
      REP(i, N) sum += (a[i] - 1) / s;
      ans = min(ans, sum);
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
