#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
              
int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int s[222], i, n, k = 0;
    double res[222], sum = 0, sum2 = 0;
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
    {
      scanf ("%d", &s[i]);
      sum += s[i];
    }
    for (i = 0; i < n; i++)
    {
      if (s[i] * n >= sum * 2)
        res[i] = 0;
      else
      {
        res[i] = -1;
        k++;
        sum2 += s[i];
      }
    }
    for (i = 0; i < n; i++)
    {
      if (res[i])
        res[i] = 100.0 / k * (sum2/sum + 1) - 100.0 * s[i]/sum;
    }
    printf ("Case #%d: ", test + 1);
    for (i = 0; i < n; i++)
      printf ("%.7lf%c", res[i], (i == n-1)? '\n' : ' ');
    
  }
  return 0;
}
