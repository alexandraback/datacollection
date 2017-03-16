#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXN = 1010;

int n;
int a[MAXN], b[MAXN];
int chk[MAXN];

void init()
{
   scanf("%d", &n);
   for (int i = 1; i <= n; ++i)
      scanf("%d %d", &a[i], &b[i]);
}

void solve()
{
   memset(chk, 0, sizeof(chk));
   int ans = 0;
   int i, j, k, t;
   t = 0;
   while (t < n * 2)
   {
      for (i = 1; i <= n; ++i)
      if (chk[i] < 2 && b[i] <= t) break;
      if (i <= n)
      {
         t += 2 - chk[i];
         chk[i] = 2;
         ++ans;
         continue;
      }
      j = -1;
      k = -1;
      for (i = 1; i <= n; ++i)
      if (chk[i] < 1 && a[i] <= t && b[i] > k)
      {
         k = b[i];
         j = i;
      }
      if (j != -1)
      {
         t += 1 - chk[j];
         chk[j] = 1;
         ++ans;
         continue;
      }
      printf("Too Bad\n");
      return;
   }
   printf("%d\n", ans);
}

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
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
