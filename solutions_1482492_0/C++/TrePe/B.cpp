#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

int i, j, k, kejsis, kejs, n, A;
double D, t[2000], x[2000], a[250];
double ret;

double getPosOther(double tt) {
	int i;
	for (i = 0; i < n-1; i++) {
		if (t[i]-1e-9 < tt && tt < t[i+1]+1e-9) {
			return x[i]+(tt-t[i])/(t[i+1]-t[i])*(x[i+1]-x[i]);
		}
	}
	return 1e123;
}

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d:\n", kejs);
		scanf("%lf%d%d", &D, &n, &A);
		for (i = 0; i < n; i++) scanf("%lf%lf", &t[i], &x[i]);
		for (i = 0; i < A; i++) scanf("%lf", &a[i]);
		for (k = 0; k < A; k++) {
			if (n == 1) {
				ret = sqrt(D / (0.5*a[k]));
			}
			if (n == 2) {
				ret = sqrt(D / (0.5*a[k]));
				if (getPosOther(ret) < D - 1e-9) { // blocking us
					ret = t[1] * (D - x[0])/(x[1]-x[0]);
				}	
			}
			printf("%.10lf\n", ret);
		}
	}
	return 0;
}
