#include <bits/stdc++.h>
using namespace std;

int T, N, f1[1005], s1[1005], dp[100005];
string f[1005], s[1005];
vector<string> firsts, seconds;

int fn(int bm) {
	int maxi = 0;
	if (bm == 0) return 0;
	if (dp[bm] != -1) return dp[bm];
	for (int i = 0; i < N; i++) {
		if (bm & (1 << i)) {
			int newbm = bm ^ (1 << i);
			bool newf = 0, news = 0;
			for (int j = 0; j < N; j++) {
				if (newbm & (1 << j)) {
					if (f1[j] == f1[i]) newf = 1;
					if (s1[j] == s1[i]) news = 1;
				}
			}
			if (newf && news) maxi = max(maxi, fn(newbm) + 1);
			else maxi = max(maxi, fn(newbm));
		}
	}
	return dp[bm] = maxi;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		firsts.clear();
		seconds.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			cin >> f[i] >> s[i];
			firsts.push_back(f[i]);
			seconds.push_back(s[i]);
		}
		sort(firsts.begin(), firsts.end());
		sort(seconds.begin(), seconds.end());
		firsts.resize(unique(firsts.begin(), firsts.end()) - firsts.begin());
		seconds.resize(unique(seconds.begin(), seconds.end()) - seconds.begin());
		for (int i = 0; i < N; i++) f1[i] = lower_bound(firsts.begin(), firsts.end(), f[i]) - firsts.begin();
		for (int i = 0; i < N; i++) s1[i] = lower_bound(seconds.begin(), seconds.end(), s[i]) - seconds.begin();
		memset(dp, -1, sizeof(dp));
		printf("Case #%d: %d\n", tc, fn((1 << N) - 1));
	}
}
