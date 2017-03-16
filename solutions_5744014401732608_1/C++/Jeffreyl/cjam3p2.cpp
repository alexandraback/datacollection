#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <cmath>
#define pii pair<int, int>
using namespace std;
long long T, B, M, dp[51]; bool ans[51][51];
int main() {
	// in a completed graph from 1 to n without cycles, there are 2^(n-2) paths
	// so we subtract the largest power of 2 from m repeatedly
	cin>>T;
	for (int t=1; t<=T; t++) {
		cin>>B>>M;
		for (int i=0; i<51; i++) memset (ans[i], 0, sizeof ans[i]);
		memset (dp, 0, sizeof dp);
		// max value is 2^B-2
		// we have 2^B-2 bits
		if (M>pow(2, B-2)) {
			cout<<"Case #"<<t<<": IMPOSSIBLE\n"; continue;
		}
		if (M==pow(2, B-2)) {
			cout<<"Case #"<<t<<": POSSIBLE\n";
			for (int i=0; i<B; i++) {
				for (int j=0; j<=i; j++) {
					cout<<"0"; ans[i][j]=0;
				}
				for (int j=i+1; j<B; j++) {
					cout<<"1"; ans[i][j]=1;
				} cout<<endl;
			}
			continue;
		}cout<<"Case #"<<t<<": POSSIBLE\n";
		for (int i=0; i<=B-2; i++) {
			ans[i+1][B-1] = M&(1L<<i);
			//cout<<ans[i];
		}//cout<<endl;
		for (int i=0; i<B-1; i++) {
			for (int j=0; j<=i; j++) {
				cout<<"0";
				ans[i][j]=0;
			}
			for (int j=i+1; j<B-1; j++) {
				cout<<"1";
				ans[i][j]=1;
			} cout<<ans[i][B-1]<<" "<<endl;
		} for (int i=0; i<B; i++) cout<<"0"; cout<<endl;
		dp[0]=1;
		/*for (int i=0; i<B; i++) {
			for (int j=0; j<i; j++) if (ans[j][i]) dp[i]+=dp[j];
			cout<<dp[i]<<" ";
		}*/
		/*while (M) {
			int L=pow(2,floor(log(M)/log(2)));
			M-=L;
			cout<<L<<" ";
		}*/
	}
	return 0;
}
