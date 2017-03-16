#include <iostream>
#include <vector>
#include <map>
using namespace std;
int solve() {
	int N;
	cin >> N;
	vector<int> d(N), n(N), w(N), e(N), s(N), dd(N), dp(N), ds(N);
	for (int i = 0; i < N; ++ i) {
		cin >> d[i] >> n[i] >> w[i] >> e[i] >> s[i] >> dd[i] >> dp[i] >> ds[i];
	}
	map<int, vector<pair<pair<int,int>, int> > > a;
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < n[i]; ++ j) {
			a[d[i] + j * dd[i]].push_back(make_pair(make_pair(w[i] + j * dp[i], e[i] + j * dp[i]), s[i] + j * ds[i]));
		}
	}
	map<int, int> b;
	int r = 0;
	for (map<int, vector<pair<pair<int,int>, int> > >::iterator i = a.begin(); i != a.end(); ++ i) {
		for (unsigned j = 0; j < i->second.size(); ++ j) {
			int k0 = i->second[j].first.first;
			int k1 = i->second[j].first.second;
			int k2 = i->second[j].second;
			for (int k = k0; k < k1; ++ k) {
				if (b[k] < k2) {
					++ r;
					break;
				}
			}
		}
		for (unsigned j = 0; j < i->second.size(); ++ j) {
			int k0 = i->second[j].first.first;
			int k1 = i->second[j].first.second;
			int k2 = i->second[j].second;
			for (int k = k0; k < k1; ++ k) {
				b[k] = max(b[k], k2);
			}
		}
	}
	return r;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}
