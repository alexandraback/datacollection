#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
struct pro
{
	ll num,cnt;
}g,g1;
ll func(ll num)
{
	ll ans=0;
	while(num>0)
	{
		ll a=num%10;
		ans=ans*10+a;
		num=num/10;
	}
	return ans;
}
ll reach[1000001],final[1000001];
int main()
{
	long long i,j,ii,n,t,ans,rev;
	queue<pro> myq;
	
	memset(reach,0,sizeof(reach));
		reach[1]=1;
		
		g.num=1;
		g.cnt=1;
		myq.push(g);
		while(!myq.empty())
		{
			g=myq.front();
			myq.pop();
			final[g.num]=g.cnt;
			if(reach[g.num+1]==0 && g.num+1<=1000000)
			{
				reach[g.num+1]=1;
				g1.num=g.num+1;
				g1.cnt=g.cnt+1;
				myq.push(g1);
			}
			rev=func(g.num);
			
			if(reach[rev]==0 && rev<=1000000)
			{
				reach[rev]=1;
				g1.num=rev;
				g1.cnt=g.cnt+1;
				myq.push(g1);
				
			}
		}
	scanf("%lld",&t);
	for(ii=1;ii<=t;ii++)
	{
		
		scanf("%lld",&n);
		
		
		printf("Case #%lld: %lld\n",ii,final[n]);
	}
	
}
