#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cassert>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 1000000 + 5;
LL n;
LL dp[MAXN];
LL reverse(LL x) {
	LL ret = 0;
	while (x) {
		ret = ret * 10 + x % 10;
		x /= 10;
	}
	return ret;
}
void bfs() {
	queue<int> q;
	q.push(1);
	dp[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u + 1 <= 1000000 && dp[u + 1] == 0) {
			dp[u + 1] = dp[u] + 1;
			q.push(u + 1);
		}
		int v = reverse(u);
		if (v <= 1000000 && dp[v] == 0) {
			dp[v] = dp[u] + 1;
			q.push(v);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	memset(dp, 0, sizeof(dp));
	bfs();
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		cin >> n;
		printf("Case #%d: %lld\n", cas, dp[n]);
	}
	return 0;
}

