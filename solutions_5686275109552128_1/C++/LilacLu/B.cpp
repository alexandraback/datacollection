#include <cstdio>
#include <cstring>

//#define small
#define large

int t, d;
int x[1005], dp[1005][1005];

int main()
{
#ifdef small
  freopen("small.in", "r", stdin);
  freopen("small.out", "w", stdout);
#endif
#ifdef large
  freopen("large.in", "r", stdin);
  freopen("large.out", "w", stdout);
#endif
  scanf("%d", &t);
  for (int Case = 1; Case <= t; ++Case) {
    scanf("%d", &d);
    int maxNum = 0;
    for (int i = 1; i <= d; ++i)
      scanf("%d", &x[i]), maxNum = maxNum > x[i] ? maxNum : x[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= d; ++i)
      for (int j = 1; j <= maxNum; ++j)
        dp[i][j] = dp[i - 1][j] + x[i] / j - (x[i] % j == 0);
    int ans = 0x7f7f7f7f;
    for (int i = 1; i <= maxNum; ++i)
      if (dp[d][i] + i < ans)
        ans = dp[d][i] + i;
    printf("Case #%d: %d\n", Case, ans);
  }
  return 0;
}
