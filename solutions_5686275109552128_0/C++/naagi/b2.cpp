#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int MaxN = 1111;

int a[MaxN];

using namespace std;
              
int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, n, res, tres;
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
      scanf ("%d", &a[i]);
    res = MaxN;
    for (int mx = 1; mx < MaxN; mx++)
    {
      tres = mx;
      for (i = 0; i < n; i++)
        tres += (a[i]-1)/mx;
      if (res > tres)
        res = tres;
    }
    printf ("Case #%d: %d\n", test + 1, res);
  }
  return 0;
}
