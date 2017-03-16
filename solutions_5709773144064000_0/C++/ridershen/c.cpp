#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

double C, F, X;

double solve() {
	double t = 0;
	int n = 0;
	double t1 = X/(n*F+2);
	double t2 = X/((n+1)*F+2) + C/(n*F+2);
	while (t1 > t2) {
		t += C/(n*F+2);
		++n;
		t1 = X/(n*F+2);
		t2 = X/((n+1)*F+2) + C/(n*F+2);
	}
	return t+t1;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		scanf("%lf", &C);
		scanf("%lf", &F);
		scanf("%lf", &X);
		double r = solve();
		printf("Case #%d: ", i+1);
		if (r > 0) {
			printf("%.7f\n", r);
		}
	}
	return 0;
}