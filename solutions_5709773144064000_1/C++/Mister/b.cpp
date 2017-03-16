#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		double ans = x / 2;
		for (int n = 0;; ++n) {
			double add = x / (2 + (n + 1) * f) - (x - c) / (2 + n * f);
			if (add >= 0) break;
			ans += add;
		}
		printf("Case #%d: %.7lf\n", cn, ans);
	}
}

