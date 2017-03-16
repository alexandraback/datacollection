#include<stdio.h>
#include<algorithm>
long long dp[1000001],from[1000001];
long long rev(long long x){
	long long ret=0;
	while(x){
		ret=ret*10+x%10;
		x/=10;
	}
	return ret;
}
int main(){
	int i,j,k;
	int T,TN;
	//printf("%lld\n",rev(3200));
	scanf("%d",&TN);
	dp[1]=1;
	for(i=2;i<=1000000;i++){
		dp[i]=dp[i-1]+1;
		from[i]=i-1;
		long long r=rev(i);
		if(i%10&&r<i&&dp[i-1]>dp[r]){
			dp[i]=dp[r]+1;
			from[i]=r;
		}
	}
	for(T=1;T<=TN;T++){
		long long n;
		scanf("%lld",&n);
		if(0)while(n>1){
			printf("%lld,",n);
			n=from[n];
		}
		printf("Case #%d: %lld\n",T,dp[n]);
	}
}
