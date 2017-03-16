#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int N;

double WK[1005], WN[1005];

void input(){
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%lf", &WN[i]);
	for(int i = 0; i < N; i++)
		scanf("%lf", &WK[i]);
	
	sort(WN, WN+N);
	sort(WK, WK+N);
}

int dp[1005][1005];

int get_deceit(){
	int best = 0;
	
	for(int j = 0; j <= N; j++)
		dp[0][j] = 0;
	
	for(int i = 1; i <= N; i++){
		dp[i][0] = 0;
		
		for(int j = 1; j <= N; j++){
			if(WN[i-1] > WK[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	
	return dp[N][N];
}

int get_war(){
	int best = 0;
	for(int i = 0; i < N; i++){
		int num = 0;
		for(int j = 0; j < N; j++){
			if(WK[j] > WN[i])
				num++;
		}
		
		int naomiBlocks = N-i;
		
		best = max(best, naomiBlocks - num);
	}
	return best;
}

void test(){
	input();
	printf("%d %d\n", get_deceit(), get_war());
}

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		test();
	}
}
