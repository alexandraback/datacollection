#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <bitset>
#include <ctime>

using namespace std;

void solve(int test) {
	printf("Case #%d:", test);
	long long k, c, s;
	cin >> k >> c >> s;
	if (s * c < k) {
		cout << " IMPOSSIBLE" << endl;
		return;
	}
	vector < bool > used(k, false);
	for (int i = 0; i < s; ++i) {
		long long res = 0;
		for (int j = 0; j < c; ++j) {
			bool nice = false;
			for (int x = 0; x < k; ++x) {
				if (!used[x]) {
					res = res * k + (long long)(x);
					used[x] = true;
					nice = true;
					break;
				}
			}
			if (!nice) {
				res = res * k;
			}
		}
		cout << " " << res + 1;
		if (count(used.begin(), used.end(), true) == k) {
			break;
		}
	}
	cout << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		solve(i + 1);
		cerr << i + 1 << ": " << clock() << endl;
	}
	return 0;
}