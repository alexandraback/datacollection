#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int R,N,M,K;
int A[10],B[10];
bool flag[128],FLAG;

void init(){
	scanf("%d%d%d%d",&R,&N,&M,&K);
}

void dfs2(int x,int res){
	if(x>N){
		flag[res]=1;
		return;
	}
	dfs2(x+1,res*B[x]);
	dfs2(x+1,res);
}

void dfs1(int x){
	if(x>N){
		memset(flag,0,sizeof(flag));
		dfs2(1,1);
		for(int i=1;i<=K;i++) if(!flag[A[i]]) return;
		FLAG=true;
		return;
	}
	for(int i=2;i<=M;i++){
		B[x]=i;
		dfs1(x+1);
		if(FLAG) return;
	}
}

void work(){
	for(int i=1;i<=R;i++){
		for(int j=1;j<=K;j++) scanf("%d",A+j);
		FLAG=false;
		dfs1(1);
		for(int j=1;j<=N;j++) printf("%d",B[j]);
		//printf("\n");
		//for(int j=1;j<=125;j++) if(flag[j]) printf("%d ",j);
		printf("\n");
	}
}

int main(){
	int T; scanf("%d",&T);
	for(int t=1;t<=T;t++){
		printf("Case #%d:\n",t);
		init();
		work();
	}
	return 0;
}
