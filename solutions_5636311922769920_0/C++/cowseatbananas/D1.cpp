#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, K, C, S;

int main() {
  scanf("%d", &T);
  REP (tc, T) {
    scanf("%d%d%d", &K, &C, &S);
    assert(S == K);
    printf("Case #%d:", tc);
    REP (i, K) printf(" %d", i);
    printf("\n");
  }
  return 0;
}
