#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 1234;

char s[MaxN];
              
int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, n, res = 0, cur = 0;
    scanf ("%d %s", &n, s);
    for (i = 0; i <= n; i++)
    {
      if (cur < i && s[i] != '0')
      {
        res += i - cur;
        cur = i;
      }
      cur += s[i] - '0';
    }
    printf ("Case #%d: %d\n", test + 1, res);
  }
  return 0;
}
