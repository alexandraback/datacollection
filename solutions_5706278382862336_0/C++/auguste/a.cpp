#include <cstdio>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b)
{
   return b == 0 ? a : gcd(b, a%b);
}

int lg(long long q)
{
   int n = 0;
   while(q%2 == 0) {
      q /= 2;
      n++;
   }
   return q == 1 ? n : -1;
}

int lp(long long q)
{
   int n = 0;
   while(q > 0) {
      q /= 2;
      n++;
   }
   return  n;
}

int main()
{
   int nbTests;
   scanf("%d", &nbTests);
   for(int iTest = 1 ; iTest <= nbTests; iTest++)
   {
      long long p, q;
      scanf("%lld", &p);
      getchar();
      scanf("%lld", &q);

      long long d = gcd(q, p);
      p /= d;
      q /= d;

      printf("Case #%d: ", iTest);
      int l = lg(q);
      if(l == -1)
         printf("impossible\n");
      else
      {
         int f = lp(p);
         printf("%d\n", l - f + 1);
      }
   }
   return 0;
}
