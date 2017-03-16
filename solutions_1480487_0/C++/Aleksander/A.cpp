#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

const double eps = 1e-9;

int g[205];
int n, x;

double getVal (int a, double val) {
	if (a - val > -eps)
		return 0;

	double res = (val - a) / double(x);
	return res;
}

bool good (int ind, double p) {
	int i;

	double myVal = g[ind] + p * x;

	double sumVal = p;
	for (i = 0;i < n;i++) {
		if (i != ind)
			sumVal += getVal(g[i], myVal);
	}

	return 1 - sumVal < -eps;
}

void getAns (int ind) {
	double l = 0, r = 1, mid;

	int iter = 100;
	while (iter) {
		mid = (l + r) / double(2);

		if (good(ind, mid))
			r = mid;
		else
			l = mid;

		iter--;
	}

	printf("%.12lf", l * 100);
}

void solve () {
	int i;

	scanf("%d", &n);
	x = 0;
	for (i = 0;i < n;i++) {
		scanf("%d", &g[i]);
		x += g[i];
	}

	for (i = 0;i < n;i++) {
		if (i)
			printf(" ");
		getAns(i);
	}
}

int main () {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test, t;

	scanf("%d\n", &test);
	for (t = 0;t < test;t++) {
		if (t)
			printf("\n");
		printf("Case #%d: ", t + 1);
		solve();
	}
	return 0;
}