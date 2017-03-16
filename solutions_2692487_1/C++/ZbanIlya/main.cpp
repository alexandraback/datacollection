#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>


using namespace std;

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;

int n, a, b[maxn];

void solve() {
	cin >> a >> n;
	for (int i = 0; i < n; i++) cin >> b[i];
	sort(b, b + n);

	int ans = inf, cur = 0;
	for (int i = 0; i <= n; i++) {
		ans = min(ans, n - i + cur);
		while (a > 1 && a <= b[i]) {
			cur++;
			a += a - 1;
		}
		if (a > b[i]) a += b[i];
		else {
			break;
		}
	}
	cout << ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";
		solve();
		cout << endl;
	}
	return 0;
}