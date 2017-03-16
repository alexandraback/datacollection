#include <bits/stdc++.h>
using namespace std;

void solve (int tc) {
	int n, cnt[1005];
	memset (cnt, 0, sizeof cnt);
	map <string, int> s[2];
	pair <string, string> a[1005];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; i++)
		s[0][a[i].first]++, s[1][a[i].second]++;
	for (int i = 0; i < n; i++) 
		cnt[i] += s[0][a[i].first] > 1,
		cnt[i] += s[1][a[i].second] > 1;
	int ret = 0;
	for (int i = 0; i < n; i++) if (cnt[i] > 1) ret++;
	cout << "Case #" << tc << ": " << ret << "\n";
}

int main () {
//	ios_base :: sync_with_stdio(0);
//	cin.tie(0);
//	clock_t start = clock();
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) solve (tc);
//	cout << (double) (clock() - start) / CLOCKS_PER_SEC << "\n";
}