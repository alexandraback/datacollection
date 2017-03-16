#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>
#include <deque>
#include <string.h>


using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

typedef long long int64;

typedef vector <int> vi;
typedef vector <vi> vvi;

typedef vector<string> vs;

bool check(const string& s, char c) {
	for (int i = 0; i < sz(s); ++i) {
		if (!(s[i] == c || s[i] == 'T')) {
			return false;
		}
	}
	return true;
}

bool check(const vs& f, char c) {
	for (int i = 0; i < 4; ++i) {
		if (check(f[i], c)) {
			return true;
		}
	}

	for (int i = 0; i < 4; ++i) {
		string s;
		for (int j = 0; j < 4; ++j) {
			s.pb(f[j][i]);
		}
		if (check(s, c)) {
			return true;
		}
	}

	{
		string s;
		for (int j = 0; j < 4; ++j) {
			s.pb(f[j][j]);
		}
		if (check(s, c)) {
			return true;
		}
	}
	{
		string s;
		for (int j = 0; j < 4; ++j) {
			s.pb(f[j][3 - j]);
		}
		if (check(s, c)) {
			return true;
		}

	}
	return false;
}

bool hasEmpty(const vs& f) {
	for (int i = 0; i < sz(f); ++i) {
		for (int j = 0; j < sz(f[i]); ++j) {
			if (f[i][j] == '.') {
				return true;
			}
		}
	}
	return false;
}

void solve() {
	vs f(4);
	for (int i = 0; i < 4; ++i) {
		string t;
		while (t.empty()) {
			cin >> t;
		}
		f[i] = t;
	}

	if (check(f, 'X')) {
		cout << "X won" << endl;
	} else if (check(f, 'O')) {
		cout << "O won" << endl;
	} else {
		if (hasEmpty(f)) {
			cout << "Game has not completed" << endl;
		} else {
			cout << "Draw" << endl;
		}
	}
}

int main () {
	//freopen("", "rt", stdin);
	//freopen("", "wt", stdout);
	//std::ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";
		solve();
	}

    return 0;
}

