#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int t, n, dp[1000001], flip;

int flipit(int x){
	int res = 0, rem;
	while(x > 0){
		rem = x%10;
		res *= 10;
		res += rem;
		x /= 10;
	}
	return res;
}
	
int main(){
	sd(t);
	
	for(int i = 1; i <= 1000000; i++){
		dp[i] = 10000000;
	}

	dp[1] = 1;
		
	for(int i = 2; i <= 1000000; i++){
		dp[i] = min(dp[i], min(i, dp[i-1]+1));
		
		flip = flipit(i);
		
		if(flip > i){
			dp[flip] = min(dp[flip], dp[i]+1);
		}
		
		
		//cout << i << " " << dp[i] << " " << flip << endl;
	}
	
	//for(int i = 1; i <= 100; i++){
	//	cout << dp[i] << endl;
	//}
	for(int T = 1; T <= t; T++){
		sd(n);
		printf("Case #%d: %d\n",T, dp[n]);
	}
	return 0;
}
