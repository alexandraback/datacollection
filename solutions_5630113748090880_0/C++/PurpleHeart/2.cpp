#include <cstdio>
#include <cstring>

int gao[5005];
int cases, N;

int main(){
	scanf("%d", &cases);
	for(int xx = 1; xx <= cases; ++xx){
		scanf("%d", &N);
		memset(gao, 0, sizeof(gao));
		for(int i = 0; i < 2 * N - 1; ++i){
			for(int j = 0; j < N; ++j){
				int x;
				scanf("%d", &x);
				gao[x]++;
			}
		}
		printf("Case #%d:", xx);
		for(int i = 1; i <= 2500; ++i)
			if(gao[i] % 2)
				printf(" %d", i);
		puts("");
	}
}
