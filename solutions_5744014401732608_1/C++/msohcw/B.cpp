#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

#define INF 2000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int TC;

int main(){
	scanf("%d", &TC);
	for(int Tn = 1; Tn <= TC; Tn++){
		printf("Case #%d: ", Tn);
		int B;
		long long M;
		scanf("%d%lld", &B, &M);

		int adj[100][100];
		long long num_ways[100];

		long long max_ways = (long long) pow(2, B-2);
		if(M > max_ways){
			printf("IMPOSSIBLE\n");
		}else{
			printf("POSSIBLE\n");
			memset(adj, 0, sizeof(adj));
			memset(num_ways, 0, sizeof(num_ways));
			for(int i = 0; i < B; i++){
				for(int j = i+1; j < B; j++){
					adj[i][j] = 1;
				}
				num_ways[i] = (i >= 2)? ((long long) pow(2, i-1)):1;
				// printf("%lld ", num_ways[i]);
			}
			long long ways = max_ways;
			for(int i = B-1; i >= 0; i--){
				if(ways == M) break;
				if(ways - num_ways[i] < M) continue;
				ways -= num_ways[i];
				adj[i][B-1] = 0;
			}
			for(int i = 0; i < B; i++){
				for(int j = 0; j < B; j++){
					printf("%d", adj[i][j]);
				}
				printf("\n");
			}
		}
	}
}