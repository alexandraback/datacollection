#include <stdio.h>
#include <stdlib.h>
int t;
int n;
double A[1001];
double sums;
inline bool chk(int a,double b)
{
double nows;
double uses=0;
double canuses;
 nows=A[a]+(b*sums);
 for(int i=1;i<=n;i++)
 {
  if(i!=a)
  {
   if(A[i]<nows){uses=uses+(nows-A[i]);}
  }
 }
 canuses=(1-b);
 canuses=canuses*sums;
 if(canuses>uses){return false;}
 else{return true;}
}
inline double search(int a)
{
double l=0,r=1,mids;
double mul1=1e+15;
double mul2=1e+18;
double ans=1;
 while(r-l>=(1/mul1))
 {
  mids=(l+r)/2;
  if(chk(a,mids)==true){ans=mids;r=mids-(1/mul2);}
  else{l=mids+(1/mul2);}
 }
 return ans*100;
}
main()
{
 freopen("A-small-attempt0.in","r",stdin);
 freopen("A-small-attempt0.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
 scanf("%d",&n);
  sums=0;
  for(int i=1;i<=n;i++)
  {
   scanf("%lf",&A[i]);
   sums=sums+A[i];
  }
  printf("Case #%d:",tests);
  for(int i=1;i<=n;i++)
  {
   printf(" %.12lf",search(i));
  }
  printf("\n");
 }
 return 0;
}
