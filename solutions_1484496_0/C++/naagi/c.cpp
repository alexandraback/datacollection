//dp[s] - number of ways to get sum = s. if dp[s] >= 2 
//then it is possible to find
//two distinct subsets with this sum
//We need the smallest of these sums.

//for large tests it should always be possible...

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
const int Max = 20 * 111111;
long long a[555], res1[555], res2[555];
int u[555];

int dp[Max + 10];
              
int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {                                         
    int i, j, n, res;
    printf ("Case #%d:\n", test + 1);
    scanf ("%d", &n);
    for (i = 0 ;i < n; i++)
      scanf ("%I64d", &a[i]);
    sort (a, a + n);
    for (i = 0 ;i < n; i++)
      u[i] = 1;
    memset (dp, 0, sizeof(dp));
    dp[0] = 1;
    for (i = 0; i < n; i++)
      for (j = Max; j > 0; j--)
        if ((j - a[i] >= 0))
          dp[j] = min (1000, dp[j] + dp[j - a[i]]);

    for (i = 0; i < Max; i++)
      if (dp[i] == 2)
        break;
    if (i == Max)
    {
      printf ("Impossible\n");
      continue;  
    }
    res = i;
    int k, l;
    k = l = 0;
    i = res;
    while (i > 0)
    {
      for (j = 0; j < n; j++)
       if (u[j] == 1 && i - a[j] >= 0 && dp[i - a[j]] > 0)
       {
          u[j] = 0;
          res1[k++] = a[j]; 
          dp[i] --;
          i -= a[j];
          break;
       }  
    }

    i = res;
    while (i > 0)
    {
      for (j = 0; j < n; j++)
       if (u[j] == 1 && i - a[j] >= 0 && dp[i - a[j]] > 0)
       {
          u[j] = 0;
          res2[l++] = a[j]; 
          dp[i] --;
          i -= a[j];
          break;
       }  
    }

    for (i = 0; i < k; i++)
      printf ("%I64d%c", res1[i], (i ==k-1)? '\n' : ' ');
    for (i = 0; i < l; i++)
      printf ("%I64d%c", res2[i], (i ==l-1)? '\n' : ' ');
    
  }
  return 0;
}
