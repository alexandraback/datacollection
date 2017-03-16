#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
typedef long long LL;

int n;
int f[1001];
vector<int> rf[1001];

bool vis[1001];
int stacklev[1001];
int dis[1001];

int ans;

void dfs(int u,int lev) {
	vis[u]=1;
	stacklev[u]=lev;
	if (!vis[f[u]])
		dfs(f[u],lev+1);
	else if (stacklev[f[u]]!=0)
		ans=max(ans,stacklev[u]-stacklev[f[u]]+1);
	stacklev[u]=0;
}
int hs(int u) {
	if (dis[u]) return dis[u];
	int ret=1;
	for (int i=0;i<rf[u].size();i++)
		ret=max(ret,hs(rf[u][i])+1);
	return dis[u]=ret;
}
void init() {
	memset(vis,0,sizeof vis);
	memset(dis,0,sizeof dis);
	for (int i=1;i<=n;i++) rf[i].clear();
}
int main() {
	int T; scanf("%d",&T);
	for (int tt=1;tt<=T;tt++) {
		scanf("%d",&n);
		init();
		for (int i=1;i<=n;i++) scanf("%d",&f[i]),rf[f[i]].pb(i);

		ans=0;
		for (int i=1;i<=n;i++) if (!vis[i]) dfs(i,1);

		for (int i=1;i<=n;i++) vis[i]=0;
		int tmp=0;
		for (int i=1;i<=n;i++) if (!vis[i])
			if (f[f[i]]==i) {
				int u=i,v=f[i]; vis[u]=vis[v]=1;
				int t1=0;
				for (int j=0;j<rf[u].size();j++)
					if (rf[u][j]!=v) t1=max(t1,hs(rf[u][j]));
				int t2=0;
				for (int j=0;j<rf[v].size();j++)
					if (rf[v][j]!=u) t2=max(t2,hs(rf[v][j]));
				tmp+=t1+t2+2;
			}
		ans=max(ans,tmp);

		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
