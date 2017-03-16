#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

int i, j, k, kejsis, kejs, n, N;
long long a[200];
double sum, Q, ret;
bool el[200];

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d:", kejs);
		scanf("%d", &n);
		sum = 0;
		for (i = 0; i < n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
			el[i] = false;
		}
		N = n;
		for (;;) {
			Q = 2. * sum / N;
			for (i = 0; i < n; i++) {
				if (el[i]) continue;
				ret = (Q-a[i])/sum * 100;
				if (ret < -1e-9) {
					el[i] = true;
//					sum -= a[i];
					N--;
					break;
				}
			}
			if (i == n) break;
		}

		for (i = 0; i < n; i++) {
			if (el[i]) printf(" 0");
			else {
				ret = (Q-a[i])/sum * 100;
				printf(" %.10lf", ret);
			}
		}

		printf("\n");
	}
	return 0;
}
