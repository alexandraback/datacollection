#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <set>
#define pb(x) insert(x)
using namespace std;

set<int> f[2000001];
set<int> ::iterator I;
void init(){
	int i,j,k,t,len;char c[100];
	for (i=1;i<=2000000;i++){
		sprintf(c,"%d",i);
		//printf("%s\n",c);
		for (j=1;j<strlen(c);j++){
			char s=c[0];
			for (k=0;k<strlen(c)-1;k++) c[k]=c[k+1];
			c[k]=s;
			if (c[0]!='0' && i<atoi(c)) f[i].pb(atoi(c));
		}
	}
}

void solve(){
	int n,i,j,t,A,B,ans;
	scanf("%d",&n);
	for (t=1;t<=n;t++){
		scanf("%d%d",&A,&B);ans=0;
		for (i=A;i<=B;i++){
			for (I=f[i].begin();I!=f[i].end();I++){
				if (*I>=A && *I<=B) ans++;
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
}

int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	init();
	solve();
}
