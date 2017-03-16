#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define repd(i,a,b) for (int i=(a);i>=(b);i--)

const int maxn=1200;
struct Edge{int nex,y;}e[maxn*maxn];
int rd[maxn],q[maxn],opt[maxn];
int fa[maxn];
int g[maxn][maxn];
bool vis[maxn];
int sum;
int n;

void dfs(int x) {
	if (vis[x]) return;
	vis[x]=true;
	sum++;
	dfs(fa[x]);
}

int main() {
	freopen("c.out","w",stdout);
	int T;scanf("%d\n",&T);
	rep(t,1,T) {
		printf("Case #%d: ",t);
		memset(g,0,sizeof g);
		scanf("%d\n",&n);
		rep(i,1,n) rd[i]=0;
		rep(i,1,n) {
			scanf("%d",&fa[i]);
			rd[fa[i]]++;
			g[i][fa[i]]=1;
		}
		int head(1),tail(0);
		rep(i,1,n) opt[i]=1;
		rep(i,1,n) if (rd[i]==0) q[++tail]=i,opt[i]=1;
		while (head<=tail) {
			int x=q[head++];
			if (--rd[fa[x]]==0) {
				q[++tail]=fa[x];
				opt[fa[x]]=max(opt[fa[x]],opt[x]+1);
			}
		}
	//	printf("%d\n",g[3][4]);
		//printf("%d\n",opt[3]);
		int ans=0;
		rep(i,1,n) {
			int t=fa[i];
			if (i == fa[fa[i]]) continue;
			if (g[t][fa[t]] && g[fa[t]][t]) {
				//ans=max(ans,opt[i]+2);
				opt[t]=max(opt[t],opt[i]+1);
			}
		}
		rep(i,1,n) vis[i]=false;
		sum=0;
		rep(i,1,n) {
			if (g[i][fa[i]] && g[fa[i]][i]) {
				//ans=max(ans,opt[i]+opt[fa[i]]);
				sum+=opt[i];
			}
		}
		ans=max(ans,sum);
		//rep(i,1,n) printf("%d %d\n",i,rd[i]);
		rep(i,1,n) {
			if (rd[i]) {
				if (i == fa[fa[i]]) continue;
				rep(j,1,n) vis[j]=false;
				sum=0;
				dfs(i);
				//printf("%d\n",sum);
				ans=max(ans,sum);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
