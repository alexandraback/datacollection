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

using namespace std;
bool check(long long n)
{
	static char buf[100];
	sprintf(buf,"%lld",n);
	int l=strlen(buf);
	for(int i=0;i<l;i++)if(buf[i]!=buf[l-1-i])return 0;
	return 1;
}
int dp[1<<20];
int n;
int num[20];
int key[20];
int has[20][50],K[20];
int good[1000];
int mp[1000],cnt;
int dfs(int s)
{
	if(s==0)return 1;
	if(dp[s]!=-1)return dp[s];
	int temp[20];
	for(int i=0;i<cnt;i++)temp[i]=num[i];
	for(int i=0;i<n;i++)if(!(s&(1<<i)))
	{
		temp[key[i]]--;
		for(int j=1;j<=K[i];j++)
			temp[has[i][j]]++;
	}
	for(int i=0;i<n;i++)if((s&(1<<i))&&(temp[key[i]]))
	{
		if(dfs(s^(1<<i)))return dp[s]=1;
	}
	return dp[s]=0;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		int kk;
		scanf("%d %d",&kk,&n);
		memset(num,0,sizeof(num));
		cnt=0;
		memset(mp,-1,sizeof(mp));
		memset(good,0,sizeof(good));
		for(int i=1;i<=kk;i++)
		{
			int x;
			scanf("%d",&x);
			num[x]++;
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&key[i]);
			good[key[i]]=1;
			scanf("%d",&K[i]);
			for(int j=1;j<=K[i];j++)
				scanf("%d",&has[i][j]);
		}
		for(int i=1;i<=200;i++)if(good[i])
			mp[i]=cnt++;
		for(int i=1;i<=200;i++)if(mp[i]!=-1)num[mp[i]]=num[i];
		for(int i=0;i<n;i++)
		{
			key[i]=mp[key[i]];
			int tt=0;
			for(int j=1;j<=K[i];j++)if(mp[has[i][j]]!=-1)
				has[i][++tt]=mp[has[i][j]];
			K[i]=tt;
		}
		memset(dp,-1,sizeof(dp));
		int s=(1<<n)-1;
		int out[20],top=0;
		while(s)
		{
			int temp[20];
			for(int i=0;i<cnt;i++)temp[i]=num[i];
			for(int i=0;i<n;i++)if(!(s&(1<<i)))
			{
				temp[key[i]]--;
				for(int j=1;j<=K[i];j++)
					temp[has[i][j]]++;
			}
			bool gao=0;
			for(int i=0;i<n;i++)if((s&(1<<i))&&(temp[key[i]]))
			{
				if(dfs(s^(1<<i)))
				{
					gao=1;
					s^=1<<i;
					out[top++]=i;
					break;
				}
			}
			if(!gao)break;
		}
		printf("Case #%d: ",++cas);
		if(s)puts("IMPOSSIBLE");
		else
		{
			for(int i=0;i<top-1;i++)printf("%d ",out[i]+1);
			printf("%d\n",out[top-1]+1);
		}
	}
}
