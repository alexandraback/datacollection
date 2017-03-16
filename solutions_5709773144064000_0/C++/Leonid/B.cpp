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
	freopen("B-small-attempt0.in", "rt", stdin);
	//freopen("test.out", "wt", stdout);
#endif
}

void solve() {
	double c, f, x;
	scanf("%lf %lf %lf ", &c, &f, &x);
	double best = x / 2;
	double curtime = 0.0, currate = 2;
	for (int i = 1; i <= 20000000; i++) {
		curtime += c / currate;
		currate += f;
		best = min(best, curtime + x / currate);
	}
	static int ntest = 0;
	printf("Case #%d: %.7lf\n", ++ntest, best);
}


int main() {
	openFiles();
	int n; scanf("%d ", &n);
	for (int i = 0; i < n; i++) solve();

	return 0;
}
