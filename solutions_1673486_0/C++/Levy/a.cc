#include <cstdio>
#include <cstring>

const int MAXN = 100100;

int A, B;
double p[MAXN];

int main() {
	int t;
	scanf("%d", &t);
	for (int c = 1; c <= t; ++c) {
		scanf("%d%d", &A, &B);
		for (int i = 0; i < A; ++i) scanf("%lf", p + i);
		
		double answer = B + 2;
		double cp = 1;
		for (int i = A; i >= 0; --i) {
			double t = cp * (i + B - (A - i) + 1) + (1 - cp) * (i + B - (A - i) + 1 + B + 1);
			if (t < answer) answer = t;
			if (i > 0) 
				cp *= p[A - i];
		}
		
		printf("Case #%d: %.6lf\n", c, answer);
	}
}

