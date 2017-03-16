#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[1000001];

int rev(int x){
	int ans;
	for( ans=0 ; x ; x/=10 ) ans = ans*10+x%10;		
	return ans;
}

int main(){

	int test,tc=1,ans,i,j;
	int n;
	
	for( i=0 ; i<=1000000 ; i++ ) dp[i]=10000000;
	
	dp[1]=1;
	for( i=1 ; i<1000000 ; i++ ){
		dp[i+1]=min(dp[i]+1,dp[i+1]);
		dp[rev(i)]=min(dp[i]+1,dp[rev(i)]);	
	}
	
	for( scanf("%d",&test) ; test-- ; printf("Case #%d: %d\n",tc++,ans) ){
		scanf("%d",&n);
		ans=dp[n];
	}

	return 0;
}

