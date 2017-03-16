#include<stdio.h>
int grid[110][110];
int main(){
	int tc;
	scanf("%d",&tc);
	for(int t=0;t<tc;t++){
		printf("Case #%d: ",t+1);
		int N,M;
		scanf("%d%d",&N,&M);
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				scanf("%d",&grid[i][j]);
		}
		bool can=true;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				bool largest=true;
				for(int u=0;u<N;u++){
					if(grid[u][j]>grid[i][j]){
						largest=false;
						break;
					}
				}
				if(largest)
					continue;
				largest=true;
				for(int u=0;u<M;u++){
					if(grid[i][u]>grid[i][j]){
						largest=false;
						break;
					}
				}
				if(!largest){
					can=false;
					break;
				}
			}
			if(!can)
				break;
		}
		if(can)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
