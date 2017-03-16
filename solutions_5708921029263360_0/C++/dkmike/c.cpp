#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

typedef pair<int, int> pii;

int addCount(map<pii, int>& count, const pii& cur) {
	if (count.end() != count.find(cur)) {
		count[cur] = count[cur] + 1;
	} else {
		count[cur] = 1;
	}

	return count[cur];
}

int check(const vector<pii>& comb, const vector<int>& p, int k) {
	map<pii, int> c1;
	map<pii, int> c2;
	map<pii, int> c3;
	const int num = (int)comb.size();
	for (int i = 0; i < num; ++i) {
		pii cur = comb[p[i]];

		if (addCount(c1, cur) > k) {
			return i;
		}

		if (addCount(c2, make_pair(1, cur.first)) > k) {
			return i;
		}

		if (addCount(c3, make_pair(1, cur.second)) > k) {
			return i;
		}
	}

	return num;
}

void ss(int t, int p, int s, int k, int pos) {
	vector<pii> comb;
	for (int i = 1; i <= p; ++i) {
		for (int j = 1; j <= s; ++j) {
			comb.emplace_back(i, j);
		}
	}

	const int num = p * s;
	vector<int> pe(num);
	for (int i = 0; i < num; ++i) {
		pe[i] = i;
	}

	vector <int> cpe;
	int best = 0;
	do {
		int cur = check(comb, pe, k);
		if (cur > best) {
			best = cur;
			cpe = pe;
		}
	} while (next_permutation(pe.begin(), pe.end()));

	cout << "Case #" << t << ": " << best << endl;

	for (int i = 0; i < best; ++i) {
		pii cur = comb[cpe[i]];
		if (0 == pos) {
			cout << 1 << ' ' << cur.first << ' ' << cur.second << endl;
		} else if (1 == pos) {
			cout << cur.first << ' ' << 1 << ' ' << cur.second << endl;
		} else {
			cout << cur.first << ' '<< cur.second << ' ' << 1 << endl;
		}
	}
}

void solve(const int t) {
	int j, p, s, k;
	cin >> j >> p >> s >> k;
	if (j <= p && j <= s) {
		ss(t, p, s, k, 0);
	} else if (p <= j && p <= s) {
		ss(t, j, s, k, 1);
	} else if (s <= j && s <= p) {
		ss(t, j, p, k, 2);
	}
}

int main() {
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		solve(i + 1);
	}

	return 0;
}
