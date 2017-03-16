#include <cstdio>
#include <cstring>

const int MAXN = 10000000;

int next[MAXN];
int count[MAXN];

void deal(int x)
{
   int t = 1, y = x;
   while (t * 10 <= x) t *= 10;
   while (next[y] != x)
   {
      if (y >= t) next[y] = x;
      y = t * (y % 10) + y / 10;
   }
}

bool circle(int p)
{
   int x = p;
   while (1)
   {
      if (next[x] == x) return false;
      if (next[x] == p) return true;
      x = next[x];
   }
}

int getnext(int p){ return next[p] == p ? p : next[p] = getnext(p);}

void prework()
{
   memset(next, 0xff, sizeof(next));
   int i;
   next[0] = 0;
   for (i = 1; i < MAXN; ++i)
   if (next[i] == -1)
      deal(i);
}

void solve()
{
   long long ans = 0;
   int l, r, i;
   scanf("%d %d", &l, &r);
   memset(count, 0, sizeof(count));
   for (i = l; i <= r; ++i)
   {
      ans -= (count[next[i]] * (count[next[i]] - 1) / 2);
      ++count[next[i]];
      ans += (count[next[i]] * (count[next[i]] - 1) / 2);
   }
   ans = 0;
   for (i = 0; i < MAXN; ++i)
      if (count[i] > 1)
      {
         ans += (count[next[i]] * (count[next[i]] - 1) / 2);
      }
   printf("%I64d\n", ans);
   fflush(stdout);
}


int main()
{
   prework();
   int ii, tt;
   scanf("%d", &tt);
   for (ii = 1; ii <= tt; ++ii)
   {
      printf("Case #%d: ", ii);
      solve();
   }
   return 0;
}