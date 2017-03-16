#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 103
using namespace std;
int T,cas=0,n,m,a[MAXN][MAXN],l[MAXN],r[MAXN],flag[MAXN][MAXN],ans;
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		printf("Case #%d: ",++cas);
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				scanf("%d",&a[i][j]);
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;++i){
			memset(l,0,sizeof(l));
			memset(r,0,sizeof(r));
			for(int j=1;j<=m;++j)
				l[j]=max(l[j-1],a[i][j]);
			for(int j=m;j>0;--j){
				r[j]=max(r[j+1],a[i][j]);
				if(l[j]<=a[i][j]&&r[j]<=a[i][j]) flag[i][j]=1;
			}
		}
		for(int i=1;i<=m;++i){
			memset(l,0,sizeof(l));
			memset(r,0,sizeof(r));
			for(int j=1;j<=n;++j)
				l[j]=max(l[j-1],a[j][i]);
			for(int j=n;j>0;--j){
				r[j]=max(r[j+1],a[j][i]);
				if(l[j]<=a[j][i]&&r[j]<=a[j][i]) flag[j][i]=1;
			}
		}
		ans=1;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if(!flag[i][j]) {ans=0;break;}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
