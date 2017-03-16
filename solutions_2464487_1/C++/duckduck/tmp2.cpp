#include <stdio.h>
#include <math.h>

int t,tt,i,j,k,n;
long long st,sum,l,r,m,tmp;

bool check()
{
	tmp=sum+m;
	if ((tmp/st)<(2*m))
		return false;
	tmp-=2*st*m;
	if ((tmp/m)<m)
		return false;
	return true;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++)
	{
		scanf("%lld%lld",&st,&sum);
		sum=sum*2;
		l=1;
		r=sum;
		while (l<=r)
		{
			m=(l+r)/2;
			if (check())
				l=m+1;
			else
				r=m-1;
		}
		printf("Case #%d: %lld\n",tt,(l-1)/2);
	}
	return 0;
}




