#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

double solve(double C, double F, double X) {
	double ret = X / 2.0;
	double base = 0.;
	for (int i = 0; true; ++i) {
		base += C / (2.0 + i * F);
		double t = base + X / (2.0 + (i + 1) * F);
		if (t < ret) {
			ret = t;
		}
		else {
			break;
		}
	}
	return ret;
}

int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		printf("Case #%d: ", cas);
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);
		printf("%.7f\n", solve(C, F, X));
	}
	return 0;
}
