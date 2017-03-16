#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 500 + 10;

void work() {
	int n;
	int a[MAX_N];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	static pair<int, int> ps[1 << 20];

	for (int mask = 0; mask < 1 << n; ++mask) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (mask >> j & 1)
				sum += a[j];
		}
		ps[mask] = make_pair(sum, mask);
	}

	sort(ps, ps + (1 << n));

	for (int i = 0; i + 1 < (1 << n); ++i) {
		if (ps[i].first == ps[i + 1].first) {
			int A = ps[i].second;
			int B = ps[i + 1].second;
			int com = A & B;
			A ^= com;
			B ^= com;

			for (int j = 0; j < n; ++j) {
				if (A >> j & 1)
					cout << a[j] << " ";
			}
			cout << endl;
			for (int j = 0; j < n; ++j) {
				if (B >> j & 1)
					cout << a[j] << " ";
			}
			cout << endl;
			return;
		}
	}
	puts("Impossible");
}

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		printf("Case #%d:\n", i + 1);
		work();
	}
	return 0;
}
