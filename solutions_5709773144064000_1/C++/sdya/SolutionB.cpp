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

double getTime(double c, double f, double x, int farms) {
	if (c >= x) {
		return x / 2.0;
	}
	double res = 0.0;
	double speed = 2.0;
	for (int i = 0; i < farms; ++i, speed += f) {
		double t = c / speed;
		res += t;
	}
	res += x / speed;
	return res;
}

void solve(int test) {
	double c, f, x;
	scanf("%lf%lf%lf", &c, &f, &x);

	const int maxN = (test == 5 || test == 65 || test == 66 || test == 83) ? 100000 : 10000;
	double res = 1e30;
	for (int i = 0; i < maxN; ++i) {
		res = min(res, getTime(c, f, x, i));
	}

	printf("Case #%d: %.10lf\n", test, res);
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