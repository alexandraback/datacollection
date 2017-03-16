#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int a[200][200];
int n, m;

void Update(int current) {
	set < int > rows;
	for (int i = 0; i < n; ++i) {
		bool nice = true;
		for (int j = 0; j < m; ++j) {
			nice &= (a[i][j] == current);
		}
		if (nice) {
			rows.insert(i);
		}
	}
	set < int > columns;
	for (int i = 0; i < m; ++i) {
		bool nice = true;
		for (int j = 0; j < n; ++j) {
			nice &= (a[j][i] == current);
		}
		if (nice) {
			columns.insert(i);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (rows.count(i) != 0 || columns.count(j) != 0) {
				a[i][j] = current + 1;
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= 100; ++i) {
			Update(i);
		}

		bool yes = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				yes &= (a[i][j] > 100);
			}
		}

		cout << "Case #" << test << ": ";
		if (yes) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}