#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A[40],n,K;
void dfs(int k1,int k2){
	if (k1>=n){
		K--;
		for (int i=1;i<=n;i++) if (A[i]||A[i-1]) putchar('1'); else putchar('0');
		for (int i=2;i<=10;i++) printf(" %d",i+1); printf("\n");
		return;
	}
	if (k2==0){
		A[k1]=1; dfs(k1+1,1); if (K==0) return;
	}
	if (k1!=n-1&&k1!=1){
		A[k1]=0; dfs(k1+1,0); if (K==0) return;
	}
}
void solve(){
	scanf("%d%d",&n,&K);
	dfs(1,0);
}
int main(){
	freopen("large.in","r",stdin);
	freopen("large.out","w",stdout);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d:\n",i); solve();
	}
}
