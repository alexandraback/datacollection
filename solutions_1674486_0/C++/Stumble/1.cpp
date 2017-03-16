#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
int T;
int maps[1200][30];
int N,flag;
bool vis[1200];
void dfs(int now)
{
	if(vis[now]||flag)
	{
		flag=1;
		return ;
	}
	vis[now]=1;
	for(int i=1;i<=maps[now][0];i++)
	{
		int &to=maps[now][i];
		dfs(to);
	}
}
void solve(int num)
{
	flag=0;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",&maps[i][0]);
		for(int j=1;j<=maps[i][0];j++)
		scanf("%d",&maps[i][j]);
	}
	for(int i=1;i<=N;i++)
	{
		memset(vis,0,sizeof(vis));
		flag=0;
		dfs(i);
		if(flag)
		break;
	}
	if(flag)
	printf("Case #%d: Yes\n",num);
	else
	printf("Case #%d: No\n",num);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	solve(i);
	return 0;
}