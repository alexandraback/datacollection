#include<cstdio>
#include<cstring>

const int MAXN = 1100;

int n;
bool a[MAXN][MAXN];
bool chk[MAXN];
int d[MAXN];

bool dfs(int p, int f)
{
//printf("%d: %d\n", p, f);
   if (chk[p]) return false;
   chk[p] = true;
   for (int i = 1; i <= n; ++i)
   if (a[p][i] && f != i)
      if (!dfs(i, p)) return false;
   return true;
}
bool solve()
{
   scanf("%d", &n);
   memset(a, 0, sizeof(a));
   memset(d, 0, sizeof(d));
   int i, j, s, t;
   for (s = 1; s <= n; ++s)
   {
      scanf("%d", &j);
      while (j--)
      {
         scanf("%d", &t);
         if (a[s][t]) return false;
         a[s][t] = true;
         ++d[t];
      }
   }
   for (i = 1; i <= n; ++i)
   if (d[i] == 0)
   {
   memset(chk, 0, sizeof(chk));
   if (!dfs(i, -1)) return false;
   }
   return true;
}

int main()
{
   freopen("A.in", "r", stdin);
   freopen("A.out", "w", stdout);
   int ii, tt;
   scanf("%d", &tt);
   for (ii = 1; ii <= tt; ++ii)
   {
      if (!solve()) printf("Case #%d: Yes\n", ii);
      else printf("Case #%d: No\n", ii);
   }
   return 0;
}
