#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int dp[20][10];
int v[20];

int main() {
  int T, E, R, n;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    scanf("%d%d%d",&E,&R,&n);
    memset(dp, -1, sizeof(dp));
    dp[0][E] = 0;
    for (int i = 0 ; i < n ; i++) {
      scanf("%d",&v[i]);
      for (int j = 0 ; j <= E ; ++j) {
        if (dp[i][j] < 0) continue;
        for (int k = 0 ; k <= j ; ++k) {
          int tj = j - k + R;
          if (tj >= E) tj = E;
          int earn = dp[i][j] + k * v[i];
          if (earn > dp[i+1][tj]) {
            dp[i+1][tj] = earn;
          }
        }
      }
    }
    int best = 0;
    for (int j = 0 ; j <= E ; ++j)
      if (dp[n][j] > best) best = dp[n][j];
    printf("Case #%d: %d\n", ca, best);
  }
  return 0;
}

