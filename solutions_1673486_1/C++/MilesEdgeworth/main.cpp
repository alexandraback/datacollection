#include <cstdio>
#include <algorithm>

const int MAX_A = 100000;
double probs[MAX_A];
int T, A, B;

double solve() {
	double pr = 1.0;
	double min = B+2;
	for (int i = 0; i <= A; ++i) {
		if (i > 0) pr *= probs[i-1];
		int bpsp = A-i;
		min = std::min(min, pr*(B-i+1)+(1-pr)*(2*B-i+2)+bpsp);
	}
	return min;
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d %d", &A, &B);
		for (int i = 0; i < A; ++i) {
			scanf("%lf", &probs[i]);
		}

		printf("Case #%d: %.6lf\n", t, solve());
	}
}