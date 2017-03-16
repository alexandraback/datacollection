#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <cstring>
#include <cassert>
#include <ctime>
#include <climits>
#include <bitset>

using namespace std;

int n, t, c, d, v, can[100], a[100], ans;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int jj = 1; jj <= t; jj++) {
		cin >> c >> d >> v;
		ans = 0;
		for (int i = 0; i <= v; i++) {
			can[i] = 0;
		}
		can[0] = 1;
		for (int i = 0; i < d; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < d; i++) {
			for (int j = v; j >= 0; j--) {
				if (can[j]) {
					can[j + a[i]] = 1;
				}
			}
		}
		for (int i = 1; i <= v; i++) {
			if (can[i] == 0) {
				ans++;
				for (int j = v; j >= 0; j--) {
					if (can[j]) {
						can[j + i] = 1;
					}
				}
			}
		}
		cout << "Case #" << jj << ": " << ans << endl;
	}

	return 0;
}