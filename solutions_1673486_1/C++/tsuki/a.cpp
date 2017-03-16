#include <cstdio>
#include <iostream>
#include <limits>
using namespace std;
const int maxn = 100000 + 5;
int t, A, B;
double p[maxn];

double gao() {
	double ans = numeric_limits<double>::max();
	for (int i = 0; i <= A; ++i)
		ans = min(ans, i + p[A - i] * (B - A + i + 1) + (1 - p[A - i]) * (B - A + i + 1 + B + 1));
	return min(ans, (double)B + 2);
}

int main() {
	p[0] = 1;
	scanf("%d", &t);
	for (int index = 1; index <= t; ++index) {
		scanf("%d%d", &A, &B);
		for (int i = 1; i <= A; ++i) {
			scanf("%lf", &p[i]);
			p[i] *= p[i - 1];
		}
		printf("Case #%d: %.6f\n", index, gao());
	}
	return 0;
}
