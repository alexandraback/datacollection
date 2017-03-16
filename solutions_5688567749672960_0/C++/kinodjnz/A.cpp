#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

static int dp[1000010];

int flip(int x) {
	int r = 0;
	while (x > 0) {
		r *= 10;
		r += x%10;
		x /= 10;
	}
	return r;
}

void make_dp() {
	int INF = (1<<29);
	dp[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		dp[i] = INF;
	}
	for (int i = 1; i <= 1000000; i++) {
		//cout << i << endl;
		dp[i+1] = min(dp[i+1], dp[i]+1);
		int f = flip(i);
		if (dp[f] > dp[i]) {
			dp[f] = dp[i] + 1;
			if (f < i) {
				i = f-1;
			}
		}
	}
}

int solve_dp(int N) {
	return dp[N];
}

ll solve(ll N) {
	return solve_dp(N);
}

int main()
{
	make_dp();
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		ll N;
		cin >> N;
		ll ans = solve(N);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
