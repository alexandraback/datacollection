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
#include <numeric>

using namespace std;

#define sqr(a) ((a)*(a))
#define two(a) (1 << (a))
#define has(mask, a) ((mask) & two(a) ? 1 : 0)

double c, f, x;

void load() {
	cin >> c >> f >> x;
}

double go (int k) {
	double cur = 0;
	double pr = 2;

	while (k > 0) {
		cur += c / pr;
		pr += f;
		k--;
	}

	return cur + x / pr;
}

void solve(int test) {
	int l = 0, r = 1e6;
	while (r - l > 1) {
		int mid = (l + r) / 2;

		if (go (mid) < go (mid + 1)) {
			r = mid;
		} else {
			l = mid;
		}
	}

	printf ("Case #%d: %.7lf\n", test, min (go (l), go (l + 1)));
}

int main() {
 	freopen ("a.in", "r", stdin);

 	int t;
 	scanf ("%d\n", &t);

 	for (int i = 1;i <= t;i++) {
 		load();
 		solve(i);
 	}

 	return 0;
}