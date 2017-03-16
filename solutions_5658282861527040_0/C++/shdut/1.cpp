#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;
//#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#define ll long long
#define ull unsigned long long
#define inf 2000000007
#define mod 1000000007
#define pii pair<int,int>
#define vi vector<int>
#define VS vector<string>
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define N 1020
#define pi 3.14159265358979323846
#define DBG(vari) cerr<<#vari<<"="<<(vari)<<endl;
#define FOREACH(i,t) for(typeof(t.begin()) i=t.begin();i!=t.end();i++)

ll dp[31][2][2][2];
int a[31],b[31],c[31];
ll fun(int x,int p,int q,int f)
{
	if(x==-1){return 1;}
	ll &ret=dp[x][p][q][f];
	if(ret+1)return ret;
	ret=0;
	if(f&&p&&q)return ret=1LL<<(2LL*x+2);
	else if(f&&p&&!q)
	{
		if(b[x])ret+=fun(x-1,p,1,f)*2LL+fun(x-1,p,q,f)*2LL;
		else ret+=fun(x-1,p,q,f)*2LL;
	}
	else if(f&&!p&&q)
	{
		if(a[x])ret+=fun(x-1,1,q,f)*2LL;
		ret+=fun(x-1,p,q,f)*2LL;
	}
	else if(f&&!p&&!q)
	{
		if(a[x]&&b[x])ret+=fun(x-1,1,q,f)+fun(x-1,p,1,f)+fun(x-1,1,1,f)+fun(x-1,p,q,f);
		else if(a[x]&&!b[x])ret+=fun(x-1,1,q,f)+fun(x-1,p,q,f);
		else if(!a[x]&&b[x])ret+=fun(x-1,p,1,f)+fun(x-1,p,q,f);
		else ret+=fun(x-1,p,q,f);
	}
	else if(!f&&p&&q)
	{
		if(c[x])ret+=fun(x-1,p,q,1)*3LL,ret+=fun(x-1,p,q,f);
		else ret+=fun(x-1,p,q,f)*3LL;
	}
	else if(!f&&p&&!q)
	{
		if(c[x])
		{
			if(b[x])ret+=fun(x-1,p,q,1),ret+=fun(x-1,p,1,1)*2LL,ret+=fun(x-1,p,q,f);
			else ret+=fun(x-1,p,q,1)*2LL;
		}
		else
		{
			if(b[x])ret+=fun(x-1,p,q,f),ret+=fun(x-1,p,1,f)*2LL;
			else ret+=fun(x-1,p,q,f)*2LL;
		}
	}
	else if(!f&&!p&&q)
	{
		if(c[x])
		{
			if(a[x])ret+=fun(x-1,p,q,1),ret+=fun(x-1,1,q,1)*2LL,ret+=fun(x-1,p,q,f);
			else ret+=fun(x-1,p,q,1)*2LL;
		}
		else
		{
			if(a[x])ret+=fun(x-1,p,q,f),ret+=fun(x-1,1,q,f)*2LL;
			else ret+=fun(x-1,p,q,f)*2LL;
		}
	}
	else if(!f&&!p&&!q)
	{
		if(c[x])
		{
			if(a[x]&&b[x])
			{
				ret+=fun(x-1,1,q,1)+fun(x-1,p,1,1)+fun(x-1,1,1,1)+fun(x-1,p,q,f);
			}
			else if(!a[x]&&b[x])
			{
				ret+=fun(x-1,p,q,1)+fun(x-1,p,1,1);
			}
			else if(a[x]&&!b[x])
			{
				ret+=fun(x-1,p,q,1)+fun(x-1,1,q,1);
			}
			else ret+=fun(x-1,p,q,1);
		}
		else
		{
			if(a[x]&&b[x])
			{
				ret+=fun(x-1,1,q,f)+fun(x-1,p,1,f)+fun(x-1,1,1,f);
			}
			else if(!a[x]&&b[x])
			{
				ret+=fun(x-1,p,q,f)+fun(x-1,p,1,f);
			}
			else if(a[x]&&!b[x])
			{
				ret+=fun(x-1,p,q,f)+fun(x-1,1,q,f);
			}
			else ret+=fun(x-1,p,q,f);
		}
	}
	return ret;
}
int main()
{
	freopen("1.txt","r",stdin);
	freopen("A-small.txt","w",stdout);
    int i,j,k,n,m,T,ca=0,d;
	scanf("%d",&T);
	while(T--)
	{
		int a1,b1;
		scanf("%d%d%d",&a1,&b1,&k);
		a1--,b1--;k--;
		for(i=30;i>=0;i--)
		if(a1&(1<<i))a[i]=1;
		else a[i]=0;
		for(i=30;i>=0;i--)
		if(b1&(1<<i))b[i]=1;
		else b[i]=0;
		for(i=30;i>=0;i--)
		if(k&(1<<i))c[i]=1;
		else c[i]=0;
		memset(dp,-1,sizeof(dp));
		ll ans=fun(30,0,0,0);
		printf("Case #%d: ",++ca);
		cout<<ans<<"\n";
	}
}