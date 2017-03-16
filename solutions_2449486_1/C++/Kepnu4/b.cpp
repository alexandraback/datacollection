#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <ctime>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

int n, m, a[105][105];

void load() {
	scanf ("%d%d", &n, &m);

	for (int i = 0;i < n;i++) {
	 	for (int j = 0;j < m;j++) {
	 	 	scanf ("%d", &a[i][j]);
	 	}
	}
}

void solve(int test) {
	for (int i = 0;i < n;i++) {
	 	for (int j = 0;j < m;j++) {
	 	 	bool ok1 = true, ok2 = true;

	 	 	for (int k = 0;k < m;k++) {
	 	 	 	if (a[i][k] > a[i][j]) ok1 = false;
	 	 	}

	 	 	for (int k = 0;k < n;k++) {
	 	 	 	if (a[k][j] > a[i][j]) ok2 = false;
	 	 	}

	 	 	if (!ok1 && !ok2) {
	 	 	 	printf ("Case #%d: NO\n", test);
	 	 	 	return;
	 	 	}
	 	}
	}
	printf ("Case #%d: YES\n", test);
}

int main() {
 	freopen ("a.in", "r", stdin);
 	freopen ("a.out", "w", stdout);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}