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

int A, n, a[105], sum[105];

void load() {
	cin >> A >> n;

	for (int i = 0;i < n;i++) {
	 	cin >> a[i];
	}
	sort (a, a + n);
}

void solve(int test) {
	int ans = n;
	int cur = 0;

	if (A > 1) {
	for (int i = 0;i < n;i++) {
	 	while (A <= a[i]) {
	 	 	cur++;
	 	 	A += A - 1;
	 	}
	 	A += a[i];
	 	ans = min (ans, cur + n - i - 1);
	}
	}

	printf ("Case #%d: %d\n", test, ans);
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