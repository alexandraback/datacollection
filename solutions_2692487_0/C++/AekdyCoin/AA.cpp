#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int dp[12][2111],n,a[111];
int getdp(int p,int x)
{
	int i,j,k;
	if (dp[p][x]!=-1)return dp[p][x];
	//printf("%d %d\n",p,x);
	if (p==n)return 0;
	int ans=n-p,t=x;
	for (i=p;i<n;i++)
	{
		if (t>a[i])
		{
			t+=a[i];
		}
		else break;
	}
	if (i>p)ans=min(ans,getdp(i,t));
	t=x;
	t+=t-1;
	if (t<2000)ans=min(ans,1+getdp(p,t));
	return dp[p][x]=ans;
}
int main()
{
	freopen("C:\\fdsfsda\\A-small-attempt2 (1).in","r",stdin);
	freopen("C:\\fdsfsda\\Aout1.txt","w",stdout);
	int s,i,j,k,cas,cc=0;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%d%d",&s,&n);
		for (i=0;i<n;i++)scanf("%d",a+i);
		if (s==1)
		{
			printf("Case #%d: %d\n",++cc,n);
			continue;
		}
		sort(a,a+n);
		memset(dp,-1,sizeof(dp));
		printf("Case #%d: %d\n",++cc,getdp(0,s));
	}
	return 0;
}
