#include<iostream>
#include<vector>

using namespace std;

int mmin(int a, int b) { return a<b?a:b; }

int main() {

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	int T;
	cin>>T;

	for(int t=1 ; t<=T ; t++) {
		int R,C,W;
		cin>>R>>C>>W;

		vector<int> dp(C+1);

		int ans=(R-1)*(C/W);

		for(int i=0 ; i<W ; i++) dp[i]=-1;
		for(int i=W ; i<=mmin(2*W-1,C) ; i++) {
			if(i==W) dp[i]=W;
			else dp[i]=W+1;
		}

		for(int i=2*W ; i<=C ; i++)
			dp[i]=1+dp[i-W];

		ans+=dp[C];

		cout<<"Case #"<<t<<": ";
		cout<<ans<<"\n";
	}

	return 0;
}