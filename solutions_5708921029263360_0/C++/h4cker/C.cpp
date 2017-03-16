#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

map < pair< pair<int, int>, int >, bool > mp;
int J, P, S, K;
int dp[11][11][11];
vector< pair < pair<int, int> , int > > v;

void solve(int j, int p, int s) {
	if (j > J || p > P || s > S) return;
	if (dp[j][p][0] < K && dp[0][p][s] < K && dp[j][0][s] < K
		&& mp.count(make_pair(make_pair(j, p), s)) == 0) {
		v.push_back(make_pair(make_pair(j, p), s));
		mp[make_pair(make_pair(j, p), s)] = true;
		dp[j][p][0]++;
		dp[j][0][s]++;
		dp[0][p][s]++;
	}
	solve(j+1, p, s);
	solve(j, p+1, s);
	solve(j, p, s+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL), cout.precision(15);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> J >> P >> S >> K;
		mp.clear();
		memset(dp, 0, sizeof(dp));
		v.clear();
		solve(1, 1, 1);
		cout << "Case #" << t << ": " << v.size() << "\n";
		for (int i = 0; i < v.size(); i++) {
			cout << v[i].first.first << " ";
			cout << v[i].first.second << " ";
			cout << v[i].second << "\n";
		}
	}

	return 0;
}
