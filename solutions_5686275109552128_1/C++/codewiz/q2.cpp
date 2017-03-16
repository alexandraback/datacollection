#include<stdio.h>
#include"iostream"
using namespace std;
int main()
{
  int t,i,j,sum,ans,p,d,ar[1003];
  scanf("%d",&t);
  for(j=1;j<=t;j++)
    {
      scanf("%d",&d);
      for(i=0;i<d;i++)
	scanf("%d",&ar[i]);
      ans=1000000000;
      for(p=1;p<=1000;p++)
	{
	  sum=p;
	  for(i=0;i<d;i++)
	    {
	      sum+=ar[i]/p;
	      if(ar[i]%p==0)
		sum--;
	    }
	  if(ans>sum)
	    ans=sum;
	}
      printf("Case #%d: %d\n",j,ans);
    }
  return 0;
}
