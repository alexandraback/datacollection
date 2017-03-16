#include <cstdio>
#include <cstring>

const int MAXN = 50;

int n, s, t;
int p[MAXN];
int np[MAXN];
int a[MAXN];
int f[MAXN][MAXN];

int max(int a, int b){ return a > b ? a : b;}

void init()
{
   memset(p, 0xff, sizeof(p));
   memset(np, 0xff, sizeof(np));
   int i;
   for (i = 0; i <= 10; ++i)
      np[i * 3] = i;
   for (i = 0; i <= 9; ++i)
   {
      np[i * 3 + 1] = max(np[i * 3 + 1], i + 1);
      np[i * 3 + 2] = max(np[i * 3 + 1], i + 1);
   }
   for (i = 0; i <= 8; ++i)
   {
      p[i * 3 + 2] = max(p[i * 3 + 2], i + 2);
      p[i * 3 + 3] = max(p[i * 3 + 3], i + 2);
      p[i * 3 + 4] = max(p[i * 3 + 4], i + 2);
   }
   
}

void solve()
{
   int i, j;
   scanf("%d %d %d", &n, &s, &t);
   for (i = 1; i <= n; ++i)
      scanf("%d", &a[i]);
   memset(f, 0xff, sizeof(f));
   f[0][0] = 0;
   for (i = 0; i < n; ++i)
   for (j = 0; j <= s; ++j)
   if (f[i][j] >= 0)
   {
      if (p[a[i + 1]] >= t) f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j] + 1);
      else f[i + 1][j + 1] = max(f[i + 1][j + 1], f[i][j]);
      if (np[a[i + 1]] >= t) f[i + 1][j] = max(f[i + 1][j], f[i][j] + 1);
      else f[i + 1][j] = max(f[i + 1][j], f[i][j]);
   }
   printf("%d\n", f[n][s]);
}

int main()
{
   init();
   int tt, ii;
   scanf("%d", &tt);
   for (ii = 1; ii <= tt; ++ii)
   {
      printf("Case #%d: ", ii);
      solve();
   }
   return 0;
}