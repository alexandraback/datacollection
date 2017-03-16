#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int N;
int dp[100005];
char in[20][2][25];

int main(){
	scanf("%d", &T);
	for(int tt = 1; tt <= T; tt++){
		scanf("%d", &N);

		for(int i = 0; i < N; i++)
			scanf("%s %s", in[i][0], in[i][1]);

		for(int i = 0; i < (1 << N); i++)
			dp[i] = 0;

		for(int i = 0; i < (1 << N); i++){
			for(int j = 0; j < N; j++){
				if(((1 << j) & i) == 0){
					int ct1 = 0, ct2 = 0;

					for(int k = 0; k < N; k++){
						if(((1 << k) & i) != 0){
							if(strcmp(in[k][0], in[j][0]) == 0)
								ct1++;
							if(strcmp(in[k][1], in[j][1]) == 0)
								ct2++;
						}
					}
					if(ct1 > 0 && ct2 > 0)ct1 = 1;
					else ct1 = 0;

					dp[i + (1 << j)] = max(dp[i + (1 << j)], dp[i] + ct1);
				}
			}
		}

		printf("Case #%d: %d\n", tt, dp[(1 << N) - 1]);
	}
}