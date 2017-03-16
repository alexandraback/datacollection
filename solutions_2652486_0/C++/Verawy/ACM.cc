#include<iostream>
#include<cstdio>
#include<string.h>
#include<cmath>
using namespace std;
#define LL long long

int v[100],a[100],k;
bool can[6*6*6];

bool tryit(int n){
	memset(can,false,sizeof(can));
	for (int i=0;i<(1<<n);i++){
		int x=1;
		for (int j=0;j<n;j++)
			if (i&(1<<j)) x*=a[j];
		can[x]=true;
	}
	for (int i=1;i<=k;i++)
		if (!can[v[i]]) return false;
	for (int i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
	return true;
}

bool dfs(int s,int n,int m){
	if (s==n)
		return tryit(n);
	for (int i=2;i<=m;i++){
		a[s]=i;
		if (dfs(s+1,n,m)) return true;
	}
	return false;
}

int main(){
	int T,n,m,r;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d%d%d%d",&r,&n,&m,&k);
		printf("Case #%d:\n",cas);
		for (int caseT=1;caseT<=r;caseT++){
			for (int i=1;i<=k;i++)
				scanf("%d",&v[i]);
//			for (int i=1;i<=k;i++){
//				for (int j=2;j<=m;j++)
//					if (v[i]%j==0){
//						v[i]/=j; pri[i][j]++;
//						fac[i]++;
//					}
//			}
			dfs(0,n,m);
		}
	}
	return 0;
}
