#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define rep(i, l, r) for(int i = l; i <= r; ++i)
using namespace std;
int n;
int fa[1010];
bool vis[1010];
int d[1010];
int findcircle(int x, int deep){
	vis[x] = 1;
	d[x] = deep;
	if(vis[fa[x]]) return d[x] - d[fa[x]] + 1;
	return findcircle(fa[x], deep + 1);
}
vector<int> g[1010];
int dfs(int x, int ban){
	int ret = 0;
	for(int i = 0; i < g[x].size(); ++i)
		if(g[x][i] != ban) ret = max(ret, dfs(g[x][i], ban));
//	printf("dfs(%d %d) = %d\n", x, ban, ret + 1);
	return ret + 1;
}
int main(){
	
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int cas;
	cin >> cas;
	rep(Cas, 1, cas){
		cin >> n;
		rep(i, 1, n) scanf("%d", &fa[i]);
		int maxcircle = 0;
		rep(i, 1, n){
			memset(vis, 0, sizeof(vis));
			maxcircle = max(maxcircle, findcircle(i, 1));
		}
		int res = 0;
		rep(i, 1, n) g[i].clear();
		rep(i, 1, n) g[fa[i]].push_back(i);
		rep(i, 1, n) if(fa[fa[i]] == i){
			//printf("i = %d fa[i] = %d\n", i, fa[i]);
			int v1 = dfs(i, fa[i]);
			int v2 = dfs(fa[i], i);
		//	printf("v1 = %d v2 = %d\n", v1, v2);
			res += v1 + v2;
		}
		res >>= 1;
	//	printf("%d %d\n", maxcircle, res);
		printf("Case #%d: %d\n", Cas,max(maxcircle, res));
	}
	return 0;
}
