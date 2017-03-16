#include<bits/stdc++.h>
using namespace std;
int dp[1009][1009];
int func(int n, int k) {
//	cout<<n<<" "<<k<<endl;
	if(n <= k) {
		return 0;
	}
	if(dp[n][k] != -1)
		return dp[n][k];
	
	return dp[n][k] = min(func(n-k, k) +1, 1 + func(n/2, k) + func(n/2 + n%2, k));
}
long long int arr[10009];
int main()
{
	 freopen("inp.in","r",stdin);

        freopen("outp.out","w",stdout);
	int t;
	cin>>t;
	memset(dp, -1, sizeof(dp));
	for(int ca = 1; ca <= t; ca ++) {
		int d;
		cin>>d;
		long long  maxi = 0;
		for(int i = 0; i < d; i++) {
			cin>>arr[i];
			maxi = max(maxi, arr[i]);
		}
		long long  ans = maxi;
		for(int wa = maxi; wa >= 1; wa--) {
			long long  sum = 0;
			for(int i = 0; i < d; i++) {
				if(arr[i] -wa > 0) {
					sum += func(arr[i], wa);
				}
			}
		ans = min(ans, sum + wa);
		}
		cout<<"Case #"<<ca<<": "<<ans<<endl;
	}
	return 0;
}	
