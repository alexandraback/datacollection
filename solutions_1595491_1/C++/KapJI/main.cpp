#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int n, s, p;

void solve() {
	scanf("%d%d%d", &n, &s, &p);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		int dm = x / 3 + (x % 3 > 0);
		if (dm >= p) {
			ans++;
		} else {
			int m = x % 3;
			switch (m) {
				case 0: {
					dm = (x - 3) / 3 + 2;
					break;
				}
				case 1: {
					dm = (x - 4) / 3 + 2;
					break;
				}
				case 2: {
					dm = (x - 2) / 3 + 2;
					break;
				}
			}
			if (x >= 2 && dm >= p && s > 0) {
				s--;
				ans++;
			}
		}
	}
	printf("%d", ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();	
		cout << endl;
	}
	return 0;
}
