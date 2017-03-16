#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <list>
#include <iterator>
#include <functional>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

int t;

string solve() {
	char a[4][4];
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> a[i][j];
	for (int i = 0; i < 4; ++i) {
		bool hO = true;
		bool hX = true;
		for (int j = 0; j < 4; ++j) {
			if (a[i][j] == 'X' || a[i][j] == '.')
				hO = false;
			if (a[i][j] == 'O' || a[i][j] == '.')
				hX = false;
		}
		if (hO) return "O won";
		if (hX) return "X won";
	}
	for (int j = 0; j < 4; ++j) {
		bool vO = true;
		bool vX = true;
		for (int i = 0; i < 4; ++i) {
			if (a[i][j] == 'X' || a[i][j] == '.')
				vO = false;
			if (a[i][j] == 'O' || a[i][j] == '.')
				vX = false;
		}
		if (vO) return "O won";
		if (vX) return "X won";
	}
	bool dMainO = true;
	bool dMainX = true;
	for (int i = 0; i < 4; ++i) {
		if (a[i][i] == 'X' || a[i][i] == '.')
			dMainO = false;
		if (a[i][i] == 'O' || a[i][i] == '.')
			dMainX = false;
	}
	if (dMainO) return "O won";
	if (dMainX) return "X won";
	bool dSideO = true;
	bool dSideX = true;
	for (int i = 0, j = 3; i < 4; ++i, --j) {
		if (a[i][j] == 'X' || a[i][j] == '.')
			dSideO = false;
		if (a[i][j] == 'O' || a[i][j] == '.')
			dSideX = false;
	}
	if (dSideO) return "O won";
	if (dSideX) return "X won";
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (a[i][j] == '.')
				return "Game has not completed";
	return "Draw";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> t;
	for (int k = 0; k < t; ++k)
		cout << "Case #" << (k + 1) << ": " << solve() << "\n";
	return 0;
}