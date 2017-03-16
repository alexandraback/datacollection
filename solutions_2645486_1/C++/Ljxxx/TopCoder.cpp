#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int E, R, n;
int v[10000], ne[10000];

void input() {
	scanf("%d%d%d", &E, &R, &n);

	if(R > E) R = E;
	
	for(int i = 0;i < n;i ++) scanf("%d", &v[i]);
}

void solve1() {
	int dp[12][6];
	for(int i = 0;i <= n;i ++) for(int j = 0;j <= E;j ++) dp[i][j] = 0;
	
	for(int i = 0;i < n;i ++) for(int j = 0;j <= E;j ++) for(int k = 0;k <= j;k ++) {
		int tmp = k+R;
		if(tmp > E) tmp = E;
		if(dp[i][j] + (j-k)*v[i] > dp[i+1][tmp]) dp[i+1][tmp] = dp[i][j] + (j-k)*v[i];
	}

	int res = 0;
	for(int i = 0;i <= E;i ++) if(dp[n][i] >= res) res = dp[n][i];
	printf("%d\n", res);
}

void solve() {
	ne[n-1] = -1;
	for(int i = n-2;i >= 0;i --) {
		int j = i+1;
		while(j != -1&&v[j] <= v[i]) j = ne[j];

		ne[i] = j;
	}

	long long res = 0;
	long long cur_E = E;
	for(int i = 0;i < n;i ++) {
		if(ne[i] == -1) {
			res += cur_E*v[i];
			cur_E = R;
			continue;
		}

		long long tmp = ((long long)R)*(ne[i] - i);

		tmp = cur_E + tmp - E;
		if(tmp < 0) tmp = 0;
		if(cur_E < tmp) tmp = cur_E;

		res += tmp*v[i];

		cur_E += R-tmp;

		if(cur_E > E) cur_E = E;
	}

	printf("%lld\n", res);
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cas = 1;cas <= t;cas ++) {
		input();
		printf("Case #%d: ", cas);
		solve();
	}
	return 0;
}