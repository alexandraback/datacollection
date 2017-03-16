#include<stdio.h>
#include<string.h>

#define MAX(A,B) ((A>B)?A:B)
#define MIN(A,B) ((A<B)?A:B)

int v[15];
int dp[15][15];
int N, E, R;

int f(int i, int k){
	if( i == N) return 0;
	if(dp[i][k]) return dp[i][k];
	int res = 0;
	for(int g = 0; g <= k; g++)
		res = MAX(res,f(i+1, MIN(E,k-g+R)) + g*v[i]);
	dp[i][k] = res;
	return res;
}

int main(){
	int T, tc = 1;
	scanf("%d", &T);
	while(T--){
		memset(dp, 0, sizeof(dp));
		scanf("%d %d %d", &E, &R, &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &v[i]);
		printf("Case #%d: %d\n", tc++, f(0,E));
	}
	return 0;
}
