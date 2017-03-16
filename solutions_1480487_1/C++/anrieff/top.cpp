#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

#define FOR(i,n) for (int i = 0; i < n; i++)
#define abs(x) ((x)<0?(-(x)):(x))
#define REP(i,v) for (unsigned i = 0; i < v.size(); i++)
#define RL(i,v) for (unsigned i = 0; i < v.length(); i++)
typedef long long ll;

void solve(void)
{
	double J[256];
	double p[256];
	double X = 0;
	int n;
	scanf("%d", &n);
	FOR(i, n) {
		scanf("%lf", &J[i]);
		X += J[i];
	}
	FOR(i, n) p[i] = J[i]/X;
	double l = 0, r = 2*X;
	while (r - l > 1e-12) {
		double m = (l + r) / 2.0;
		double sp = 0;
		FOR(i, n) {
			if (J[i] >= m) continue;
			double toGive = (m - J[i]) / X;
			sp += toGive;
		}
		if (sp > 1) r = m;
		else l = m;
	}
	double m = (l + r) * 0.5;
	FOR(i, n) {
		if (i) printf(" ");
		if (J[i] >= m) printf("0");
		else printf("%.9lf", (m - J[i]) / X * 100);
	}
	printf("\n");
}

int main(void)
{
	//freopen("/home/vesko/gcj/a.in", "rt", stdin);
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
