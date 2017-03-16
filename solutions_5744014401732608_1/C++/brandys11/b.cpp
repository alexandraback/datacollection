#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
	ll B, M;
	cin >> B >> M;

	ll maximum = (1ll << (B - 2ll));
	if(M > maximum) {
		cout << "IMPOSSIBLE";
		return;
	}
	cout << "POSSIBLE";

	vector<vector<int>> G(B, vector<int> (B, 0));

	for(int i=1; i < B-1; i++) {
		for(int j=i+1; j < B; j++) {
			G[i][j] = 1;
		}
	}

	for(ll i=1; i < B - 1; i++) {
		ll act = (1ll << (B - 2ll - i));
		if (act <= M) {
			M -= act;
			G[0][i] = 1;
		}
	}
	if(M == 1ll) G[0][B-1] = 1;

	for(auto &r: G) {
		cout << endl;
		for(auto &b: r) cout << b; 
	}
}

int main(void) {
	int T;
	cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
}