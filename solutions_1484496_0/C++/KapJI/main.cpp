#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

const int ITERS = 100;
const double EPS = 1e-12;

int n;
bool found;
vector<int> a, b;

void gen(int l) {
	if (l == n) {
		int sum1 = 0, sum2 = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; ++i) {
			if (b[i] == 1) {
				sum1 += a[i];
				cnt1++;
			}
			if (b[i] == 2) {
				sum2 += a[i];
				cnt2++;
			}
		}
		if (sum1 == sum2 && cnt1 > 0 && cnt2 > 0) {
			found = true;
			for (int i = 0; i < n; ++i) {
				if (b[i] == 1) {
					printf("%d ", a[i]);
				}
			}
			printf("\n");
			for (int i = 0; i < n; ++i) {
				if (b[i] == 2) {
					printf("%d ", a[i]);
				}
			}
			printf("\n");
		}
		return;
	}
	for (int i = 0; i < 3; ++i) {
		b[l] = i;
		gen(l + 1);
		if (found) {
			return;
		}
	}
}

void solve() {
	scanf("%d", &n);
	a.resize(n);
	found = false;
	b.assign(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	gen(0);
	if (!found) {
		printf("Impossible\n");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d:\n", i + 1);
		solve();
	}
	return 0;
}
