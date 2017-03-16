#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int dp[20][20],v[20];
int main() {
	int _,E,R,N,ca(0); cin>>_;
	while(_--) {
		cin>>E>>R>>N;
		memset(dp,0,sizeof dp);
		for(int i(0);i!=N;++i)
			cin>>v[i+1];
		for(int i(0);i<N;++i)
			for(int j(R);j<=E;++j)
				for(int k(0);k<=j;++k)
					dp[i+1][j-k+R] = max(dp[i+1][j-k+R],dp[i][j]+k*v[i+1]);
		int res = *max_element(dp[N],dp[N]+E+1);
		printf("Case #%d: %d\n",++ca,res);
	}
}
