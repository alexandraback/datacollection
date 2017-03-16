#include <bits/stdc++.h>

using namespace std;

int aug(int l, vector<vector<int>> & G, vector<bool> & visited, vector<int> & match) {
	if(visited[l]) return 0;
	visited[l] = true;
	for(int r : G[l]) {
		if(match[r] == -1 || aug(match[r], G, visited, match)) {
			match[r] = l;
			return 1;
		}
	}
	return 0;
}

void solve(int t) {
	int M;
	cin >> M;
	vector<vector<int>> G(2 * M + 1);
	vector<bool> is_left(2 * M + 1, false);
	vector<int> match(2 * M + 1, -1);
	map<string, int> to_int[2];
	int idx = 1;
	for(int m = 0; m < M; ++m) {
		string s1, s2;
		cin >> s1 >> s2;
		int x, y;
		if(to_int[0][s1])
			x = to_int[0][s1];
		else
			x = to_int[0][s1] = idx++;
		if(to_int[1][s2])
			y = to_int[1][s2];
		else
			y = to_int[1][s2] = idx++;
		G[x].push_back(y);
		is_left[x] = true;
	}
	int ans = 0;
	for(int n = 0; n <= 2 * M; ++n)
		if(is_left[n]) {
			vector<bool> visited(2 * M + 1, false);
			ans += aug(n, G, visited, match);
		}
	printf("Case #%d: %d\n", t, M - int(to_int[0].size() + to_int[1].size()) + ans);
}

int main() {	
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t)
		solve(t);
}
