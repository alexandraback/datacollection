#include<bits/stdc++.h>
using namespace std;
const int maxn=100+5;
typedef long long ll;
int k, c, s;
ll solve(int a,ll l)
{
	ll res=0;
	for(int i=0;i<c;i++)
	{
		int x= a+i<k ? a+i : 0;
		res+=x*l;
		l/=k;
	}
	return res+1;
}
int main()
{
	//freopen("D-small-attempt0.in","r",stdin);
	//freopen("Da-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T, cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:",++cas);
		if(k>s*c)
		{
			puts(" IMPOSSIBLE");
			continue;
		}
		ll l=1;
		for(int i=1;i<c;i++) l*=k;
		for(int i=0;i<k;i+=c) printf(" %lld",solve(i,l));
		puts("");
	}
	return 0;
}

