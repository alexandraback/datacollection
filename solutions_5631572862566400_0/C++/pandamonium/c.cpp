#include <bits/stdc++.h>
using namespace std;
int t,n,pa[1005],cyc[1005];
int vis[1005];
typedef pair<int,int> ii;
queue <ii> q;
vector <int> adj[1005],cyc2;
int main(){
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		scanf("%d",&n);
		for(int x=1;x<=n;x++) adj[x].clear();
		for(int x=1;x<=n;x++){
			scanf("%d",&pa[x]);
			adj[pa[x]].push_back(x);
		}
		memset(vis,0,sizeof(vis));
		memset(cyc,0,sizeof(cyc));
		cyc2.clear();
		int maxcyc=1;
		for(int x=1;x<=n;x++){
			if(!vis[x]){
				int v=x;
				while(!vis[v]){
					vis[v]=1;
					v=pa[v];
				}
				int cnt=0;
				while(vis[v]==1){
					vis[v]=2;
					cnt++;
					v=pa[v];
				}
				maxcyc=max(maxcyc,cnt);
				while(vis[v]==2){
					cyc[v]=cnt;
					if(cnt==2) cyc2.push_back(v);
					vis[v]=3;
					v=pa[v];
				}
				v=x;
				while(vis[v]==1){
					vis[v]=3;
					v=pa[v];
				}
			}
		}
		memset(vis,0,sizeof(vis));
		int ans=0;
		for(int x=0;x<cyc2.size();x++){
			q.push(ii(cyc2[x],1));
			int maxd=1;
			vis[cyc2[x]]=1;
			while(!q.empty()){
				ii cur=q.front();
				maxd=max(cur.second,maxd);
				q.pop();
				for(int y=0;y<adj[cur.first].size();y++){
					if(cyc[adj[cur.first][y]]!=2&&!vis[adj[cur.first][y]]){
						vis[adj[cur.first][y]]=1;
						q.push(ii(adj[cur.first][y],cur.second+1));
					}
				}
			}
			ans+=maxd;
		}
		printf("Case #%d: %d\n",c,max(ans,maxcyc));
	}
	return 0;
}
