#include <cstdio>
#include <cmath>
#include <cstring>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
const int maxn=11;
int f[maxn][maxn];
int v[maxn];
int n,e,r;

void init(){
	scanf("%d%d%d",&e,&r,&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	return;
}

int dp(){
	memset(f,0xff,sizeof(f));
	f[0][e]=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<=e;j++){
			if (f[i][j]==-1){
				continue;
			}
			for (int k=0;k<=j;k++){
				int rem=min(e,j-k+r);
				f[i+1][rem]=max(f[i+1][rem],f[i][j]+v[i+1]*k);
			}
		}
	}
	int ans=-1;
	for (int i=0;i<=e;i++){
		ans=max(ans,f[n][i]);
	}
	return ans;
}

int main(){
	int tcase;
	scanf("%d",&tcase);
	for (int i=1;i<=tcase;i++){
		init();
		printf("Case #%d: %d\n",i,dp());
	}
	return 0;
}
