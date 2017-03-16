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

int N;
char s[1010];

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    scanf("%d%s", &N, s); ++N;

    int ans = 0;
    int stand = 0;
    REP(i, N) {
      int c = s[i] - '0';
      if (c == 0) continue;

      if (stand < i) {
        ans += i - stand;
        stand = i;
      }
      stand += c;
    }

    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
