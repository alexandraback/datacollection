#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>

using namespace std;

int n;
double a[500];

void solve(int testcase) {
	printf("Case #%d: ", testcase);
	scanf("%d", &n);

	double sum = 0;

	for (int i = 0; i < n; ++i) {
		scanf("%lf", &a[i]);
		sum += a[i];
	}
	
	for (int i = 0; i < n; ++i) {
		double l = 0, r = 1;
		for (int iter = 0; iter < 100; ++iter) {
			double key = (l + r) / 2;

			double cursum = key;
			double val = a[i] + sum * key;
			for (int j = 0; j < n; ++j) {
				if (i != j) {
					double add = 0;
					double val2 = val - a[j];
					if (val2 > 0) {
						val2 /= sum;
						add = val2;
					}
					cursum += add;
				}
			}
			if (cursum > 1) {
				r = key;
			} else {
				l = key;
			}
		}
		double ans = (l + r) / 2.;
		printf(" %.10lf", ans * 100.);
	}
	printf("\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;

	for (int t = 1; t <= tests; ++t) {
		solve(t);
	}

	return 0;
}