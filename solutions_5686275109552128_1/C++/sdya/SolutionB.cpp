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

void solve(int test) {
	int n;
	cin >> n;
	vector < int > p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	int res = 1000000000;
	for (int t = 1; t <= res; ++t) {
		vector < int > q = p;
		int current = 0;
		for (int i = 0; i < n; ++i) {
			if (q[i] <= t) {
				continue;
			}
			if (q[i] % t == 0) {
				current += (q[i] / t) - 1;
			} else {
				current += q[i] / t;
			}
		}
		res = min(res, current + t);
	}
	printf("Case #%d: %d\n", test, res);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}