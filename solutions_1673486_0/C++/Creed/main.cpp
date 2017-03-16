#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int N = 1e5 + 10;
const double eps = 1e-9;
int t, x, y;
double p[N], f[N], sum[2][N], s[N];
double getsum(int l, int r)
{
  if (l > r) return 0.0;
  return s[r] - (l > 0 ? s[l - 1] : 0);
}
int main()
{
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("O.txt", "w", stdout);
  cin >> t;
  for(int q = 0; q < t; q++)
  {
    scanf("%d%d", &x, &y);
    for(int i = 0; i < x; i++)
    {
      scanf("%lf", &p[i]);
      sum[0][i] = (i == 0 ? p[i] : sum[0][i - 1] * p[i]);
    }
    for(int i = x - 1; i >= 0; i--)
      sum[1][i] = (i == x - 1 ? p[i] : sum[1][i + 1] * p[i]);
    f[0] = sum[1][0];
    for(int i = 0; i < x; i++)
      f[i + 1] = (i > 0 ? sum[0][i - 1] : 1.0) * (1.0 - p[i]);
    for(int i = 1; i <= x; i++)
      s[i - 1] = (i == 1 ? f[i] : s[i - 2] + f[i]);
    double ans = min(sum[1][0] * (y - x + 1) + (1.0 - sum[1][0]) * (2 * y - x + 2), (double)y + 2);
    for(int i = 0; i < x; i++)
    {
      double tmp = ((sum[1][0] + getsum(i, x - 1)) * (2 * (x - i) + y - x + 1) +
                    getsum(0, i - 1) * (2 * (x - i) + 2 * y - x + 2));
      ans = min(ans, tmp);
    }
    printf("Case #%d: %.7lf\n", q + 1, ans);
  }
  return 0;
}
