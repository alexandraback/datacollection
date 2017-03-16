#include<stdio.h>
long long int gcd(long long int a,long long int b) {
 if(b==0) return a;
  return gcd(b,a%b);
}
int main() {
 long long int t,T,p,q,i,g,ok;
 scanf("%lld",&T);
 for(t=1;t<=T;t++)
 {
  scanf("%lld/%lld",&p,&q);
   g=gcd(q,p);
    p/=g;
     q/=g;
     ok=1;
     for(i=q;i>1;i/=2)
        if(i%2) {
            ok=0;
            break;
        }
      for(i=1;ok&&(double)p/q<0.5;i++,q/=2);
      if(ok) printf("Case #%lld: %lld\n",t,i);
       else printf("Case #%lld: impossible\n",t);
   }
   return 0;
}
