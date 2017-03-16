#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<string, string>> topics(n);
	map<string, int> first, second;
	for(auto& t : topics) {
		cin >> t.first >> t.second;
		if(!first[t.first]) {
			first[t.first] = first.size();
		}
		if(!second[t.second]) {
			second[t.second] = second.size();
		}
	}
	int best = 0;
	for(int mask = 0; mask < 1 << n; ++mask) {
		int f = 0, s = 0, count = 0;
		for(int i = 0; i < n; ++i) {
			if(mask & 1 << i) {
				f |= 1 << (first[topics[i].first] - 1);
				s |= 1 << (second[topics[i].second] - 1);
			} else {
				++count;
			}
		}
		if(f == (1 << first.size()) - 1 && s == (1 << second.size()) - 1) {
			best = max(best, count);
		}
	}
	cout << ' ' << best << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	for(int i = 1; i <= cases; ++i) {
		cout << "Case #" << i << ':';
		solve();
	}
	return 0;
}
