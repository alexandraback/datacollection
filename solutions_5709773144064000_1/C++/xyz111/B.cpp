#include <cstdio>
#include <algorithm>
using namespace std;

int T;
double C, F, X, ans, nowC, nowT;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int Q = 1; Q <= T; Q++) {
		scanf("%lf%lf%lf", &C, &F, &X);
		ans = X / 2;
		nowT = 0; nowC = 2;
		while (nowT <= ans) {
			nowT += C / nowC;
			nowC += F;
			ans = min(ans, nowT + X / nowC);
		}
		printf("Case #%d: %.10lf\n", Q, ans);
	}
}
