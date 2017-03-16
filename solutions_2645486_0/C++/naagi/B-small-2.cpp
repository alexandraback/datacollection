#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int dp [12][12];

int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int res = 0, e, r, n, i, j, k;
    int v[12];
    scanf ("%d %d %d", &e, &r, &n);
    for (i = 1; i <= n; i++)
      scanf ("%d", &v[i]);
    memset (dp, 0, sizeof(dp));
    for (i = 0; i < n; i++)
    {
      for (j = 0; j <= e; j++)
        for (k = 0; k <= j; k++)
         if (dp[i + 1][min(j - k + r, e)] < dp[i][j] + v[i+1] * k)
           dp[i + 1][min(j - k + r, e)] = dp[i][j] + v[i+1] * k;
    }

    for (i = 0; i <= e; i++)
      if (res < dp[n][i])
        res = dp[n][i];
    printf ("Case #%d: %d\n", test + 1, res);
    
  }
  return 0;
}
