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
	string s;
	cin >> s;
	int added = 0;
	int res = 0;
	for (int i = 0; i <= n; ++i) {
		int m = (s[i] - '0');
		if (m == 0) {
			continue;
		}

		int needed = i;
		if (added >= needed) {
			added += m;
			continue;
		}
		res += needed - added;
		added = needed;
		added += m;
		continue;
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