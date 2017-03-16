#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 12

using namespace std;

int v[MAX];
int E, R, N;
int dp[MAX][MAX];

int f(int p, int e){
	if(p == N)
		return 0;
	if(dp[p][e] != -1)
		return dp[p][e];
	int &r = dp[p][e];
	r = 0;
	for(int i = 0; i <= e; i++){
		r = max(r, i*v[p] + f(p+1, min(E, e-i+R)));
	}
	return r;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		scanf("%d%d%d", &E, &R, &N);
		for(int i = 0; i < N; i++)
			scanf("%d", &v[i]);

		for(int i = 0; i < MAX; i++)
			for(int j = 0; j < MAX; j++)
				dp[i][j] = -1;

		printf("Case #%d: %d\n", t, f(0, E));
	}
	return 0;
}
