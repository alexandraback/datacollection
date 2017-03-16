#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define YES "YES"
#define NO "NO"

int N,M;
int matrix[101][101];

void print_matrix(){
	int i,j;
	for(i = 0;i < N;++i){
		for(j = 0;j < M;++j){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

char *is_possible(){
	int i,j,k,l,elem;
	if(M == 1 || N == 1)
		return YES;
	for(i = 0;i < N;++i){
		for(j = 0;j < M;++j){		
			elem = matrix[i][j];
			for(k = 0;k < N;++k){
				if(matrix[k][j] > elem){
					for(l = 0;l < M;++l){
						if(matrix[i][l] > elem)
							return NO;
					}
				}
			}
		}
	}
	return YES;
}

int main(){
	int i,T,j,k;
	scanf("%d\n",&T);
	for(i = 1;i <= T;++i){
		scanf("%d %d\n",&N,&M);
		for(j = 0;j < N;++j){
			for(k = 0;k < M;++k){
				scanf("%d",&matrix[j][k]);
			}
			scanf("\n");
		}
		printf("Case #%d: %s\n",i,is_possible());
	}
	return 0;
}

