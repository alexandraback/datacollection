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
int rev(int x) {
	stringstream ss;
	ss << x;
	string res = ss.str();
	int ans = 0;
	for(int i = res.size()-1; i>=0; i--) {
		ans = 10*ans+res[i]-'0';
	}
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	REP(i, 1100000) dp[i] = 1<<30;
	dp[1] = 1;
	for(int i = 1; i <= 1000000; i++) {
		dp[i+1] = min(dp[i+1], dp[i]+1);
		int rv = rev(i);
//		printf("%d %d\n", i, rv);
		dp[rv] = min(dp[rv], dp[i]+1);
	}
	for(int testc = 1; testc <= T; testc++) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: %d\n", testc, dp[n]);
	}
	return 0;
}
