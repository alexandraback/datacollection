#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 2222;

double t[MaxN], x[MaxN], a[MaxN];

int main (void)
{
  int test, tests;

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i;
    int n, m;
    double dist, res;
    scanf ("%lf %d %d", &dist, &n, &m);
    for (i = 0; i < n; i++)
      scanf ("%lf %lf", &t[i], &x[i]);
    for (i = 0; i < m; i++)
      scanf ("%lf", &a[i]);

    printf ("Case #%d:\n", test + 1);
    for (i = 0; i < m; i++)
    {
//      if (n == 1)
//    d = v_0*t + 0.5*a*t^2 = a t^2/2 
//    t^2 = 2d / a;
      res = sqrt (2 * dist/ a[i]);

//    t0 x0
//    t1 x1 >= D
//    td d
//    (t1 - td)/(t1 - t0) = (x1 - d)/(x1 - x0)
//    (t1 - td)*(x1 - x0) = (t1 - t0) * (x1 - d)
//     td = t1 - (t1 - t0) * (x1 - d)/(x1 - x0);
      if (n > 1 && x[0] < dist)    /* n = 2! */
        res = max (res, t[1] - (t[1] - t[0]) * (x[1] - dist)/(x[1] - x[0]));
      printf ("%.10lf\n", res);
    }
  }
  return 0;
}
