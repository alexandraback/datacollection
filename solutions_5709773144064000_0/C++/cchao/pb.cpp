#include <cstdio>
#include <iostream>
using namespace std;
double c, f, x, ans;

int main() {
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase) {
		scanf("%lf%lf%lf", &c, &f, &x);
		ans = x / 2;
		double t = 0, r = 2;
		for(int i = 1; i <= 2000; ++i) {
			ans = min(ans, t + x / r);
			t += c / r;
			r += f;
		}
		printf("Case #%d: %.9f\n", kase, ans);
	}
	return 0;
}