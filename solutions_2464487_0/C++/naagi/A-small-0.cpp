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
    long long res = 0, r, t;
    long long le, ri, me;
    scanf ("%I64d %I64d", &r, &t);
    le = 1, ri = 1e9;
    while (le + 1 < ri)
    {
      me = (le + ri) / 2;
      if ((long double) me * (2 * r + 2 * me  - 1) <= t)
        le = me;
      else
        ri = me;        
    }
    res = le;
    printf ("Case #%d: %I64d\n", test + 1, res);
    
  }
  return 0;
}
