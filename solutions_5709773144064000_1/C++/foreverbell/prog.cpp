#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <cassert>

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

using namespace std;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt <= tests; ++tt) {
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		double sum = 0, last = 1e100;
		for (int n = 0; ; ++n) {
			double cur = X / (2 + n * F) + sum;
			if (cur < last) {
				last = cur;
			} else break;
			sum += C / (2 + n * F);
		}
		printf("Case #%d: ", tt);
		printf("%.20f\n", last);
	}
	return 0;
}
