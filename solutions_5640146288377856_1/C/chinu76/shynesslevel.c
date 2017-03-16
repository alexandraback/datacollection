#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main()
{
    FILE *fpt;
    fpt=fopen("out.txt","w");
    long long int i,j,k,t,n,s,x,count=0,count2=0,r,c,w;
    scanf("%lld",&t);
   for(x=0;x<t;x++)
   {
   scanf("%lld %lld %lld",&r,&c,&w);
   s=c/w;
   if(c%w!=0)
   count2=s*r+w;
   else
    count2=s*r+w-1;
   printf("Case #%lld: %lld\n",x+1,count2);
    fprintf(fpt,"Case #%lld: %lld\n",x+1,count2);
    count=0;count2=0;
   }
   return 0;
}
