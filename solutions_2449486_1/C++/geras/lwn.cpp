// Author: Kamil Niziński
#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
int T[101][101],MAXW[101],MAXK[101];
bool solve () {
	int n,m,i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%d",&T[i][j]);
	fill(MAXW+1,MAXW+1+n,0);
	fill(MAXK+1,MAXK+1+m,0);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) {
		MAXW[i]=max(MAXW[i],T[i][j]);
		MAXK[j]=max(MAXK[j],T[i][j]);
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) if(T[i][j]<MAXW[i]&&T[i][j]<MAXK[j]) return 0;
	return 1;
}
int main() {
	int t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++) if(solve()) printf("Case #%d: YES\n",i);
	else printf("Case #%d: NO\n",i);
	return 0;
}