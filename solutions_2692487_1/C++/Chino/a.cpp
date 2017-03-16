#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int motes[1000][1000];
int sum[1000];
int N, A;

void bfs(int cur){
	
}

int main(int argc, char *argv[]){
	int T;
	scanf("%d\n",&T);
	for(int cases=0; cases<T; cases++){
		scanf("%d %d\n", &A, &N);
		for(int i=0; i<N; i++){
			scanf("%d\n",&motes[0][i+1]);
		}
		sort(motes[0]+1, motes[0]+N+1);
		int i, j;
		i=1;
		j=1;
		int bestSoFar = N;
		int cur = 0;
		motes[1][0]=A;
		int inc;
		
		while(i<=N){
			if(motes[j][i-1]>motes[0][i]){
				motes[j][i] = motes[j][i-1]+motes[0][i];
				i++;
				
			}else{
			//	printf("%d %d\n",cur, bestSoFar);
				inc = motes[j][i-1] - 1;
				if(!inc){
					break;
				}
				motes[j+1][i-1] = motes[j][i-1] + inc;
				j++;				
			}
			cur = N-(i-1) + j-1;
				if(bestSoFar > cur){
					bestSoFar = cur;
				}
		}
		
		//printf("%d %d %d\n",i,j,bestSoFar);
		printf("Case #%d: %d\n", cases+1, bestSoFar);
	}
	
}

