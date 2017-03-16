#include <stdio.h>

int T,ts;
long long a,b;

bool pal(long long x)
{
	long long y=0,z=x;
	while(x)
	{
		y=y*10+x%10;
		x/=10;
	}
	return z==y;
}

int f(long long x)
{
	int i,j,ans=0;
	long long p;
	for(i=0;;i++)
	{
		p=i;
		j=i/10;
		while(j)
		{
			p=p*10+j%10;
			j/=10;
		}
		if(p*p>x)
			break;
		p*=p;
		if(pal(p))
		{
			ans++;
			//printf("%lld\n",p);
		}
	}
	for(i=1;;i++)
	{
		p=i;
		j=i;
		while(j)
		{
			p=p*10+j%10;
			j/=10;
		}
		if(p*p>x)
			break;
		p*=p;
		if(pal(p))
		{
			ans++;
			//printf("%lld\n",p);
		}
	}
	return ans;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		printf("Case #%d: %d\n",++ts,f(b)-f(a-1));
	}
	return 0;
}
