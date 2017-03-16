#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

long long gcd (long long a, long long b)
{
  return b == 0? a : gcd (b,  a % b);
}

int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    long long p, q, g;
    scanf ("%I64d/%I64d", &p, &q);

    g = gcd (p, q);
    q /= g;
    p /= g;
    int res1 = -1;
    for (int i = 0; i <= 40; i++)
      if ((1ll << i) == q)
      {
        res1 = i;
        break;
      }
    if (res1 != -1)
    {
      int res = -1;
      for (int i = 0; i <= 40; i++)
        if (p * (1ll << i) >= q)
        {
          res = i;
          break;
        }
      printf ("Case #%d: %d\n", test + 1, res);
    }
    else
      printf ("Case #%d: impossible\n", test + 1);
    
  }
  return 0;
}
