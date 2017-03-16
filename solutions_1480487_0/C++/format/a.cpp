#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 1000;

int main() {
	int tc;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++) {
		printf("Case #%d:", t);

		int n;
		int s[N];
		int mark[N];
		int sum0 = 0;
		bool zero = true;
		scanf("%d", &n);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &s[j]);
			sum0 += s[j];
		}
		memset(mark, 0, sizeof(mark));

		int sum, k;
		bool flag = true;
		while (flag) {
			sum = k = 0;
			for (int j = 1; j <= n; j++) {
				if (mark[j] == 0) {
					sum += s[j];
					k++;
				}
			}

			flag = false;
			for (int j = 1; j <= n; j++) {
				if (mark[j] == 0 && s[j] * k >= sum + sum0) {
					mark[j] = 1;
					flag = true;
				}
			}
		}

		//printf("%d, %d, %d\n", sum0, sum, k);
		for (int j = 1; j <= n; j++) {
			if (mark[j]) {
				printf(" %.5lf", 0.0);
			} else {
				printf(" %.5lf", 100.0 * (1.0 * (sum + sum0) / k - s[j]) / sum0);
			}
			//printf(" %.5lf", max(100.0 * (sum * 2 / n - s[j]) / sum, 0.0));
			//printf(" %.5lf", 100.0 * (sum * 2 / k - s[j]) / sum);
		}
		printf("\n");
	}
	return 0;
}

