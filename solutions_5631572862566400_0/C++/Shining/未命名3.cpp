#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int TT,l,r,n,found,ans,ok;
int vis[1010],nex[1010];
vector<int> like[1010];

int dfs2(int x){
	int ret=0;
	for	(int i=0;i<like[x].size();++i)
		if	(!vis[like[x][i]]){
			vis[like[x][i]]=1;
			ret=max(ret,dfs2(like[x][i])+1);
			vis[like[x][i]]=0;
		}
	return	ret;
} 

int dfs(int ori,int x){
	if	(nex[x]==ori)	return	1;
	if	(vis[x])	return	-999999;
	vis[x]=1;
	return	dfs(ori,nex[x])+1;
}

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&TT);
	for	(int T=1;T<=TT;++T){
		printf("Case #%d:",T);
		scanf("%d",&n);
		for	(int i=0;i<=n;++i)	like[i].clear();
		for	(int i=1;i<=n;++i){
			scanf("%d",&nex[i]);
			like[nex[i]].push_back(i);
		}
		ans=0;
		memset(vis,0,sizeof vis);
		for	(int i=1;i<=n;++i)
			if	(vis[i]==0 && nex[nex[i]]==i){
				vis[i]=vis[nex[i]]=1;
				ans+=2+dfs2(i)+dfs2(nex[i]);
			}
			
		for	(int i=1;i<=n;++i){
			memset(vis,0,sizeof vis);
			ans=max(ans,dfs(i,i));
		} 
		printf(" %d\n",ans);
	}
} 
