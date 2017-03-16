#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
#endif
}

const int MAX = 1000006;
const int INF = 0x7FFFFFFF;

int reverse(int n) {
	char num[20] = {0};
	sprintf(num, "%d", n);
	int len = strlen(num);
	int x = 0;
	for (int i = len - 1; i >= 0; i--) {
		x *= 10;
		x += num[i] - '0';
	}
	return x;
}

int dodp(int n) {
	vector<int> dp(n + 1, INF);
	dp[1] = 1;
	for (int i = 1; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		int r = reverse(i);
		if (r <= n) {
			dp[r] = min(dp[r], dp[i] + 1);
		}
	}
	return dp[n];
}

void solve() {
	int n; scanf("%d ", &n);
	printf("%d\n", dodp(n));
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
