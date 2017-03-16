#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<map>
#include<string.h>
#include<set>
typedef long long lnt;
int a[1100],c,ori,ans[1100];
bool vi[1100],sp[1100];
int dfs(int k,int num){
	vi[k]=1;
	if(a[k]==ori) return num;
	if(vi[a[k]]) return 0;
	return dfs(a[k],num+1);
}
void DFS(int x){
	c++;
	vi[x]=1;
	if(sp[x]){
		if(c>ans[x]) ans[x]=c;
		return ;
	}
	if(vi[a[x]]) return;
	DFS(a[x]);
}
int main(){
	int n,k,i,T,t=0,max,in,g;
	freopen("C-large.in","r",stdin);
	freopen("pCout.txt","w",stdout);
	scanf("%d",&T);
	while(T--){
		t++;
	 	max=0;in=0;
	 	scanf("%d",&n);
	 	memset(sp,0,sizeof(sp));
	 	memset(ans,0,sizeof(ans));
	 	for(k=1;k<=n;k++) scanf("%d",&a[k]);
		for(k=1;k<=n;k++){
			memset(vi,0,sizeof(vi));
			ori=k;
			c=dfs(k,1);
			if(max<c) max=c;
			if(k==a[a[k]]){
				sp[k]=1;ans[k]=1;
			}
	 	}
	 	for(k=1;k<=n;k++){
	 		if(sp[k]) continue;
	 		memset(vi,0,sizeof(vi));
	 		c=0;
	 		DFS(k);
	 	}g=0;
	 	for(k=1;k<=n;k++){
	 		if(sp[k]) g+=ans[k];
	 	}
	 	if(max<g) max=g;
		printf("Case #%d: ",t);
		printf("%d\n",max); 
	}
}
