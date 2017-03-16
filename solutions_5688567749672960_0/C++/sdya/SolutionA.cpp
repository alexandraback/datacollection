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

const int maxN = 1100000;
int d[maxN];

int trivial(int n) {
	d[1] = 1;
	for (int i = 2; i <= n; ++i) {
		d[i] = d[i - 1] + 1;
		int v = rev(i);
		if (v < i && rev(v) == i) {
			d[i] = min(d[i], d[v] + 1);
		}
	}
	return d[n];
}

long long greedy(long long n) {
	long long res = 1;
	while (n != 1) {
		long long x = n - 1;
		long long y = rev(n);

		long long t = min(x, y);
		++res;
		n = t;
	}
	return res;
}

void solve(int test) {
	int n;
	cin >> n;
	printf("Case #%d: %d\n", test, (int)(trivial(n)));
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	/*long long x;
	while (true) {
		cin >> x;
		cout << trivial(x) << endl;
		cout << greedy(x) << endl;
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