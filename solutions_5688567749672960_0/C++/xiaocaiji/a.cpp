#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN = 1000010;
int dp[MAXN];

int reverse(int val){
	int tot = 0;
	while(val){
		tot = tot * 10 + val %10;
		val = val / 10;
	}
	
	return tot;
}

int main(){
	
	memset(dp,0,sizeof(dp));
	dp[1] = 1; 
	for(int i=2;i<=1000000;i++){
		if(dp[i] == 0){
			dp[i] = dp[i-1] +1;
			int val = reverse(i);
			if(dp[val] == 0)
				dp[val] = dp[i]+1;
			else
				dp[val] = min(dp[val],dp[i]+1);
		}else{
                        dp[i] = min(dp[i-1]+1,dp[i]);
                }
	}
	
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		int N;
		scanf("%d",&N);
		printf("Case #%d: %d\n",i,dp[N]);
	}
} 
