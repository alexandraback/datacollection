#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long double LD;

typedef struct Tnum{
   LD d;
   int e;
   
   Tnum(){}
   
   Tnum(LD a)
   {
      d = a;
      e = 0;
   }
};

void adjust(Tnum &a){
   while (a.d > -1 && a.d < 1)
   {
      a.d *= 10;
      --a.e;
   }
   while (a.d >= 10 || a.d <= -10)
   {
      a.d /= 10;
      ++a.e;
   }
}

Tnum operator +(Tnum a, Tnum b)
{
   Tnum c;
   if (a.e < b.e)
   {
      c = a;
      a = b;
      b = c;
   }
   while (b.e < a.e)
   {
      ++b.e;
      b.d /= 10;
   }
   c = a;
   c.d += b.d;
   adjust(c);
   return c;
}

Tnum operator -(Tnum a, Tnum b)
{
   Tnum c;
   if (a.e < b.e)
   {
      c = a;
      a = b;
      b = c;
   }
   while (b.e < a.e)
   {
      ++b.e;
      b.d /= 10;
   }
   c = a;
   c.d -= b.d;
   adjust(c);
   return c;
}

Tnum operator *(Tnum a, Tnum b)
{
   Tnum c;
   c.d = a.d * b.d;
   c.e = a.e + b.e;
   adjust(c);
   return c;
}

Tnum operator /(Tnum a, Tnum b)
{
   Tnum c;
   c.d = a.d / b.d;
   c.e = a.e - b.e;
   adjust(c);
   return c;
}

LD get(Tnum a)
{
   while (a.e < 0)
   {
      ++a.e;
      a.d /= 10;
   }
   while (a.e > 0)
   {
      --a.e;
      a.d *= 10;
   }
   return a.d;
}

Tnum a[200][200];

LD solve()
{
   int n, x, y;
   cin >> n >> x >> y;
   int t = 0;
   int N = (abs(x) + y);
   for (int i = 0; i < N / 2; ++i)
      t += 4 * i + 1;
   if (n <= t) return (LD)0;
   n -= t;
   if (n >= 2 * N + 1) return (LD)1;
   int K = n;
   int M = y + 1;
   if (K < M) return (LD)0;
   for (int i = 0; i <= N; ++i)
   for (int j = 0; j <= N; ++j)
      a[i][j] = Tnum(0);
   a[0][0] = Tnum(1);
   //cout << N << M << K << endl;
   for (int i = 0; i <= N; ++i)
   for (int j = 0; j <= N; ++j)
   {
      if (i < N && j < N)
      {
         a[i + 1][j] = a[i + 1][j] + a[i][j] * Tnum(0.5);
         a[i][j + 1] = a[i][j + 1] + a[i][j] * Tnum(0.5);
      }
      else if (i < N)
      {
         a[i + 1][j] = a[i + 1][j] + a[i][j];
      }
      else
      {
         a[i][j + 1] = a[i][j + 1] + a[i][j];
      }
   }
   Tnum ans(0);
   for (int i = M; i <= N; ++i)
      ans = ans + a[i][K - i];
   return get(ans);
}

int main()
{
   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
   int t;
   cin >> t;
   for (int i = 1 ; i <= t; ++i)
   {
      cout << "Case #" << i << ": " << fixed << setprecision(8) << solve() << endl;
   }
   return 0;
}