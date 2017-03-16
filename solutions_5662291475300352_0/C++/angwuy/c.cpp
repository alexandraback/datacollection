#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

const int MAXN = 500010;
const double INF = 1E+8;

int n, h;
int p[MAXN];
int m[MAXN];

void init()
{
   scanf("%d", &n);
   h = 0;
   for (int i = 1; i <= n; ++i)
   {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      while (b--)
      {
         p[++h] = a;
         m[h] = c++;
      }
   }
}

int get(long double t)
{
   int ans = 0;
   for (int i = 1; i <= h; ++i)
   {
      if ((long double)t * 360 / m[i] < 720 - p[i]) continue;
      ans += int(((long double)t * 360 / m[i] - 720 + p[i]) / 360);
      if (ans > n) break;
   }
   return ans;
}

void solve()
{
   long double l, ml, mr, r;
   int a1, a2;
   l = 0, r = INF;
   while (r - l > (long double)(1E-12))
   {
      ml = l / 3 * 2 + r / 3;
      mr = l / 3 + r / 3 * 2;
      a1 = get(ml);
      a2 = get(mr);
      if (a1 < a2) r = mr;
      else l = ml;
   }
   printf("%d\n", a1);
}

bool equ(long double a, long double b)
{
   return (a < b + (long double)(1E-12)) && (a > b - (long double)(1E-12));
}

int solve1()
{
   long long ta1 = (long long)(360 - p[1]) * m[1];
   long long ta2 = ta1 + (long long)360 * m[1];
   long long tb1 = (long long)(360 - p[2]) * m[2];
   long long tb2 = tb1 + (long long)360 * m[2];
   if (ta1 >= tb2) return 1;
   if (tb1 >= ta2) return 1;
   return 0;
   
}

int main()
{
   int tt;
   scanf("%d", &tt);
   for (int ii = 1; ii <= tt; ++ii)
   {
      init();
      printf("Case #%d: %d\n", ii, solve1());
   }
   return 0;
}
