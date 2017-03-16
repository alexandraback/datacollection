#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <numeric>

using namespace std;

#define INF (2000000000)

const int nmax = 1 << 10;
const double eps = 1e-12;

int s[nmax];
int S;
int n;

double t[nmax];

bool good(int i, double x) {

	double g = s[i] + x * S;

	x = 1 - x;

	for(int j = 0; j < n; ++j) {
		
		if (j == i) {
			t[j] = g;
			continue;
		}

		double y = (g - s[j]) / S;

		if (y < 0) {
			continue;
		}

		if (y > x) {
			return true;
		}

		x -= y;

	}

	return abs(x) < eps;

}

double f(int i) {

	double L = 0.0, R = 1.0, M;

	for(int j = 0; j < 60; ++j) {

		M = (L + R) * 0.5;

		if (good(i, M)) {
			R = M;
		} else {
			L = M;
		}

	}

	return L;

}

void solveTest() {

	S = 0;

	for(int i = 0; i < n; ++i) {
		S += s[i];
	}

	for(int i = 0; i < n; ++i) {
		printf(" %.7lf", f(i) * 100);
	}
	puts("");

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("A.in", "rt", stdin);
	freopen("A.out", "wt", stdout);
#endif
	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt) {
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &s[i]);
		}
		printf("Case #%d:", tt + 1);
		solveTest();
		cerr << "Case " << tt + 1 << " done\n";
	}
	return 0;
}