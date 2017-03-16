#include<stdio.h>
#include<math.h>
long long gcd(long long a,long long b)
{
    if(a==0)
    return b;
    else
    return gcd(b%a,a);
}
main()
{
    int t;
    scanf("%d",&t);
    int j;

    for(j=1;j<=t;j++){
   long long int i,p,q,count=0;
 scanf("%lld/%lld",&p,&q);
 long long k=gcd(p,q);
 p=p/k;
 q=q/k;
 if((q&(q-1))==0)
 {
     double r=(double)q/p;
   count=ceil(log2(r));
printf("Case #%d: %llu\n",j,count);
 }
 else
 printf("Case #%d: impossible\n",j);
    }
 return 0;
}
