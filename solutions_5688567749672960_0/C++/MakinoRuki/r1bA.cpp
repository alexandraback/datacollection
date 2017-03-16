#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define N 1000010
#define inf 1000000000
using namespace std;
typedef long long ll;
int T;
ll n;
int dp[N];
int edge[N];
bool vis[N];
int getRev (int cur) {
	int res = 0;
	while (cur) {
		res = res * 10 + cur % 10;
		cur /= 10;
	}
	return res;
}
void spfa (int cur) {
	memset(vis, false, sizeof(vis));
	queue<int> Q;
	Q.push(1);
	vis[1] = true;
	dp[1] = 1;
	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		vis[cur] = false;
		if (edge[cur] >= 0) {
			if (dp[edge[cur]] > dp[cur] + 1) {
				dp[edge[cur]] = dp[cur] + 1;
				if (!vis[edge[cur]]) {
					vis[edge[cur]] = true;
					Q.push(edge[cur]);
				}
			}
		}
		if (dp[cur + 1] > dp[cur] + 1) {
			dp[cur + 1] = dp[cur] + 1;
			if (!vis[cur + 1]) {
				vis[cur + 1] = true;
				Q.push(cur + 1);
			}
		}
	}
}
int main() {
	freopen ("A-small-attempt1.in", "r", stdin);
	freopen ("out.txt", "w", stdout);
	cin>>T;
	for (int cas = 1; cas <= T; ++cas) {
		cin>>n;
		memset(edge, -1, sizeof(edge));
		for (int i = 1; i <= n; ++i) {
			dp[i] = inf;
			int rev = getRev (i);
			if (rev != i) {
				edge[i] = rev;
			}
		}
		spfa (1);
		printf("Case #%d: %d\n", cas, dp[n]);
	}
	return 0;
}
