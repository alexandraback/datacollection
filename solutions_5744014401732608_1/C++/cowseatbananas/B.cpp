#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define REP(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;

int T, B, G[50][50];
long long M;

int main() {
  scanf("%d", &T);
  REP (tc, T) {
    scanf("%d%lld", &B, &M);

    long long mx = 1;
    REP (i, B - 2) mx *= 2;
    if (M > mx) printf("Case #%d: IMPOSSIBLE\n", tc);
    else {
      printf("Case #%d: POSSIBLE\n", tc);

      memset(G, 0, sizeof G);
      if (M == 1) {
        G[0][B - 1] = 1;
      } else if (M == 2) {
        G[0][B - 1] = 1;
        G[0][1] = G[1][B - 1] = 1;
      } else {
        G[0][1] = 1;
        long long mx = 2;
        int nn = 2;
        while (M > mx) {
          FOR (i, nn) G[i][nn] = 1;
          ++nn;
          mx *= 2;
        }
        if (M == mx) {
          FOR (i, nn) G[i][B - 1] = 1;
        } else {
          assert(nn <= B - 1);
          for (int i = 0; (1LL << i) < M; ++i) {
            if ((M >> i) & 1)
              G[i + 1][B - 1] = 1;
          }
        }
      }

      long long dp[B];
      FOR (i, B) {
        dp[i] = 0;
        if (!i) dp[i] = 1;
        else {
          FOR (j, i) if (G[j][i])
            dp[i] += dp[j];
        }
      }
      assert(dp[B - 1] == M);

      FOR (i, B) {
        FOR (j, B) printf("%d", G[i][j]);
        printf("\n");
      }
    }
  }
  return 0;
}
