#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 100010;

int n, m;
double a[MAXN];

inline double min(double a, double b){ return a < b ? a : b;}

void init()
{
   scanf("%d %d", &n, &m);
   a[0] = 1;
   for (int i = 1; i <= n; ++i)
   {
      scanf("%lf", &a[i]);
      a[i] *= a[i - 1];
   }
}

void solve()
{
   double ans = m + 2;
   for (int i = 0; i <= n; ++i)
      ans = min(ans, a[i] * (n - i + m - i + 1) + 
         (1 - a[i]) * (n - i + m - i + 1 + m + 1));
   printf("%.6f\n", ans);
}

int main()
{
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii)
   {
      printf("Case #%d: ", ii);
      init();
      solve();
   }
   return 0;
}