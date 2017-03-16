#include <stdio.h>
#include <math.h>

int main()
{
	int i,tot;
	long long start,stop,mid,last;
	long long r,t,result;
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	scanf("%d",&tot);
	for (i=1; i<=tot; ++i)
	{
		scanf("%lld%lld",&r,&t);
		result=0;
		start=1;
		stop=sqrt(t+0.0)+1;
		while (start<=stop)
		{
			mid=(start+stop)/2;
			last=2*r+1+(mid-1)*4;
			if (2*r+1+last<=2*t/mid)
			{
				result=mid;
				start=mid+1;
			}
			else stop=mid-1;
		}
		printf("Case #%d: %lld\n",i, result);
	}
	return 0;
}