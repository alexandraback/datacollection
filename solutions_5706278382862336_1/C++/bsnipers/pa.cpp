#include <stdio.h>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
	{
		return a;
	}else{
		return gcd(b,a%b);
	}
}


int main()
{
	int i1;
	int t;
	long long p,q,g;
	int ans;
	
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	
	scanf("%d",&t);
	for(i1=1; i1<=t; i1++)
	{
		scanf("%I64d/%I64d",&p,&q);
		ans=0; 
		g=gcd(p,q);
		p/=g;
		q/=g;
		g=q;
		while(g%2==0)
		{
			g/=2;
		}
		if(g!=1)
		{
			printf("Case #%d: impossible\n",i1);
			continue;
		}
		while(p<q/2)
		{
			ans++;
			q/=2;
		}
		printf("Case #%d: %d\n",i1,ans+1);
	}
	return 0;
}

