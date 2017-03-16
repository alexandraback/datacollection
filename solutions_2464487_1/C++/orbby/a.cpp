 //FUCK

#include<stdio.h>
#include<math.h>
long long a,s;

long long search(long long l,long long r)
{
	if(l==r)
	{
		return l;
	}
	long long mid=(l+r+1)/2;
	long long ans=2*mid*mid;
	ans=ans-s;
	ans=ans+(2+a)*mid;
	ans=ans+a;
	if(ans==0)
	{
		return mid;
	}
	if(ans>0)
	{
		return search(l,mid-1);
	}
	return search(mid,r);
}

int main()
{

	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;tt++)
	{
		long long r;
		scanf("%lld %lld",&r,&s);
		a=2*r+1;
		long long right=(long long)sqrt((double)s/2.0);
		long long right2=s/(2+a)+1;
		if(right2<right)
		{
			right=right2;
		}
		long long ret=search(0,right);
		ret++;
		printf("Case #%d: %lld\n",tt+1,ret);
	}
}
