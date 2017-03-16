#include <cstdio>

int T;
int B;
long long M;
bool ans[55][55];
long long maxx;

int main(){
	scanf("%d", &T);
	for(int tt = 1; tt <= T; tt++){
		scanf("%d %lld", &B, &M);
		for(int i = 0; i < B; i++){
			for(int j = 0; j < B; j++)
				ans[i][j] = 0;
		}

		maxx = 1;
		for(int i = 0; i < B - 2; i++)
			maxx *= 2;

		//printf("%lld\n", maxx);

		if(maxx < M){
			printf("Case #%d: IMPOSSIBLE\n", tt);
		}else {
			printf("Case #%d: POSSIBLE\n", tt);
			for(int i = 1; i < B; i++){
				for(int j = i + 1; j < B; j++)
					ans[i][j] = 1;
			}

			for(int i = 1; i < B; i++){
				maxx /= 2;
				if(M > maxx){
					ans[0][i] = 1;
					M -= maxx;
				}
			}

			for(int i = 0; i < B; i++){
				for(int j = 0; j < B; j++)
					printf("%d", ans[i][j]);
				printf("\n");
			}
		}
	}
}