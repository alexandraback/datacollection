#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
#define Nx 1000000

long long int p,q,ans,r,bin;
int t,tc;

long long fpb(long long a, long long b)
{
	if(a>b)
		return fpb(b,a);
	if(a==0)
		return b;
	else
		return fpb(b % a, a);
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	tc = 0;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",++tc);
		scanf("%lld/%lld",&p,&q);
		ans = 0;
		r = fpb(p,q);
		p /= r;
		q /= r;
		bin = 1; 
		while(bin < q)
		{ 
			bin*=2;
		}
		if(bin % q)
			printf("impossible\n");
		else
		{
			while(bin>p)
			{
				bin /= 2;
				ans++;
			}
			if (ans<41)
				printf("%lld\n",ans);
			else
				printf("impossible\n");
		}
	}
	return 0;
}
 
