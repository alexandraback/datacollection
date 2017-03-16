#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cmath>

typedef long long ll;

using namespace std;

ll dp[6][10];
ll E, R, N;
ll v[10];

ll solve(){
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= E; i++){
		ll gain = v[0]*i;
		dp[min(E, E-i+R)][0] = gain;
	}
	//for(int i = 0; i <= E; i++)
	//	cout<<i<<";"<<dp[i][0]<<endl;

	for(int i = 1; i < N; i++){
		for(int j = 0; j <= E; j++){ //j = consume
			for(int k = E; k >= j; k--){ //k = remain
				int remain = min(E, k-j+R);
				dp[remain][i] = max(dp[remain][i], dp[k][i-1]+j*v[i]);
			}
		}
	}
	ll ret = 0;
	for(int i = 0; i <=E; i++){
		ret = max(ret, dp[i][N-1]);
	}
	return ret;
}

int main(){
	int T; cin>>T;
	for(int i = 1; i <= T; i++){
		cin>>E>>R>>N;
		for(int j = 0; j < N; j++)
			cin>>v[j];
		//printf("%d\n", v[0]);
		ll ret = solve();
		printf("Case #%d: %ld\n", i, ret);
	}
	return 1;
}