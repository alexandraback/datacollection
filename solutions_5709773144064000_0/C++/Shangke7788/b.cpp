#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

double C, F, X;

int main() {
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		double ans = 1e200;
		scanf("%lf%lf%lf", &C, &F, &X);
		int n = ceil(X / C);
		double now = 0.0;
		for (int i = 0; i <= n; i++) {
			ans = min(ans, now + X / (i * F + 2.0));
			now += C / (i * F + 2.0);
		}
		printf("Case #%d: %.9lf\n", ca, ans);
	}
	return 0;
}
