//============================================================================
// Name        : cj_130427_A.cpp
// Author      : huangxs139
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

double r, t;
double x;
double tmp;
long long ans;

int main() {
	int T;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%lf%lf", &r, &t);
		x = 2*r-1;
		tmp = 2*t/(sqrt(x*x+8*t)+x);
		//printf("%lf ", tmp);
		ans = (long long)tmp;
		//printf("%I64d\n", ans);
		if (ans > tmp)
			ans--;
		printf("Case #%d: ", cas);
		cout << ans << endl;
	}
	return 0;
}
