#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <tuple>
#include <string.h>

typedef long long ll;
using namespace std;

bool isok(const vector<tuple<int, int, int>> &v, int K, int m) {
	int used[3][5][5] = {};
	for (int i = 0; i < (int)v.size(); i++) {
		if (m&(1<<i)) {
			auto &t = v[i];
			if (++used[0][get<0>(t)][get<1>(t)] > K) return false;
			if (++used[1][get<1>(t)][get<2>(t)] > K) return false;
			if (++used[2][get<0>(t)][get<2>(t)] > K) return false;
		}
	}
	return true;
}

vector<tuple<int, int, int>> solve(int J, int P, int S, int K) {
	vector<tuple<int, int, int>> ans;
	vector<tuple<int, int, int>> v;
	for (int j = 0; j < J; j++) {
		for (int p = 0; p < P; p++) {
			for (int s = 0; s < S; s++) {
				v.emplace_back(j+1, p+1, s+1);
			}
		}
	}
	if (K >= 3)
		return v;
	int n = v.size();
	int ms = 0;
	int oldx = -1;
	for (int i = 0; i < (1<<n); i++) {
		if (isok(v, K, i)) {
			if (ms < __builtin_popcount(i)) {
				ans.clear();
				for (int j = 0; j < (int)v.size(); j++) {
					if (i&(1<<j)) {
						ans.push_back(v[j]);
					}
				}
			}
		}
		int x = (int)(((double)i)*100 / (1<<n));
		if (x > oldx) {
			oldx = x;
			cerr << x << endl;
		}
	}
	return ans;
}

bool isok(const vector<tuple<int, int, int>> &v, int K) {
	map<pair<int, int>, int> used12;
	map<pair<int, int>, int> used23;
	map<pair<int, int>, int> used13;
	for (int i = 0; i < (int)v.size(); i++) {
		auto &t = v[i];
		if (++used12[make_pair(get<0>(t), get<1>(t))] > K) return false;
		if (++used23[make_pair(get<1>(t), get<2>(t))] > K) return false;
		if (++used13[make_pair(get<0>(t), get<2>(t))] > K) return false;
	}
	return true;
}

vector<tuple<int, int, int>> solve2(int J, int P, int S, int K) {
	vector<tuple<int, int, int>> ans;
	vector<tuple<int, int, int>> v;
	for (int j = 0; j < J; j++) {
		for (int p = 0; p < P; p++) {
			for (int s = 0; s < S; s++) {
				v.emplace_back(j+1, p+1, s+1);
				if (isok(v, K)) {
					ans = v;
				} else {
					v = ans;
				}
			}
		}
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int J, P, S, K;
		cin >> J >> P >> S >> K;
		vector<tuple<int, int, int>> ans = solve(J, P, S, K);
		cout << "Case #" << i+1 << ": " << ans.size() << endl;
		for (auto &t: ans) {
			cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;
		}
	}
}
