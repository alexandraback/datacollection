#include <string.h>
#include <stdio.h>

int num_ways[1001];
int N;
int graph[1001][11];

void print_ways(){
	int i;
	for(i =0;i <=N;++i){
		printf("%d ",num_ways[i]);
	}
	printf("\n");
}

void found_ways(int i){
	int k;
	if(i == 0)
		return;
	for(k = 1;k <= graph[i][0];++k){
		//printf("encontrado camino desde %d hacia %d\n",i,graph[i][k]);
		num_ways[graph[i][k]]++;
		if(num_ways[graph[i][k]] >= 2){
			return;
		}
		found_ways(graph[i][k]);
	}
}

int check_ways(){
	int i;
	for(i = 1;i <= N;++i){
		if(num_ways[i] >= 2){
			return 1;
		}
	}
	return 0;
}

int calculate_ways(){
	int i,res,j,k,l;
	for(i = 1;i <= N;++i){
		memset(num_ways,0,sizeof(num_ways));
		found_ways(i);
		//print_ways();
		res = check_ways();
		if(res)
			break;
	}
	return res;
}

int main(){
	int i,T,j,k,res;
	scanf("%d\n",&T);
	for(i = 1;i <=T;++i){
		scanf("%d\n",&N);
		for(j = 1;j <= N;++j){
			scanf("%d",&graph[j][0]);
			for(k = 1;k <= graph[j][0];++k){
				scanf("%d",&graph[j][k]);
			}
			scanf("\n");
		}
		res = calculate_ways();
		printf("Case #%d: %s\n",i,res ? "Yes" : "No");
	}
	return 0;
}

