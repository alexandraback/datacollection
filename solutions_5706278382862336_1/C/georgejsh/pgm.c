#include<stdio.h>
#define MAX 1000000007
long long int gcd(long long int a,long long int b)
{
 if(a<b)
  return gcd(b,a);
 if(a%b==0)
  return b;
 else
  return gcd(b,a%b);
}
int check(long long int p)
{
 int i=0;
 while(p%2!=1)
 {
  i++;
  p=p/2;
 }
 if(p/2!=0)
  return -1;
 else 
 return i;
}
int check1(long long int p)
{
 int i=0;
 while(p)
 {
  i++;
  p=p/2;
 }
 return i;
}
int main()
{
 int t;
 long long int p,q,r;
 int i,j,k;
 for(scanf("%d",&t),j=0;j<t;j++)
 {
  printf("Case #%d: ",j+1);
  scanf("%lld/%lld",&p,&q);
  //printf("%lld %lld",p,q);
  r=gcd(p,q);
 // printf("%lld ",r);
  q=q/r;
  p=p/r;
  i=check(q);
  k=check1(p);
 // printf("%d %d\n",i,k);
  if(i!=-1)
  {
    printf("%d\n",i-k+1);
  }
  else
   printf("impossible\n");
 }
 return 0;
}