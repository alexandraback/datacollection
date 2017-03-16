#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long llong;

int E, R, N;
int v[10];
int dp[10][6];

int DP(int i, int e){
	if(i == N) return 0;
	if(dp[i][e] >= 0) return dp[i][e];
	int &ret = dp[i][e];
	ret = 0;
	for(int x = 0;x <= e; ++x){
		ret = max(ret, x * v[i] + DP(i + 1, min(e - x + R, E)));
	}
	return ret;
}
int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for(int cas = 1;cas <= TT; ++cas){
		scanf("%d %d %d", &E, &R, &N);
		for(int i = 0;i < N; ++i){
			scanf("%d", v + i);
		}
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", cas, DP(0, E));
	}
	return 0;
}