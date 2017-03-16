#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

void solve() {
  int energy, recovery, n;
  int v[15] = {};

  scanf("%d %d %d", &energy, &recovery, &n);
  for (int i = 0; i < n; i++)
    scanf("%d ", &v[i]);

  int dp[15][15] = {{}};

  for (int i = 0; i <= n; i++) {
    for (int e = 0; e <= energy; e++) {
      for (int spend = 0; spend <= e; spend++) {
        int newe = min(energy, e - spend + recovery);
        dp[i+1][newe] = max(dp[i+1][newe], dp[i][e] + v[i] * spend);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= energy; i++)
    ans = max(ans, dp[n][i]);
  printf("%d\n", ans);
}

int main() {
  int n;
  scanf("%d\n", &n);

  for (int cnum = 1; cnum <= n; cnum++) {
    printf("Case #%d: ", cnum);
    solve();
  }

  return 0;
}
