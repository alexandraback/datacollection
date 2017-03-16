#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#define fop freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
using namespace std;

long long a[110],s;
int n;
int ans;
void dfs(int pos,long long now,int gao)
{
	if(pos==n)ans=min(ans,gao);
	else
	{
		if(a[pos]<now)dfs(pos+1,now+a[pos],gao);
		else
		{
			ans=min(ans,gao+n-pos);
			dfs(pos,now+now-1,gao+1);
		}
	}
}
int main()
{
	fop;
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&s);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		ans=10000000;
		if(s>1)
		dfs(0,s,0);
		else ans=n;
		printf("Case #%d: %d\n",++cas,ans);
	}
}
