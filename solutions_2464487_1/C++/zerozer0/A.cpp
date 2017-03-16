#include <stdio.h>
int main()
{
	int T,test=0;
	long long t,r,ans,low,mid,high,tmp;
//	freopen("A-large.in","r",stdin);
//	freopen("Al.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&r,&t);
		high=1000000000;
		low=0;
		while(low<high)
		{
			mid=(low+high)>>1;
			if(mid==0)
			{
				high=1;
				break;
			}
			tmp=t/mid;
			if(tmp>2*(mid+r)-1)
				low=mid+1;
			else
				high=mid;
		}
		tmp=t/high;
		if(tmp>=2*(high+r)-1)
			ans=high;
		else
			ans=high-1;
		printf("Case #%d: %lld\n",++test,ans);
	}

	return 0;
}