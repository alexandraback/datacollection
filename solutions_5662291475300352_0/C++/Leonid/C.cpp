#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("C-small-1-attempt0.in", "rt", stdin);
	freopen("C-small-1-attempt0.out", "wt", stdout);
#endif
}

const double EPS = 1e-7;

bool equal(double a, double b) {
	if (b > a - EPS && b < a + EPS) return true;
	else return false;
}

void solve() {
	int n; scanf("%d ", &n);
	vector<int> d(n), h(n), m(n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d ", &d[i], &h[i], &m[i]);
	}
	/* Just follow the hiker. */
	if (n == 1 && h[0] == 1) {
		printf("0\n");
		return;
	}

	double p0, p1, v0, v1;
	if (n == 2) {
		p0 = d[0], p1 = d[1];
		v0 = 360.0 / m[0], v1 = 360.0 / m[1];
		if (p0 < p1) {
			/* First hiker is upfront. */
			swap(p0, p1);
			swap(v0, v1);			
		}
	} else {
		p0 = d[0], p1 = d[0];
		v0 = 360.0 / m[0], v1 = 360.0 / (m[0] + 1.0);
	}

	/* Equal speeds. */
	if (equal(v0, v1)) {
		printf("0\n");
		return;
	}

	/* Second is faster. */
	if (v0 < v1) {
		/* Follow the second, just until they align. */
		double tx = (p1 - p0) / (v0 - v1);
		double p = p0 + v0 * tx;
		p0 = p, p1 = p;
	}

	/* Make first one faster. */
	if (v0 < v1) {
		swap(v0, v1);
		swap(p0, p1);
	}

	/* Calculate next time they will meet up. */
	double t = 360.0 / (v0 - v1);
	p1 = p1 + t * v1;
	if (p1 < 360.0 + EPS) {
		printf("1\n");
	} else {
		printf("0\n");
	}
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        printf("Case #%d: ", i + 1);
        solve();
    }
    return 0;
}
