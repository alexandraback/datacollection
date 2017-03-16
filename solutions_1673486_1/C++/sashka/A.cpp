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

const int nmax = 100100;

double p[nmax];
double d[nmax][2];
double a[nmax][2];
int n, m;

void solveTest() {

	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; ++i) {
		scanf("%lf", &p[i]);
	}

	d[0][0] = 1.0;
	d[0][1] = 0.0;

	for(int i = 0; i < m; ++i) {
		d[i + 1][0] = d[i][0] * p[i];
		d[i + 1][1] = d[i][0] * (1 - p[i]) + d[i][1];
	}

	double ans = d[0][0] * (n + 2);

	for(int i = 1; i <= m; ++i) {
		double s1 = d[i][0] * (m - i + n - i + 1);
		double s2 = d[i][1] * (m - i + n - i + n + 2);
		ans = min(ans, s1 + s2);
	}

	printf("%.9lf", ans);

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
		printf("Case #%d: ", tt + 1);
		solveTest();
		puts("");
		cerr << "Case " << tt + 1 << " done\n";
	}
	return 0;
}