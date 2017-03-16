#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <cassert>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
#include <functional>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)

const LL M = 1000000007;

int same_from_begin(const string& s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] != s[0]) {
			return i;
		}
	}
	return n;
}
int same_from_end(const string& s) {
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[n - i - 1] != s[n - 1]) {
			return i;
		}
	}
	return n;
}

int Solve() {
	int n;
	cin >> n;
	vector<string> sets(n);
	for (int i = 0; i < n; i++) {
		cin >> sets[i];
	}
	map<char, int> chars_count;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sets[i].size(); j++) {
			chars_count[sets[i][j]]++;
		}
	}
	map<char, int> same;
	map<char, int> same_chars_count;
	vector<string> not_same;
	map<char, int> starts_with;
	map<char, int> ends_with;
	for (int i = 0; i < n; i++) {
		const auto& s = sets[i];
		int c = same_from_begin(s);
		if (c == s.size()) {
			same[s[0]]++;
			same_chars_count[s[0]] += s.size();
		}
		else {
			not_same.push_back(s);
			int sz = not_same.size();

			if (starts_with[s[0]] != 0) {
				return 0;
			}
			starts_with[s[0]] = sz;

			if (ends_with[s.back()] != 0) {
				return 0;
			}
			ends_with[s.back()] = sz;
		}
	}
	n = not_same.size();
	vector<char> was(n);
	int was_count = 0;
	int res = 1;
	int pieces = 0;
	
	for (int i = 0; i < n; i++) {
		const auto& s = not_same[i];
		if (was[i]) {
			continue;
		}
		if (ends_with[s[0]] != 0) {
			continue;
		}
		int piece_res = 1;
		pieces += 1;

		for (int j = 0; j < same[not_same[i][0]]; j++) {
			piece_res = (piece_res * (LL)2) % M;
		}

		for (int si = i, prev_si = -1; si != -1;) {
			if (was[si]) {
				return 0;
			}
			was[si] = true;
			was_count++;
			if (same[not_same[si][0]] == -1) {
				throw 42;
				return false;
			}
			
			int expected_count = same_from_begin(not_same[si]) + same_chars_count[not_same[si][0]];
			if (prev_si != -1) {
				expected_count += same_from_end(not_same[prev_si]);
			}
			if (expected_count < chars_count[not_same[si][0]]) {
				return 0;
			}
			same[not_same[si][0]] = -1;
			prev_si = si;
			si = starts_with[not_same[si].back()] - 1;
			if (si == -1) {
				for (int j = 1; j <= same[not_same[prev_si].back()]; j++) {
					piece_res = (piece_res * (LL)j) % M;
				}
				same[not_same[prev_si].back()] = -1;
			}
		}
		res = (res * (LL)piece_res) % M;
	}
	if (was_count != n) {
		return 0;
	}
	for (auto it : same) {
		if (it.second != -1) {
			if (it.second == 0) {
				throw 53;
			}
			int piece_res = 1;
			pieces += 1;
			for (int j = 1; j <= it.second; j++) {
				piece_res = (piece_res * (LL)j) % M;
			}
			res = (res * (LL)piece_res) % M;
		}
	}
	for (int i = 1; i <= pieces; i++) {
		res = (res * (LL)i) % M;
	}
	/*for (char cc = 'a'; cc <= 'z'; cc++) {
		int expected = same_chars_count[cc];

		int si = starts_with[cc] - 1;
		if (si != -1) {
			expected += same_from_begin(not_same[si]);
		}

		int ei = ends_with[cc] - 1;
		if (ei != -1) {
			expected += same_from_end(not_same[ei]);
		}		

		if (expected != chars_count[cc]) {
			return 0;
		}
	}*/
	return res;
}
void Go() {
	cout << Solve();
}

int main() {
	const string task = "B";
	const string folder = "gcj/2014/1c";
	const int attempt = 0;
	const bool dbg = false;


	if (dbg) {
		freopen("inp.txt", "r", stdin);
	}
	else {
		stringstream ss;
		if (attempt < 0)
			ss << folder << '/' << task << "-large";
		else
			ss << folder << '/' << task << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	FOR(i, t) {
		printf("Case #%d: ", i + 1);
		Go();
		printf("\n");
	}
	return 0;
}