#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
vector<int> v[1010];
int visit[1010];
int dfs(int u)
{
	visit[u] = 1;
	for(int i = 0; i < v[u].size(); i ++)
		if(visit[v[u][i]] || dfs(v[u][i])) return 1;
	return 0;
}
int main()
{
freopen("A-small-attempt0(2).in","r",stdin);
freopen("A-small-attempt0.out","w",stdout);
	int t,n,m;
	scanf("%d",&t);
	for(int k = 1; k <= t; k ++) {
		for(int i = 0; i < 1010;i ++)
			v[i].clear();
		scanf("%d",&n);
		for(int i = 1; i <= n; i ++) {
			scanf("%d",&m);
			int x;
			while(m --) {
				scanf("%d",&x);
				v[i].push_back(x);
			}
		}
		int flag = 0;
		for(int i = 1; i <= n; i ++) {
			memset(visit,0,sizeof(visit));
			if(dfs(i)) {
				flag = 1;
				break;
			}
		}
		printf("Case #%d: ",k);
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

