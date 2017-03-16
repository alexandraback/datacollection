/*
 * Author: rush
 * Filename: B.cpp
 * Timestamp: 06/05/2012 18:50:18 CST
 */
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define SZ(x) ((int)x.size())
#define FOR(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long LL;

int T, N, A;
double D, t[2005], x[2005];
double a[2005];

double gao(double a, double b, double c) {
	double delta = b * b - 4.0 * a * c;
	return (-b + sqrt(delta)) / (2.0 * a);
}

int main() {
	scanf("%d", &T);
	for (int id = 1; id <= T; ++id) {
		scanf("%lf%d%d", &D, &N, &A);
		FOR(i, N) scanf("%lf%lf", &t[i], &x[i]);
		FOR(i, A) scanf("%lf", &a[i]);
		
		printf("Case #%d:\n", id);
		if (N == 1) {
			FOR(i, A) {
				double ans = sqrt(2.0 * D / a[i]);
				printf("%.9f\n", ans);
			}
		} else if (N == 2) {
			FOR(i, A) {
				double ans = sqrt(2.0 * D / a[i]);
				double v = (x[1] - x[0]) / (t[1] - t[0]);
				double t = gao(0.5 * a[i], -v, -x[0]);
				if (t < ans) {
					ans = t + (D - (x[0] + v * t)) / v;
				}
				printf("%.9f\n", ans);
			}
		}
	}
	return 0;
}
