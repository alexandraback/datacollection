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

int dp[1 << 20];
int n, k;
int p[20];
vector < int > a[20];

int calc(int mask, const vector < int > &start) {
	if (dp[mask] != -1) {
		return dp[mask];
	}
	if (mask == 0) {
		return dp[mask] = 1;
	}

	vector < int > current = start;
	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			--current[p[i]];
			for (int j = 0; j < a[i].size(); ++j) {
				++current[a[i][j]];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
			++current[p[i]];
			for (int j = 0; j < a[i].size(); ++j) {
				--current[a[i][j]];
			}

			if (current[p[i]] > 0 && calc(mask ^ (1 << i), start)) {
				return dp[mask] = 1;
			}

			--current[p[i]];
			for (int j = 0; j < a[i].size(); ++j) {
				++current[a[i][j]];
			}
		}
	}
	return dp[mask] = 0;
}

bool check(int mask, const vector < int > &start) {
	memset(dp, -1, sizeof(dp));
	return calc(mask, start);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		cerr << test << endl;
		vector < int > start(201, 0);
		cin >> k >> n;
		for (int i = 0; i < k; ++i) {
			int value;
			cin >> value;
			++start[value];
		}
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			int m;
			cin >> m;
			a[i].resize(m);
			for (int j = 0; j < m; ++j) {
				cin >> a[i][j];
			}
		}

		vector < int > res;
		vector < int > used(n, false);
		int mask = (1 << n) - 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (used[j]) {
					continue;
				}

				if (start[p[j]] == 0) {
					continue;
				}

				--start[p[j]];
				for (int l = 0; l < a[j].size(); ++l) {
					++start[a[j][l]];
				}

				if (check(mask ^ (1 << j), start)) {
					used[j] = true;
					mask ^= (1 << j);
					res.push_back(j + 1);
					break;
				} else {
					++start[p[j]];
					for (int l = 0; l < a[j].size(); ++l) {
						--start[a[j][l]];
					}
				}
			}
			if (res.size() != i + 1) {
				break;
			}
		}

		cout << "Case #" << test << ":";
		if (res.size() != n) {
			cout << " IMPOSSIBLE" << endl;
		} else {
			for (int i = 0; i < n; ++i) {
				cout << " " << res[i];
			}
			cout << endl;
		}
	}
	return 0;
}