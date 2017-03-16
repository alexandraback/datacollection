#include <cstdio>
#include <algorithm>
using namespace std;

int T, n;
double C, F, X, t, ans;

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%lf%lf%lf", &C, &F, &X);
		n = 0;
		t = 0;
		ans = 1e8;
		while (t + 1e-7 < ans) {
			ans = min(ans, t + X / (2 + n * F));
			t += C / (2 + n * F);
			n++;
		}
		printf("Case #%d: %.7f\n", tc, ans);
	}
	return 0;
}