#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define PI 3.1415926535897932
#define inf 10000000000000
ll adj[100][100];
ll st[100];
ll near(ll num)
{
	ll i=1;
	while(i<=num)
	{
		i*=2;
	}
	i=i/2;
	return i;
}
int main()
{   
	ll t,y=0;
	scanf("%lld",&t);
	while(t--)
	{
		y++;
		ll b,m,i,j;
		memset(adj,0,sizeof(adj));
		scanf("%lld%lld",&b,&m);
		printf("Case #%lld: ",y);
		ll ans=pow(2,b-2);
		if(ans>=m)
		{
			printf("POSSIBLE\n");
			for(i=1;i<=b-1;i++)
			{
				for(j=1;j<=b;j++)
				{
					if(i<j)
					adj[i][j]=1;
				}
			}
			for(i=b-1;i>=2;i--)
			st[i]=pow(2,b-1-i);
			while(ans>m)
			{
				ll diff=ans-m;
				ll dd=near(diff);
				for(i=2;i<=b-1;i++)
				{
					if(st[i]==dd)
					break;
				}
				st[i]=0;
				adj[1][i]=0;
				ans-=dd;
			}
			for(i=1;i<=b;i++)
			{
				for(j=1;j<=b;j++)
				printf("%lld",adj[i][j]);
				printf("\n");
			}
		}
		else
		{
			printf("IMPOSSIBLE\n");
		}

	}
	return 0;
}