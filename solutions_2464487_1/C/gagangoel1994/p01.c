#include <stdio.h>
#define checking 1
long long int findcount(long long int r, long long int t);
int main()
{
  if(checking)
    {
      freopen("A-large.in","r",stdin);
      freopen("2.in","w",stdout);
    }
long long int T,r,t;
 long long int i,j,a,b,count,c;
  scanf("%lld",&T);
  for (i=0;i<T;i++)
    {
      scanf("%lld%lld",&r,&t);
      a=2*r;
      count=findcount(r,t);
      printf("Case #%lld: %lld\n",i+1,count);
    }
  return 0;
}
long long int findcount(long long int r, long long int t)
{
  int check=0;
  long long int count=500000000,c,d,a=2*r,e=250000000;
  if(a>2000000000) 
    {
      count=4000000000000000000/a;
      e=(count+1)/2;
    }
  else;

  while(check==0)
    {
      c=(a-1)*count+2*count*count;
      d=(a-1)*(count+1)+2*(count+1)*(count+1);
      if (t>=c && t<d)
	check=1;
      if (t>=d)
	count=count+e;
      if(t<c)
	count=count-e;
      e=(e+1)/2;
    }
  return count;
}

