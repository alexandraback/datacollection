#include <cstdio>
#include <algorithm>
using namespace std;

long long power(long long n, int p)
{
   long long t = 1;
   for(int i=0; i<p; i++)
      t *= n;
   return t;
}

long long steps[] = {0, 19, 199, 1099, 10999, 100999, 1009999, 10009999, 100099999, 1000099999, 10000999999, 100000999999, 1000009999999, 10000009999999};

long long rev(long long n)
{
   long long r = 0;
   while(n > 0)
   {
      r = r*10 + (n % 10);
      n /= 10;
   }
   return r;
}

long long calc(long long n)
{     
   int ndig = 0;
   long long m = n;
   long long tot = 0;
   while(m > 0)
   {
      m /= 10;
      ndig++;
   }
   for(int i=0; i<ndig-2; i++)
      tot += steps[i+1] - rev(steps[i]) + 1;
   tot += power(10, ndig-1) - rev(steps[ndig-2]);
  // printf("%lld\n", tot);
   
   long long add[2] = {0, 0};
   for(int k = 0; k <=1; k++)
   {
      long long half1 = n / power(10, (ndig+k)/2);
      long long half2 = n % power(10, (ndig+k)/2);

      if(half1 != power(10, (ndig+1-k)/2 - 1) && half1 != 0)
         add[k] +=  rev(half1);
      add[k] += half2;
   }
   tot += min(add[0], add[1]);

   if(n < 10) tot = n;
   return tot;
}

int main()
{
   int T;
   scanf("%d", &T);
   for(int _i=1; _i<=T; _i++)
   {
       long long n;
       scanf("%lld", &n);
       long long tot = calc(n);
       if(n % 10 == 0 && n > 10)
          tot = calc(n-1)+1;

       printf("Case #%d: %lld\n",_i, tot);
   }
   return 0;
}
