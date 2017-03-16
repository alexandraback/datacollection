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



bool check(const vvi& a) {
	for (int h = 100; h >= 1; --h) {
		vvi can(sz(a), vi(sz(a[0]), 0));

		for (int i = 0; i < sz(a); ++i) {
			bool ok = true;
			for (int j = 0; j < sz(a[i]); ++j) {
				if (a[i][j] > h) {
					ok = false;
					break;
				}
			}

			if (ok) {
				for (int j = 0; j < sz(a[i]); ++j) {
					can[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < sz(a[0]); ++i) {
			bool ok = true;
			for (int j = 0; j < sz(a); ++j) {
				if (a[j][i] > h) {
					ok = false;
					break;
				}
			}

			if (ok) {
				for (int j = 0; j < sz(a); ++j) {
					can[j][i] = 1;
				}
			}
		}

		for (int i = 0; i < sz(a); ++i) {
			for (int j = 0; j < sz(a[i]); ++j) {
				if (a[i][j] == h && !can[i][j]) {
					return false;
				}
			}
		}
	}
	return true;
}


void solve() {
	int n, m;
	cin >> n >> m;
	vvi a(n, vi(m, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	if (check(a)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
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

