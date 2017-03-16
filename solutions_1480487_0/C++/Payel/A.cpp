#include <cstdio>
using namespace std;

const int MAX = 256;
const double eps = 1e-9;

double score[MAX], total;

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int test, cs, i, n;
	double p;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		for(total = 0.0, i = 0; i < n; i++) {
			scanf("%lf", &score[i]);
			total += score[i];
		}
		p = 2.0 * total / (double)n;
		printf("Case #%d:", cs);
		for(i = 0; i < n; i++) printf(" %.8lf", (p - score[i]) / total * 100.0 + eps);
		printf("\n");
	}
	return 0;
}