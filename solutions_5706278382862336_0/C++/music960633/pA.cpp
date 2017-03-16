#include <stdio.h>

long long gcd(long long a, long long b){
   while((a%=b)&&(b%=a));
   return a+b;
}

int lg(long long a){
   int ret = 0;
   while(a%2==0){
      ret++;
      a/=2;
   }
   if(a!=1) return -1;
   else return ret;
}

int main(){
   int T;
   long long a, b;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      scanf("%lld/%lld", &a, &b);
      long long g = gcd(a, b);
      a /= g;
      b /= g;
      int p = lg(b);
      if(p == -1){
         printf("Case #%d: impossible\n", t);
         continue;
      }
      int ans = 0;
      while((a&b)==0){
         ans++;
         b/=2;
      }
      printf("Case #%d: %d\n", t, ans);
   }
   return 0;
}
