#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <queue>
#include <cstdlib>
#include <map>
#include <utility>
#include <algorithm>
#define pb push_back
#define MP make_pair
typedef long long ll;
using namespace std;
ll dp[10000005][2];
ll dp_remain[10000005][2];
vector<ll> v;
int  M,t,n,m,s;
int T;
ll E , R,N;
ll dfs(ll d , ll remain){
	if (d >= N) return 0;
	ll ans = 0;
	for(int take=0;take<=remain; take++){
		if( remain - take + R > E) continue;
		ll temp = take * v[d] + dfs(d+1 , remain - take + R);
		ans = max(ans , temp);
	}
	return ans;
	
}
int main(){
	int i,j,k;
	cin >> T;
	for(t =1;t<=T;t++){
		v.clear();
		cin >> E >> R >> N;
		for(n=0;n<N;n++){
			ll temp;
			cin >> temp;
			v.pb(temp);
		}
		ll ans = dfs(0, E);
		
		if (E <= R){
			ll ans= 0;
			for(int i=0;i<N;i++){
				ans+=v[i]*E;
			}

			cout<<"Case #"<<t<<": "<<ans<<endl;;
			continue;
			dp[0][0] = E*v[0];
			dp_remain[0][0] = R;
		}
		/*
		else{
			dp[0][0] = R*v[0];
			dp_remain[0][0] = E;
		}

		dp[0][1] = E * v[0];
		dp_remain[0][1] = R;
		cout<<dp[0][0]<<" "<<dp[0][1]<<endl;
		for(i=1;i<N;i++){
			ll temp1 = dp[i-1][0];
			ll temp1_remain=-1;
			if(dp_remain[i-1][0] + R <=E){
				temp1_remain = dp_remain[i-1][0] + R;
			}else{
				temp1 +=(dp_remain[i-1][0] + R - E)*v[i];
				temp1_remain = E;
			}
			ll temp2 = dp[i-1][1];
			ll temp2_remain = -1;
			if(dp_remain[i-1][1] + R <= E){
				temp2_remain = dp_remain[i-1][1]+R;
			}else{
				temp2 += (dp_remain[i-1][1] + R - E) * v[i];
				temp2_remain = E;
			}
			if(temp1 > temp2){
				dp[i][0] = temp1;
				dp_remain[i][0] = temp1_remain;
			}else{
				dp[i][0] = temp2;
				dp_remain[i][0]  = temp2_remain;
			}

			temp1 = dp[i-1][0] + v[i]*dp_remain[i-1][0];
			temp1_remain=R;
			temp2 = dp[i-1][1] + v[i]*dp_remain[i-1][1];
			temp2_remain = R;
			if(temp1 > temp2){
				dp[i][1] = temp1;
				dp_remain[i][1] = temp1_remain;
			}else{
				dp[i][1] = temp2;
				dp_remain[i][1]  = temp2_remain;
			}
			cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		*/
		cout<<"Case #"<<t<<": ";
		cout<<ans<<endl;

	}	
	return 0;
}
