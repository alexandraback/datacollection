#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int main()
{
    FILE *fpt;
    fpt=fopen("out.txt","w");
    long long int i,j,k,t,n,s,x,count=0,count2=0,r,c,w,d,v,l;
   double  a1=1,a2=1,a3=1,max;

    scanf("%lld",&t);
   for(x=0;x<t;x++)
   {
   scanf("%lld %lld %lld",&k,&l,&s);
 char a[k];
 char b[l];
 scanf("%s",a);
 scanf("%s",b);

max=floor(s/l);

for(i=0;i<l;i++)
{
  for(j=0;j<k;j++)
  {
      if(b[i]==a[j])
        count++;
  }
  a1=(double)count/(double)k;
  count=0;
  a2=a2*a1;
  if(a2==0)
    break;
}
if( a2==0)
{
     printf("Case #%lld: 0.0\n",x+1);
    fprintf(fpt,"Case #%lld: 0.0\n",x+1);
}

else if(a2<0.0000001 && a2>0)
{
     printf("Case #%lld: %0.1lf\n",x+1,max);
    fprintf(fpt,"Case #%lld: %0.1lf\n",x+1,max);
}
else
{
     printf("Case #%lld: %0.7lf\n",x+1,max-max*a2);
    fprintf(fpt,"Case #%lld: %0.7lf\n",x+1,max-max*a2);

}

 a1=1,a2=1;
    count=0;count2=0;
   }
   return 0;
}

