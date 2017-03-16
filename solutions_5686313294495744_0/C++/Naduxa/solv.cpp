#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <string>
#include <time.h>

using namespace std;
const int N = 16;
vector<pair<string, string>> g;

int dp[(1 << N)];
int n;


int yes(int mask, int j) {
	bool f1 = false;
	bool f2 = false;
	for (int i = 0; i < n; i++) {
		if (i == j) continue;
		if (g[i].first == g[j].first && ((mask & (1 << i)) == 0))
		{
			f1 = true;
		}
		if (g[i].second == g[j].second && ((mask & (1 << i)) == 0))
		{
			f2 = true;
		}
	}
	if (f1 && f2)
		return true;
	return false;
}

int calc(int mask) {
	if (dp[mask] != -1)
		return dp[mask];
	if (mask == 0) {
		return dp[mask] = 0;
	}

	dp[mask] = 0;
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) != 0) {
			int r = yes(mask, i);
			dp[mask] = max(dp[mask], calc(mask ^ (1 << i)) + r);
		}
	}
	return dp[mask];
}

int solve() {
	memset(dp, -1, sizeof dp);
	return calc((1 << n) - 1);
}

int main() {
#ifdef _DEBUG
	freopen("kuku.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	freopen("kuku.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin.tie(0);
	cout.sync_with_stdio(false);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n;
		g.clear();
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			g.push_back(make_pair(s1, s2));
		}
		cout << "Case #" << t + 1 << ": ";
		cout << solve() << endl;
	}
	return 0;
}