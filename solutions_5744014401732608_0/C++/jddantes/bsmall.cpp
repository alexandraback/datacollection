#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int adjMat[6][6];
int ways_arr[6];

int B, M;


int dfs(int node){
	if(node == B-1){
		return ways_arr[node] = 1;
	}

	int ways = 0;
	for(int adj = node+1; adj<B; adj++){
		if(adjMat[node][adj]){
			int ret = dfs(adj);
			ways += ret;
		}
	}

	return ways_arr[node] = ways;
}

int main(){
	int cases;
	scanf("%d", &cases);

	for(int e = 0; e<cases; e++){
		scanf("%d %d", &B, &M);

		int numEdges = B*(B-1)/2;

		vector<pi> edges;
		for(int node = 0; node<B; node++){
			for(int adj = node+1; adj<B; adj++){
				edges.push_back(pi(node, adj));
			}
		}
		bool found = false;

		for(int comb = 0; comb< (1<<numEdges); comb++){

			for(int i = 0; i<B; i++){
				ways_arr[i] = -1;
				for(int j = 0; j<B; j++){
					adjMat[i][j] = 0;
				}
			}

			int mask = comb;
			int index = 0;
			while(mask){
				if(1 & mask){
					pi edge = edges[index];
					adjMat[edge.first][edge.second] = 1;
				}
				mask >>= 1;
				index++;
			}

			int ret = dfs(0);
			if(ret == M){
				found = true;
				printf("Case #%d: POSSIBLE\n", e+1);
				for(int i = 0; i<B; i++){
					for(int j = 0; j<B; j++){
						printf("%d", adjMat[i][j]);
					}
					printf("\n");
				}
				break;
			} else {

			}

		}

		if(!found){
			printf("Case #%d: IMPOSSIBLE\n", e+1);
		}


	}
}