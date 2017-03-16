#include <iostream>
#include <algorithm>
#include <assert.h>
#include <cstring>
#include <stdio.h>
#include <math.h>
#include <string>
#include <vector>
#include <time.h>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

////////////////////////////////////////////////////////////////////////////////
#define mp make_pair
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	for (int k1 = 0; k1 < k; ++k1) {
		cout << "Case #" << k1 + 1 << ": ";
		int b;
		cin >> b;
		vector<vector<int>> answ(b, vector<int>(b, 0));
		int m;
		cin >> m;
		if (m > (1 << (b - 2))) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}

		cout << "POSSIBLE" << endl;
		for (int i = 1; i < b - 1; ++i) {
			for (int j = i + 1; j < b; ++j) {
				answ[i][j] = 1;
			}
		}

		for (int j = 1; j < b; ++j) {
			if (!m) {
				break;
			}
			else {
				if (j == b - 1) {
					--m;
					answ[0][j] = 1;
				}
				else {
					if (m >= (1 << (b - (j + 2)))) {
						m -= 1 << (b - (j + 2));
						answ[0][j] = 1;
					}
				}
			}
		}

		for (int i = 0; i < b; ++i) {
			for (int j = 0; j < b; ++j) {
				cout << answ[i][j];
			}
			cout << endl;
		}
	}
}