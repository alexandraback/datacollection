#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int n,tt;
int num[2050],adj[2050][150],visited[2050];
bool dfs(int x)
{
	visited[x]=1;
	for (int a=1;a<=num[x];++a)
	{
		if (visited[adj[x][a]])
		{
			return true;
		}else visited[adj[x][a]]=1;
		if (dfs(adj[x][a])) return true;
	}
	return false;
}
bool find()
{
	for (int a=1;a<=n;++a)
	{
		memset(visited,0,sizeof(visited));
		if (dfs(a)) return true;
	}
	return false;
}
int main()
{
	freopen("result.in","r",stdin);
	freopen("result.out","w",stdout);
	scanf("%d",&tt);
	for (int z=1;z<=tt;++z)
	{
		scanf("%d",&n);
		for (int a=1;a<=n;++a)
		{
			scanf("%d",&num[a]);
			for (int b=1;b<=num[a];++b)
			{
				scanf("%d",&adj[a][b]);
			}
		}
		printf("Case #%d:",z);
		if (find()) printf(" Yes\n");
		else printf(" No\n");
	}
}
