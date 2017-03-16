#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

const int N=1005;

int n,fa[N],d[N];
int tim,vis[N],step[N];

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&fa[i]),d[i]=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			++tim;
			int u,s=0;
			for(u=i;vis[u]!=tim;u=fa[u],s++) vis[u]=tim,step[u]=s;
			ans=max(ans,s-step[u]);
			d[u]=max(d[u],step[u]);
		}
		int tot=0;
		for(int i=1;i<=n;i++) if(fa[fa[i]]==i){
			tot+=d[i]+d[fa[i]]+2;
		}
		printf("Case #%d: %d\n",Case,max(tot/2,ans));
	}
}
