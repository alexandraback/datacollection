#include <cstdio>


int v[1001],depth[1001],f[1001],a[1001][1001];
int n,ans,t;
int find(int x,int g,int d){
	if (v[x]>0){
		if(v[x]==g){
			return d-depth[x];
		}
		return 0;
	}
	v[x]=g;
	depth[x]=d;
	return find(f[x],g,d+1);
	
}

int max(int x,int y){
	return x>y?x:y;
}
int dfs(int x){
	int ans = 0;
	v[x] =1001;
	for (int j = 1; j <= a[x][0]; ++j){
		if (a[x][j]==f[x]) continue;
		ans =max(ans,dfs(a[x][j]));
	}
	return ans+1;
}

int main(){

	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&t);
	ans = 0;
	for (int tt = 1; tt <= t; ++tt){
		scanf("%d",&n);
		ans =0;
		for (int i = 1; i <= n; ++i){
			scanf("%d",&f[i]);
			a[i][0]=0;
			v[i]=0;
			depth[i]=0;
		}
		for (int i = 1; i <= n; ++i){
			a[f[i]][0]++;
			a[f[i]][a[f[i]][0]]=i;
		}

		for (int i = 1; i <= n; ++i){
			if (f[f[i]]==i)
				ans += dfs(i);
		}

		for (int i = 1; i <=n; ++i){
			if(v[i]==0){
				ans = max(ans, find(i,i,0));
			}
		}

		printf("Case #%d: %d\n",tt,ans);
	}

	return 0;
}