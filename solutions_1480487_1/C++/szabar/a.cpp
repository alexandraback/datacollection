#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <list>
#include <stack>
#include <deque>
#include <cstdio>
#include <iostream>

using namespace std;

bool is_enough_to_overbid(double * s, int n, int wyb, double w, double pts) {
	for (int i = 0; i < n; ++i) {
		if (i != wyb) {
			double diff = max(w - s[i], 0.0);
			pts -= diff;
		}
	}
	if (pts < 0) {
		return false;
	}
	return true;
}

void cont(int c) {
	double s[1000];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int in;
		scanf("%d", &in);
		s[i] = in;
	}
	printf("Case #%d:", c);
	double res = 0;
	if (n == 1) {
		printf(" %lf", res);
		return;
	}
	int x = 0;
	for (int i = 0; i < n; ++i) {
		x += s[i];
	}

	const double eps = 0.000000001;
	for (int i = 0; i < n; ++i) {
		double curr = 1;
		if (!is_enough_to_overbid(s, n, i, s[i]+x, 0)) {
			double lb = 0;
			double rb = 1;
			curr = (rb + lb) / 2;
			do {
				if (is_enough_to_overbid(s, n, i, s[i] + x * curr, (1 - curr) * x)) {
					lb = curr;
				} else {
					rb = curr;
				}
				curr = (rb + lb) / 2;
			} while (rb - lb > eps);
		}
		curr *= 100;
		printf(" %.7lf", curr);
	}
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		cont(i + 1);
	}
}
