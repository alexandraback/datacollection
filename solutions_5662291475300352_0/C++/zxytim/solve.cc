/*
 * $File: solve.cc
 * $Date: Sun May 03 01:05:01 2015 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */


#include <cassert>
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

struct Point {
	double x, y;
	Point(double x=0, double y=0): x(x), y(y) {}
};
struct Line {
	double b, k;
	Line(double k=0, double b=0): b(b), k(k) {}
	bool operator < (const Line &o) const {
		if (k != o.k)
			return k < o.k;
		return b < o.b;
	}

	Point intersect(const Line &o) {
		double x = (o.b - b) / (k - o.k),
			   y = k * x + b;
		return Point(x, y);
	}
};
ll solve(FILE *fin) {
	int N;
	fscanf(fin, "%d", &N);
	std::vector<Line> a;
	for (int i = 0; i < N; i ++) {
		double D, H, M;
		fscanf(fin, "%lf%lf%lf", &D, &H, &M);
		for (int j = 0; j < H; j ++)
			a.push_back(Line(M + j, D));
	}
	std::sort(a.begin(), a.end());
	if (a.size() == 1)
		return 0;
	assert(a.size() == 2);
	Point p = a[0].intersect(a[1]);
	a[1] = Line(a[1].k, -a[1].k * a[1].intersect(Line(0, 360)).x);
	if (a[0].intersect(a[1]).y <= 360)
		return 1;
	return 0;
}

int main() {
	int T;
	FILE *fin = stdin;
	fscanf(fin, "%d", &T);
	for (int case_id = 1; case_id <= T; case_id ++) {
		std::cout << "Case #" << case_id << ": " << solve(fin) << std::endl;
	}
	return 0;
}


/*
 * vim: syntax=cpp11.doxygen foldmethod=marker foldmarker=f{{{,f}}}
 */
