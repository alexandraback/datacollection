#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct pro
{
	ll num,cnt;
}g,g1;

ll mark[1000001],final[1000001];
ll i,j,ii,n,t,ans,rev,nu;


queue< pro > Q;


int main()
{

	memset(mark,0,sizeof(mark));
	mark[1]=1;

		g.num=1;
		g.cnt=1;
		Q.push(g);
		while(!Q.empty())
		{
			g=Q.front();
			Q.pop();
			final[g.num]=g.cnt;
			if(mark[g.num+1]==0 && g.num+1<=1000000)
			{
				mark[g.num+1]=1;
				g1.num=g.num+1;
				g1.cnt=g.cnt+1;
				Q.push(g1);
			}
			ll ans=0;
			nu = g.num;
	while(nu>0)
	{
		ll a=nu%10;
		ans=ans*10+a;
		nu=nu/10;
	}

			if(mark[ans]==0 && ans<=1000000)
			{
				mark[ans]=1;
				g1.num=ans;
				g1.cnt=g.cnt+1;
				Q.push(g1);

			}
		}
	scanf("%lld",&t);
	for(ii=1;ii<=t;ii++)
	{

		scanf("%lld",&n);


		printf("Case #%lld: %lld\n",ii,final[n]);
	}

}
