#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 1234567, MaxC = 0x3f3f3f3f;

int dp[MaxN];

int rev (int i)
{
  int ret = 0;
  while (i > 0)
  {
    ret = ret * 10 + i % 10;
    i /= 10;
  }
  return ret;
}
              
int main (void)
{
  int i, test, tests;
  memset (dp, MaxC, sizeof dp);
  dp[1] = 1;
  for (i = 1; i < MaxN; i++)
  {
    dp[i+1] = min (dp[i+1], dp[i] + 1);
    if (rev (i) < MaxN)
      dp[rev(i)] = min (dp[rev(i)], dp[i] + 1);
  }
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int n;
    scanf ("%d", &n);

    printf ("Case #%d: %d\n", test + 1, dp[n]);
  }
  return 0;
}
