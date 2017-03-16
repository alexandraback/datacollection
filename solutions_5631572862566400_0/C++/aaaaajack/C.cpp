#include<bits/stdc++.h>
using namespace std;
int a[1010];
bool vis[1010];
bool old[1010];
int ic[1010];
int stk[1010];
int csz[1010];
int len[1010];
vector<int> g[1010];
int get_len(int u){
	if(len[u]) return len[u];
	for(int i=0;i<g[u].size();i++){
		len[u]=max(len[u],get_len(g[u][i]));
	}
	return ++len[u];
}
int main(){
	int T;
	scanf("%d",&T);
	for(int cs=1;cs<=T;cs++){
		int n,mc=0,t2=0;
		scanf("%d",&n);
		memset(vis,0,sizeof(vis));
		memset(old,0,sizeof(old));
		memset(ic,0,sizeof(ic));
		memset(len,0,sizeof(len));
		memset(csz,0,sizeof(csz));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				int sz=0,tsz=0,cf;
				for(cf=i;!vis[cf];cf=a[cf]){
					stk[sz++]=cf;
					vis[cf]=true;
				}
				tsz=sz;
				if(!old[cf]){
					do{
						--sz;
						ic[stk[sz]]=cf;
						csz[cf]++;
					}while(stk[sz]!=cf);
				}
				for(int i=0;i<tsz;i++){
					old[stk[i]]=true;
				}
				for(int i=0;i<sz;i++){
					g[a[stk[i]]].push_back(stk[i]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(ic[i]==i){
				if(csz[i]>mc) mc=csz[i];
				if(csz[i]==2) t2+=get_len(i)+get_len(a[i]);
			}
		}
		printf("Case #%d: %d\n",cs,max(mc,t2));
	}
	return 0;
}