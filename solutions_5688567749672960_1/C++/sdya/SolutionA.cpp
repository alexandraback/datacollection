#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

long long rev(long long n) {
	long long m = 0;
	while (n) {
		m = m * 10 + (n % 10);
		n /= 10;
	}
	return m;
}

const int maxN = 11000000;
int d[maxN], p[maxN];

int trivial(int n) {
	d[1] = 1;
	for (int i = 2; i <= n; ++i) {
		d[i] = d[i - 1] + 1;
		p[i] = i - 1;
		int v = rev(i);
		if (v < i && rev(v) == i) {
			if (d[v] + 1 < d[i]) {
				d[i] = d[v] + 1;
				p[i] = v;
			}
		}
	}
	return d[n];
}

void path(int n) {
	int v = n;
	while (v != 1) {
		printf("%d ", v);
		v = p[v];
	}
	printf("\n");
}

int getDigits(long long n) {
	int res = 0;
	while (n) {
		++res;
		n /= 10;
	}
	return res;
}

long long clever(long long n) {
	if (n == 1) {
		return 1;
	}

	long long d = getDigits(n);

	long long p = (d + 1) / 2;

	long long pw = 1LL;
	for (int i = 0; i < p; ++i) {
		pw *= 10LL;
	}

	long long m = n / pw;
	long long a = m * pw + 1;
	if (a <= n) {
		if (rev(a) < a) {
			return clever(rev(a)) + 1LL + n - a;
		}
		if (a + 1 <= n) {
			return clever(a) + n - a;
		}
	}
	return clever(n - 1) + 1LL;
}

void solve(int test) {
	long long n;
	cin >> n;
	//printf("Case #%d: %d\n", test, (int)(trivial(n)));
	printf("Case #%d: ", test);
	cout << clever(n) << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	/*trivial(10000000);

	for (int i = 1; ; ++i) {
		if (i % 100 == 0) {
			cerr << i << endl;
		}
		if (d[i] != clever(i)) {
			cout << i << endl;
			cout << d[i] << endl;
			path(i);
			cout << clever(i) << endl;
			return 0;
		}
	}*/

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}