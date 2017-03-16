#include <cstdio>
#include <cstring>
#include <vector>
#define MAX_A 100005

using namespace std;

int a, b;

double prob_correct[MAX_A];
double cum[MAX_A];

double get_expected(int num_back) {
	return (cum[a-num_back]) * (2 * num_back + b - a + 1) +
			(1.0 - cum[a-num_back]) * (2 * num_back + b - a + 1 + b + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int rayge = 1; rayge <= t; rayge++) {
		scanf("%d %d", &a, &b);
		cum[0] = 1.0;
		for (int i = 0; i < a; i++) {
			scanf("%lf", &prob_correct[i]);
			cum[i + 1] = cum[i] * prob_correct[i];
		}

		double minimum = (double) (b + 2);
		for (int i = 0; i <= a; i++) {
			double tmp = get_expected(i);
			if (tmp < minimum) {
				minimum = tmp;
			}
		}
		printf("Case #%d: %.6lf\n", rayge, minimum);
	}
}
