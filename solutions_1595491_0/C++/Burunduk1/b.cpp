/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2012.04.14
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int N, S, p;

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
  {
    printf("Case #%d: ", t + 1);

    int N, S, p, res = 0, a;
    scanf("%d%d%d", &N, &S, &p);
    forn(i, N)
    {
      scanf("%d", &a);
      if ((a + 2) / 3 >= p)
        res++;
      else if (a > 1)
      {
        // x
        // x .. x+2
        // x+2
        // 3x + 2..4 = y
        int x = (a - 2) / 3;
        if (x + 2 >= p && S)
          S--, res++;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
