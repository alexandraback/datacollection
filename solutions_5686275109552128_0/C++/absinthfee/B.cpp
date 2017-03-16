#include <stdio.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int T,D;
int P[1010];
int dp[1010][1010];

int solveDP(int idx, int min) {

	if(idx <= min) return 0;
	if(dp[idx][min] != -1) return dp[idx][min];
	
	
	return (dp[idx][min] = (solveDP(idx-min,min) + 1));
}

int main() {

	scanf("%d",&T);
	
	memset(dp,-1,sizeof dp);
	
	for(int t = 1; t <= T;t++) {
		scanf("%d",&D);
		int result = 0;
		
		for(int i = 0; i < D;i++) {
			scanf("%d",&P[i]);
			result = max(result,P[i]);
		}
		
		
		for(int i = 1;i < result;i++) {
			int tempResult = i;
			for(int j = 0; j < D;j++) {
				tempResult += solveDP(P[j],i);
			}
			result = min(result,tempResult);
		}
		printf("Case #%d: %d\n",t,result);
	}
	
	

	return 0;
}
