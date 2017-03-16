//看看会不会爆int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()

int n, T;
vector<int> g[1010];
int vis[1010];
int b[1010];
int dep[1010];
int ans;

void dfs(int t, int f, int dp){
	vis[t] = f; dep[t] = dp;
	if(!vis[b[t]]) dfs(b[t], f, dp + 1);
	else if(vis[b[t]] == f) ans = max(ans, dp - dep[b[t]] + 1);
}

int DFS(int t){
	int dp = 1;
	for(auto v : g[t])
		if(!vis[v]){
			dp = max(dp, DFS(v) + 1);
		}
	return dp;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("ccc.in", "r", stdin);
	freopen("ccc.out", "w", stdout);
#endif
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d: ", t);
		ans = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) g[i].clear();
		for(int i = 1; i <= n; i++){
			scanf("%d", &b[i]);
			g[b[i]].pb(i);
		}
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i++)
			if(!vis[i]) dfs(i, i, 1);
		memset(vis, 0, sizeof(vis));
		int two = 0; int cnt = 0;
		for(int i = 1; i <= n; i++)
			if(b[b[i]] == i && i < b[i]){
				two++;
				vis[i] = vis[b[i]] = 1;
				int t1 = DFS(i);
				int t2 = DFS(b[i]);
				cnt += t1 + t2;
			}
		ans = max(ans, cnt);
		cout << ans << endl;
	}
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         佛祖保佑       永无BUG
*/
