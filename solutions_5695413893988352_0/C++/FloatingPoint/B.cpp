#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

vector<pair<string, string> > results;
int T;

ull pow_10[20];

ull absd(ull a, ull b) {
	if (a > b) return a - b;
	return b - a;
}

string ulltos(ull x, int sz) {
	string s;
	s.resize(sz);
	for (int i = 0; i < sz; ++i) {
		s[sz - 1 - i] = '0' + x % 10;
		x /= 10;
	}
	return s;
}

bool matches(ull x, string s) {
	int sz = s.size();
	for (int i = 0; i < sz; ++i) {
		if (s[sz - 1 - i] != '?' && s[sz - 1 - i] != '0' + x % 10) return false;
		x /= 10;
	}
	return true;
}

pair<string, string> solve(string c, string j) {
	pair<ull, ull> minsol; ull mindiff = ULLONG_MAX;
	int N = c.size();
	for (ull i = 0; i < pow_10[N]; ++i) {
		for (ull k = 0; k < pow_10[N]; ++k) {
			if (matches(i, c) && matches(k, j)) {
				ull d = absd(i, k);
				if (d < mindiff || d == mindiff && i < minsol.first || d == mindiff && i == minsol.first && k < minsol.second) {
					minsol = make_pair(i, k);
					mindiff = d;
				}
			}
		}
	}
	return make_pair(ulltos(minsol.first, N), ulltos(minsol.second, N));
}

int main() {
#ifndef LOCAL
	freopen("B.txt", "r", stdin);
	freopen("B.out.txt", "w", stdout);
#endif
	pow_10[0] = 1ULL;
	for (int i = 1; i < 18; ++i) pow_10[i] = 10ULL * pow_10[i-1];
	cin >> T;
	results.resize(T);
	for (int i = 0; i < T; ++i) {
		string c, j;
		cin >> c >> j;
		results[i] = solve(c, j);
	}
	
	for (int i = 0; i < T - 1; ++i) cout << "Case #" << i + 1 << ": " << results[i].first << " " << results[i].second << endl;
	cout << "Case #" << T << ": " << results[T-1].first << " " << results[T - 1].second;
}