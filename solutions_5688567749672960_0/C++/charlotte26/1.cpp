#include<iostream>
#include<algorithm>
using namespace std;
int rev(long long n) {
	long long ans=0;
	while(n) {
		ans*=10;
		ans+=(n%10);
		n/=10;
	}
	return ans;
}
int dp[1000001];
int main() {
	int c=1,T;
	cin>>T;
	while(c<=T) {
		int n;
		cin>>n;
		dp[1]=1;
		for(int i=2;i<=n;i++) {
			if(i%10==0) {
				dp[i]=dp[i-1]+1;
				continue;
			}
			if(rev(i)<i)dp[i]=min(dp[i-1]+1,dp[rev(i)]+1);
			else dp[i]=dp[i-1]+1;
			//cout<<i<<" "<<dp[i]<<endl;
		}
		cout<<"Case #"<<c<<": "<<dp[n]<<endl;
		c++;
	}
	return 0;
}
