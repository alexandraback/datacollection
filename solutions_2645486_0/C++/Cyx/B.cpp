#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN=15;

int E,R,N,V[MAXN];
int ans;

void init(){
	scanf("%d%d%d",&E,&R,&N);
	for(int i=1;i<=N;i++) scanf("%d",&V[i]);
}

void dfs(int x,int e,int sum){
	if(x==N+1){
		ans=max(ans,sum);
		return ;
	}
	for(int i=0;i<=e;i++){
		dfs(x+1,min(e-i+R,E),sum+V[x]*i);
	}
}

void work(){
	ans=0;
	dfs(1,E,0);
	printf("%d",ans);
}

int main(){
	int T; scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d: ",t);
		init();
		work();
		printf("\n");
	}
	return 0;
}
