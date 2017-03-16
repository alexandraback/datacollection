
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <sstream>
#include <iostream>
#include <string>
#include <functional>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int n, X, sbj, J[222];
double sbj_score;

bool f (int u, double frac) //sbj can be lowest score?
{
	if (u == n)	return true;
	if (u == sbj) return f (u + 1, frac);
	else{
		double le = 0.0, ri = 1.0;
		for (int i = 0; i < 100; i ++){
			double mid = (le + ri) / 2;
			if (J[u] + X*mid > sbj_score) ri = mid;
			else le = mid;
		}
		if (frac - le >= 0)
			return f (u + 1, frac - le);
		else return false;
	}
}

int
main ()
{
	freopen ("As.in","r",stdin);
	freopen ("As.out","w",stdout);
	int t;
	scanf ("%d", &t);
	for (int tc = 1; tc <= t; tc ++){
		scanf ("%d", &n);
		for (int i = 0; i < n; i ++)
			scanf ("%d", &J[i]);

		printf ("Case #%d: ", tc);
		X = accumulate (J, J + n, 0);
		for (int i = 0; i < n; i ++){
			double le = 0.0, ri = 1.0;
			for (int j = 0; j < 100; j ++){
				double mid = (le + ri) / 2;
				sbj = i;
				sbj_score = J[i] + X*mid;
				if (f (0, 1.0 - mid)) le = mid;
				else ri = mid;
			}
			printf ("%.6lf ", le * 100);
		}
		puts ("");
	}
	return 0;
}
