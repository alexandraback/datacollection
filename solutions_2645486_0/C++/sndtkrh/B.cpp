#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int cnt = 1; cnt <= T; cnt++){
		int E, R, N;
		int v[10];
		scanf("%d %d %d", &E, &R, &N);
		for(int i = 0; i < N; i++){
			scanf("%d", v + i);
		}
		int dp[N][E + 1];
		for(int j = 0; j <= E; j++)
			dp[0][j] = v[0] * (E - j);
		for(int i = 1; i < N; i++){
			for(int j = 0; j <= E; j++){
				int t = -10000;
				for(int k = E+R; k-R >= 0 && k - j >= 0; k--){
					int f;
					if(k > E) f = E - j;
					else f = k - j;
					t = max(t, dp[i-1][k-R] + f * v[i]);
				}
				dp[i][j] = t;
			}
		}
/*
		for(int i = 0; i < N; i++){
			for(int j = 0; j <= E; j++){
				printf("%d ", dp[i][j]);
			}
			puts("");
		}
*/
		printf("Case #%d: %d\n", cnt, dp[N-1][0]);
	}
}
