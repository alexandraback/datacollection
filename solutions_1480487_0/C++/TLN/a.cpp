/*
 * a.cpp
 *
 */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

bool enough(vector<int> &score, int sum, int i, double p) {
	double lower = score[i] + sum * p;
	double q = 0;
	forn(j, score.size()) {
		if (i == j)
			continue;
		if (score[j] < lower)
			q += (lower - score[j]) / sum;
	}
	//printf("limit: %lf, %lf \n", p, q);
	return (q >= 1 - p);
}

void solve(vector<int> &score) {
	int sum = 0;
	forn(i, score.size())
		sum = sum + score[i];
	forn(i, score.size()) {
		double p1 = 0, p2 = 1;
		while (p2 - p1 > 1e-8) {
			double p = (p1 + p2) / 2;
			if (enough(score, sum, i, p))
				p2 = p;
			else
				p1 = p;
		}
		printf(" %.6lf", p2 * 100);
	}
}

int main(void) {
	int t;
	cin >> t;
	for (int c = 1; c <= t; ++c) {
		int n;
		cin >> n;
		vector<int> score(n);
		forn(i, n)
			cin >> score[i];
		printf("Case #%d:", c);
		solve(score);
		printf("\n");
	}
	return 0;
}
