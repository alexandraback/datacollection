#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int g[7][7];
int c[7];

int b, m;

pair<int, int> next_(int i, int j) {
	if (j == b - 1) {
		i++;
		j = i + 1;
	}
	else {
		j++;
	}

	return make_pair(i, j);
}

int count(int i) {
	if (i >= b - 1) {		
		return 1;
	}

	if (c[i] != -1) {
		return c[i];
	}

	int res = 0;
	for (int j = i + 1; j < b; j++) {
		if (g[i][j]) {
			res += count(j);
		}
	}

	c[i] = res;
	return res;
}

int found(int i, int j) {
	if (i >= b - 1 && j >= b - 1) {
		int res = (count(0) == m);

		for (int k = 0; k < 7; k++) {
			c[k] = -1;
		}

		return res;
	}

	for (int v = 0; v < 2; v++) {
		g[i][j] = v;
		auto u = next_(i, j);
		int res = found(u.first, u.second);
		if (res) {
			return true;
		}
	}

	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		cout << "Case #" << test << ": ";

		cin >> b >> m;

		for (int i = 0; i < 7; i++) {
			c[i] = -1;
		}

		if (found(0, 1)) {
			cout << "POSSIBLE" << endl;
			for (int i = 0; i < b; i++) {
				for (int j = 0; j < b; j++) {
					cout << g[i][j];
				}
				cout << endl;
			}
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
}