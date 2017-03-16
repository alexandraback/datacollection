/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.04.12
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void solve( int tn )
{
  double c, f, x, res = 1e100, cur = 0, dx = 2, tmp;
  scanf("%lf%lf%lf", &c, &f, &x);
  while ((tmp = cur + x / dx) < res)
    res = tmp, cur += c / dx, dx += f;
  printf("Case #%d: %.10f\n", tn, res);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
    solve(t + 1);
  return 0;
}
