#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
	int ttt;
	scanf("%d", &ttt);
	for (int test = 1; test <= ttt; ++test) {
		double c, f, x;
		scanf("%lf%lf%lf", &c, &f, &x);
		int t = 0;
		while (true) {
			if (f / (2 + (t + 1) * f) < c / x) break;
			++t;
		}
		double ans = 0;
		for (int i = 0; i < t; ++i) {
			ans += c / (2 + i * f);
		}
		ans += x / (2 + t * f);
		printf("Case #%d: %.6f\n", test, ans);
	}
	return 0;
}