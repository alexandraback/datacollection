#include <stdio.h>
#include <string.h>
int dp[20][20];

int min(int a, int b){
	if(a < b)return a;
	return b;
}
int max(int a, int b){
	if(a > b)return a;
	return b;
}
int main(){
	int T;
	scanf("%d", &T);
	for(int TT=1;TT<=T;TT++){
		int e, r, n;
		scanf("%d%d%d", &e, &r, &n);
		int sum = 0, maxi = 0;
		memset(dp, 0, sizeof(dp));
		for(int i=1;i<=n;i++){
			int v;
			scanf("%d", &v);
			for(int j=0;j<=e;j++){
				for(int k=max(j-r,0);k<=e;k++){
					dp[i][j] = max(dp[i-1][k] + (min(k+r,e)-j)*v, dp[i][j]);
				}
			}
		}
		for(int j=0;j<=e;j++){
			maxi = max(maxi, dp[n][j]);
		}

		printf("Case #%d: %d\n", TT, maxi);
	}
}

