#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <numeric>
#define rep(x, to) for (int x = 0; x < (to); x++)
#define REP(x, a, to) for (int x = (a); x < (to); x++)
#define foreach(itr, x) for (typeof((x).begin()) itr = (x).begin(); itr != (x).end(); itr++)

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<long, long> PLL;

const int MAX_N = (int)(1e+6 + 5);
const int INF = (int)(1e+9 + 7);

ll T,N;
ll ans;
ll dp[MAX_N];
queue<int> que;

int rev(int x) {
	int res = 0;
	while (x > 0) {
		res *= 10;
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main() {
	fill(dp, dp + MAX_N, INF);
	dp[1] = 1;
	que.push(1);
	while (!que.empty()) {
		int cur = que.front(); que.pop();
		if (cur + 1 < MAX_N && dp[cur + 1] > dp[cur] + 1) {
			dp[cur + 1] = dp[cur] + 1;
			que.push(cur + 1);
		}
		int r = rev(cur);
		if (r < MAX_N && dp[r] > dp[cur] + 1) {
			dp[r] = dp[cur] + 1;
			que.push(r);
		}
	}
	cin >> T;
	rep(i, T) {
		cin >> N;
		printf("Case #%d: %lld\n", i + 1, dp[N]);
	}
	return 0;
}


