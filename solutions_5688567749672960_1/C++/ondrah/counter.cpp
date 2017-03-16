#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <string>
#include <sstream>

#define pb push_back
#define mp make_pair
#define ll long long
#define FOR(i, A, N) for(int (i) = (A); (i) < (N); (i)++)
#define REP(i, N) for(int (i) = 0; (i) < (N); (i)++)

using namespace std;
int dp[9111111];
ll rev(ll x) {
	stringstream ss;
	ss << x;
	string res = ss.str();
	ll ans = 0;
	for(int i = res.size()-1; i>=0; i--) {
		ans = 10*ans+res[i]-'0';
	}
	return ans;
}

ll calc(ll num, int revd) {
	if(num <= 20)
		return num;
	if(num % 10 == 0)
		return 1+calc(num-1, 0);
	vector<int> V1;
	ll old = num;
	while(num > 0) {
		V1.pb(num%10);
		num /= 10;
	}

	if(!revd) {
		ll tmp = 0;
		ll best = 1<<30;
		for(int i = 0; i < (V1.size()+1)/2; i++) {
			tmp = 10*tmp + V1[i];
		}
		tmp = rev(tmp);
		ll x = rev(old-tmp+1);
		best = min(best, tmp+calc(x, 1));
		if(x == old-tmp+1)
			best--;

		return best;
	} else {
		ll nxt = 0;
		REP(i, V1.size()-1) nxt = 10*nxt+9;		
		return old-nxt+calc(nxt, 0);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, 1100000) dp[i] = 1<<30;
	dp[1] = 1;
	int k = 0;
	for(int i = 1; i <= 1000000; i++) {
		dp[i+1] = min(dp[i+1], dp[i]+1);
		int rv = rev(i);
		k = max(k, dp[i]);
//		printf("%d %d\n", i, rv);
		dp[rv] = min(dp[rv], dp[i]+1);
	}
	
	for(int testc = 1; testc <= T; testc++) {
		ll n;
		scanf("%lld", &n);
		printf("Case #%d: %lld\n", testc, calc(n, 0));
	}	
	return 0;
}
