#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, K, C, S;

int main() {
  scanf("%d", &T);
  REP (tc, T) {
    scanf("%d%d%d", &K, &C, &S);
    if (S * C < K) printf("Case #%d: IMPOSSIBLE\n", tc);
    else {
      long long p = K;
      printf("Case #%d:", tc);
      while (p) {
        long long pos = 0;
        FOR (i, C) {
          if (--p < 0) p = 0;
          pos = pos * K + p;
        }
        printf(" %lld", pos + 1);
      }
      printf("\n");
    }
  }
  return 0;
}
