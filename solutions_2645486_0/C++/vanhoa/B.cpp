#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

long long val[10100];
int R, N, EMax;

long long dfs(int actNo, int ELeft){
	if(actNo==N) return 0;
	long long r=0;
	for(int i=0;i<=ELeft;i++){
		r=max(r,i*val[actNo]+dfs(actNo+1,min(EMax,ELeft-i+R)));
	}
	return r;
}

long long solveCaseSmall(){
	scanf("%d%d%d",&EMax,&R,&N);
	for(int i=0;i<N;i++) scanf("%d",&val[i]);
	return dfs(0,EMax);
}

int main(int argc, char *argv[]) {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	int T;scanf("%d",&T);
	for(int t=1;t<=T;t++){
		long long r=solveCaseSmall();
		printf("Case #%d: %lld\n",t,r);
	}
}