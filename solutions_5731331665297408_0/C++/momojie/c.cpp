#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>

using namespace std;

bool map[55][55];
string a[55];
bool flag;
string ans;
int n,m;
bool vis[55];
int r[55];

/*
bool check(string tmp)
{
	int len = n * 5;
	for (int i = 0 ; i < len ; i--)
	{
		if (tmp[i] > ans[i]) return false;
		if (tmp[i] < ans[i]) return true;
	}
	return false;
}
*/

void check()
{
	for (int i = 1 ; i <= n ; i++)
	{
		string tmp1 = a[i];
		for (int j = i - 1 ; j >= 1 ; j--)
			tmp1 += a[j];
		for (int j = i + 1 ; j <= n ; j++)
			tmp1 += a[j];
		if (!flag || tmp1 < ans) ans = tmp1;
		flag = true;
		string tmp2 = a[i];
		for (int j = i + 1 ; j <= n ; j++)
			tmp2 += a[j];
		for (int j = i - 1 ; j >= 1 ; j--)
			tmp2 += a[j];
		if (!flag || tmp2 < ans) ans = tmp2;
		flag = true;
	}
}

void dfs(int k,int now)
{
	r[k] = now;
	vis[now] = true;
	if (k == n)
	{
		check();
		vis[now] = false;
		return ;
	}
	for (int i = 1 ; i <= n ; i++)
		if (!vis[i] && map[now][i])
			dfs(k+1,i);
	vis[now] = false;
}

int main()
{
	int t;
	scanf("%d",&t);
	int cas = 0;
	while (t--)
	{
		scanf("%d%d",&n,&m);
		memset(map,false,sizeof(map));
		for (int i = 1 ; i <= n ; i++)
			cin>>a[i];
		for (int i = 1 ; i <= m ; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			map[x][y] = map[y][x] = true;
		}
		flag = false;
		memset(vis,false,sizeof(vis));
		string tmp("");
		for (int i = 1 ; i <= n ; i++)
			dfs(1,i);
		printf("Case #%d: ",++cas);
		cout<<ans<<endl;
	}
	return 0;
}
