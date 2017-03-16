#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int calculate(int n, int A, int B) {
	int a[8], k = 0, old = n;
	while (n) {
		a[k ++] = n % 10;
		n /= 10;
	}
	reverse(a, a + k);
	set < int > S;
	for (int i = 0; i < k; ++i) {
		if (a[i] != 0) {
			int m = 0;
			for (int j = i; j < i + k; ++j) {
				m = m * 10 + a[j % k];
			}
			if (old < m && m <= B) {
				S.insert(m);
			}
		}
	}
	return S.size();
}

void solve(int test) {
	int A, B;
	scanf("%d%d", &A, &B);
	int res = 0;
	for (int i = A; i <= B; ++i) {
		res += calculate(i, A, B);
	}
	printf("Case #%d: %d\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 1; i <= tests; ++i) {
		solve(i);
		cerr << i << endl;
	}
	return 0;
}