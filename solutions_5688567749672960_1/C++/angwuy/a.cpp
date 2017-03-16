#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

const int MAXN = 2000000;

int f[MAXN];

long long c[20];
long long e[20];

long long inv(long long x)
{
   long long y = 0;
   while (x > 0)
   {
      y = y * 10 + x % 10;
      x /= 10;
   }
   return y;
}

int min(int x, int y){ return x < y ? x : y;}

long long solve(long long x)
{
   int w = -1;
   long long y = x;
   while (y > 0)
   {
      y /= 10;
      ++w;
   }
   if (x == e[w]) return c[w];
   long long ba = c[w];
   long long ans = ba + x - e[w];
   --x;
   long long tmp = ba + x % e[(w+1) / 2] + inv(x) % e[w+1-(w+1)/2]+1;
   if (tmp < ans) ans = tmp;
   tmp = ba + inv(x) % e[(w+1) / 2] + x % e[w+1-(w+1)/2]+1;
   if (tmp < ans) ans = tmp;
   return ans;
}


int main()
{
   memset(f, 0x7f, sizeof(f));
   f[1] = 1;
   for (int i = 1; i < MAXN; ++i)
   {
      if (f[i + 1] > f[i]) f[i + 1] = f[i] + 1;
      int j = inv(i);
      if (j < MAXN && f[j] > f[i])
         f[j] = f[i] + 1;
   }

   c[0] = 1;
   e[0] = 1;
   c[1] = 10;
   e[1] = 10;
   for (int i = 2; i < 20; ++i)
   {
      e[i] = e[i - 1] * 10;
      c[i] = c[i-1] + e[(i+1) / 2] + e[i-(i+1)/2]-1;
   }
   for (int i = 1; i < MAXN; ++i)
   if (f[i] != solve(i))
   {
      printf("%d: %d, %I64d\n", i, f[i], solve(i));
      break;
   }
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii)
   {
      long long x;
      scanf("%I64d\n", &x);
      printf("Case #%d: %I64d\n", ii, solve(x));
   }
   return 0;
}
