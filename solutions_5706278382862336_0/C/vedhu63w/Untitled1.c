#include<stdio.h>
#include<math.h>
main()
{
    int t,j;
    scanf("%d",&t);
    for(j=1;j<=t;j++){
   long long int i,p,q,count=0;
 scanf("%lld/%lld",&p,&q);
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
