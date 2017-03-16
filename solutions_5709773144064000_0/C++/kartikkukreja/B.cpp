#include <cstdio>
using namespace std;

int main() {
	int T, i;
	double C, F, X, rate, sum, time;	
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.txt", "w", stdout);
	
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%lf %lf %lf", &C, &F, &X);
		rate = 2.0; sum = time = 0.0;
		while (sum < X) {
			if (sum < C) {
				time += (C - sum) / rate;
				sum = C;
			}
			if ((X-sum+C)/(rate+F) < (X-sum)/rate) {
				rate += F;
				sum -= C;
			} else {
				time += (X-sum)/rate;
				sum = X;
			}
		}
		printf("Case #%d: %.7lf\n", i, time);
	}
	
	return 0;
}
