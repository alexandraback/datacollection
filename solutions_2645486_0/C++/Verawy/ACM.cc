#include<iostream>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
#define LL long long

int f[100][100],v[100];

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T,E,R,n;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d%d",&E,&R,&n);
		for (int i=1;i<=n;i++) scanf("%d",&v[i]);
		memset(f,-1,sizeof(f));
		f[0][E]=0;
		for (int i=0;i<=n;i++)
			for (int j=0;j<=E;j++)
				if (f[i][j]!=-1){
					for (int k=0;k<=j;k++){
						int t=min(j-k+R,E);
						f[i+1][t]=max(f[i+1][t],f[i][j]+v[i+1]*k);
					}
				}
		int ans=0;
		for (int i=0;i<=E;i++)
			ans=max(ans,f[n][i]);
		printf("Case #%d: %d\n",cas,ans);
	}
	return 0;
}
