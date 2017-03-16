#include<cstdio>
#include<cstring>
int f[1010],in[1010];
int dfn[1010],low[1010],clk,stk[1010],cnt;
int scc,sz[1010];
bool ins[1010],end[1010],ban[1010];
int ans;
void tarjan(int u){
	ins[u]=true;
	stk[++cnt]=u;
	dfn[u]=low[u]=++clk;
	int v=f[u];
	if(!dfn[v]){
		tarjan(v);
		if(low[v]<low[u])low[u]=low[v];
	}
	else if(ins[v]&&dfn[v]<low[u])low[u]=dfn[v];
	if(low[u]==dfn[u]){
		sz[++scc]=0;
		do{
			v=stk[cnt--];
			ins[v]=false;
			sz[scc]++;
		}while(v!=u);
		if(sz[scc]>ans)ans=sz[scc];
	}
}
int dep[1010],lst[1010];
void dfs(int u){
        ban[u]=true;
	int v=f[u];
	if(end[v]){
		dep[u]=1;
		lst[u]=v;
		return;
	}
	if(ban[v])return;
	if(dep[v]==-1)dfs(v);
	if(~dep[v])dep[u]=dep[v]+1,lst[u]=lst[v];
}
int es[1010];
int main(){
    freopen("C-small-attempt0.bin","r",stdin);
    freopen("output.txt","w",stdout);
	int t;scanf("%d",&t);
	int n,i;
	for(int cas=1;cas<=t;cas++){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&f[i]);
			ban[i]=in[i]=end[i]=0;
                }
		ans=0;
		for(i=1;i<=n;i++)
			if(f[f[i]]==i){
				end[i]=end[f[i]]=true;
				es[i]=es[f[i]]=0;
			}
		for(i=1;i<=n;i++)in[f[i]]++,dfn[i]=0;
		scc=clk=0;
		for(i=1;i<=n;i++)if(!dfn[i])tarjan(i);
		for(i=1;i<=n;i++)dep[i]=-1;
		for(i=1;i<=n;i++)
			if(!in[i]){
                                memset(ban,0,sizeof ban);
				dfs(i);
				if(dep[i]>es[lst[i]])es[lst[i]]=dep[i];
			}
		for(i=1;i<=n;i++)if(end[i]){
			if(es[i]+es[f[i]]+2>ans)ans=es[i]+es[f[i]]+2;
		}
		printf("Case #%d: %d\n",cas,ans);
	}

}
