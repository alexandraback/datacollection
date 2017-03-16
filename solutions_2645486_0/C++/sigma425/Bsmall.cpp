#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int t,e,r,n;
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> e >> r >> n;
		int dp[11][6];
		for(int j=0;j<11;j++){
			for(int k=0;k<6;k++){
				dp[j][k]=-1;
			}
		}
		dp[0][e]=0;
		for(int j=0;j<n;j++){
			int v;
			cin >> v;
			for(int k=0;k<=e;k++){
				for(int l=0;l<=k;l++){
					dp[j+1][min(k-l+r,e)]=max(dp[j+1][min(k-l+r,e)],dp[j][k]+l*v);
				}
			}
		}
		int ans=-1;
		for(int j=0;j<=e;j++){
			ans=max(ans,dp[n][j]);
		}
		cout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}