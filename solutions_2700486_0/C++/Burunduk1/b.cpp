/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2013.05.04
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

typedef long double dbl;

dbl C( int n, int k )
{
  dbl r = 1;
  forn(i, k)
    r *= n - i, r /= i + 1;
  return r;
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(tt, tn)
  {
    printf("Case #%d: ", tt + 1);

    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);

    int l = abs(x) + y;
    for (int s = 0; s < l; s += 2)
      n -= 2 * s + 1;
    if (n <= 0)
      puts("0.0");
    else if (n >= 2 * l + 1)
      puts("1.0");
    else if (x == 0)
      puts("0.0");
    else 
    {
      y = y + 1;
      //printf("n = %d, l = %d, y = %d : ", n, l, y);
      if (n >= l + y)
        puts("1.0");
      else
      {
        dbl a = 0, b = 0;
        forn(i, 1 << n)
        {
          int left = 0, right = 0;
          forn(j, n)
            if ((i >> j) & 1)
              left++;
            else
              right++;
          if (right >= y)
            a += 1;
          b += 1;
        }
/*
        forn(t, n + 1)
        {
          dbl num = C(n, t);
          //printf("%d * %.2f : ", t >= y, (double)num);
          a += (t >= y) * num;
          b += num;
        }
*/
        printf("%.20f\n", (double)(a / b));
      }
    }
  }
  return 0;
}
