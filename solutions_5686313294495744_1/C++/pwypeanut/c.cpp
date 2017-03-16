#include <bits/stdc++.h>
using namespace std;

int T, N, f1[1005], s1[1005], owner[1005];
bool vis[1005];
vector<int> adjlist[1005];
string f[1005], s[1005];
vector<string> firsts, seconds;

int Aug(int left) {
	if (vis[left]) return 0;
	vis[left] = 1;
	for (int j = 0; j < adjlist[left].size(); j++) {
		int right = adjlist[left][j];
		if (owner[right] == -1 || Aug(owner[right])) {
			owner[right] = left;
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		firsts.clear();
		seconds.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) adjlist[i].clear();
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
		for (int i = 0; i < N; i++) adjlist[f1[i]].push_back(s1[i]);
		int ans = 0;
		memset(owner, -1, sizeof(owner));
		for (int i = 0; i < firsts.size(); i++) {
			memset(vis, 0, sizeof(vis));
			ans += Aug(i);
		}
		//printf("ans: %d\n", ans);
		printf("Case #%d: %d\n", tc, N - ((int)firsts.size() + seconds.size() - ans));
	}
}
