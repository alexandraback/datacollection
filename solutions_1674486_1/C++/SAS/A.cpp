#include<stdio.h>
#include<stdlib.h>
int m[1021];
int in[1021][1021];
int used[1021];
int flag = 0;
void dfs(int n){
	if(used[n] == 1){
		flag = 1;
		return;
	}
	used[n] = 1;
	for(int i=0;i<m[n];i++){
		dfs(in[n][i]);
		if(flag == 1)return;
	}
}
int N;
int main(){
	int T;
	scanf("%d",&T);
	for(int ca = 1;ca <=T;ca++){
		scanf("%d",&N);
		for(int i=0;i<N;i++){
			used[i] = 0;
			scanf("%d",&m[i]);
			for(int j=0;j<m[i];j++){
				scanf("%d",&in[i][j]);
				in[i][j]--;
			}
		}

		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++)used[j] = 0;
			flag = 0;
			dfs(i);
			if(flag == 1)break;
		}


		printf("Case #%d: ",ca);
		if(flag == 0)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
