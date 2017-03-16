#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

void work(int id) {
	int A, B;
	cin >> A >> B;

	int ans = 0;
	for (int x = A; x <= B; ++x) {
		int ds[10], p = 0;
		int t = x;
		while (x)
			ds[p++] = x % 10, x /= 10;
		x = t;
		reverse(ds, ds + p);

		set<int> have;

		for (int i = 1; i < p; ++i) {
			rotate(ds, ds + 1, ds + p);
			if (ds[0] > 0) {
				int y = 0;
				for (int j = 0; j < p; ++j) {
					y = y * 10 + ds[j];
				}
				if (y < x && y >= A)
					have.insert(y);
			}
		}

		ans += have.size();
	}

	printf("Case #%d: %d\n", id, ans);
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		work(i);
	}
	return 0;
}
