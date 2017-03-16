#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int B,M;
bool ar[60][60];
int num[60];
bool findM;

int findRoad(){
	for(int i=B-1; i>=1; --i){
		num[i]=0;
		for(int j=i+1; j<=B; ++j)
			if(ar[i][j])
				num[i]+=num[j];
	}
	return num[1];
}

void dfs(int n,int i){
	if(findM) return;
	if(n==B){
		if(findRoad() == M){ 
			puts("POSSIBLE");
			for(int i=1; i<=B; ++i){
				for(int j=1; j<=B; ++j){
					if(ar[i][j]) j!=B ? printf("1") : printf("1\n");
					else j!=B ? printf("0") : printf("0\n");
				}
			}
			findM=true;
		}
		return;
	}
	if(i==B+1){
		dfs(n+1,n+2);
		return;
	}
	ar[n][i]=true;
	dfs(n,i+1);
	if(findM) return;
	ar[n][i]=false;
	dfs(n,i+1);
}

int main(){
	int T; scanf("%d",&T);
	for(int Case=1; Case<=T; ++Case){
		/* init */
		scanf("%d%d",&B,&M);
		memset(ar,false,sizeof(ar));
		num[B]=1;
		/* dfs */
		findM=false;
		printf("Case #%d: ",Case);
		dfs(1,2);
		if(!findM) puts("IMPOSSIBLE");
	}
	return 0;
}

