#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;

	cin >> t;

	int f = 0;

	while (t--) {
		f++;
		cout << "Case #" << f << ": ";

		ll k, c, s;

		cin >> k >> c >> s;

		if (c == 1) {
			if (s != k) {
				cout << "IMPOSSIBLE" << endl;
				continue;
			} else {
				for (int i = 1; i <= s; i++) {
					cout << i << ' ';
				}
				cout << endl;
				continue;
			}
		}

		ll a = 1;

		for (int i = 1; i < c; i++) {
			a = a * k;
		}

		ll f = a * k;
		ll pos = 2;
		vector <ll> ans;

		while (pos <= f) {
			ans.push_back(pos);
			pos += 2 * a;
			pos += 2;
		}

		if (pos == f + 1) {
			ans.push_back(pos - 1);
		}

		if ((int)ans.size() > s) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			for (int i = 0; i < (int)ans.size(); i++) {
				cout << ans[i] << ' ';
			}
			cout << endl;
		}
	}

	return 0;
}
