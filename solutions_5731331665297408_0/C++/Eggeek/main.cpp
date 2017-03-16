#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define maxn 10
int n,m,ord[maxn];
int g[maxn][maxn],gg[maxn][maxn];
string s[maxn];
bool vis[maxn];
string ans;

void dfs(int cur,string curs, int cnt) {
	string nxt;
	if (cnt==n) {
		if (ans.size()==0 || ans>curs)
			ans = curs;
		return;
	}
	for (int i=1; i<=n; i++ ) if (gg[cur][i]) {
		gg[cur][i]--;
		if (!vis[i]) {
			nxt=curs+s[i];
			vis[i] = true;
			dfs(i,nxt,cnt+1);
			vis[i] = false;
			g[cur][i]++;
		} else {
			nxt=curs;
			dfs(i,nxt,cnt);
			g[cur][i]++;
		}
	}
}

void work() {
	scanf("%d%d",&n,&m);
	memset(g,0,sizeof(g));
	for (int i=1; i<=n; i++ ) cin>>s[i];
	for (int i=1; i<=m; i++ ) {
		int u,v;
		scanf("%d%d",&u,&v);
		g[u][v] = 1;
		g[v][u] = 1;
	}
	ans = "";
	for (int i=1; i<=n; i++ ) {
		memset(vis,0,sizeof(vis));
		memcpy(gg,g,sizeof(g));
		dfs(i,"",1);
	}
	cout<<ans<<endl;
}

int main() {
	int cas;
	freopen("test.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&cas);
	for (int i=1; i<=cas; i++ ) {
		printf("Case #%d: ",i);
		work();
	}
	return 0;
}
