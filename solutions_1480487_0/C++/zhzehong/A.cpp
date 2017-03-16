#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {

	freopen("A-small-attempt5.in", "r", stdin);
	freopen("A-small-attempt5.out", "w", stdout);

	int cases;
	scanf("%d", &cases);

	for (int cas = 1; cas <= cases; cas++) {
		int sum = 0, N, m, temp;
		int s[250];
		double ans[250]; 
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &s[i]);
			sum += s[i];
		}
		temp = sum;
		m = N;
		for (int i = 0; i < N; i++) {
			if (sum * 2 / N < s[i]) {
				ans[i] = 0.0;
				m--;
				temp -= s[i];
			//	printf("==%d\n", i);
			}
			else ans[i] = 1.0;
        }
    //    printf("%d %d\n", temp, m);
        for (int i = 0; i < N; i++) {
			if (ans[i] > 0.5) {
				ans[i] = 1.0 * (1.0 * (sum + temp) / m - s[i]) / sum * 100.0;
			}
		}
		printf("Case #%d:", cas); 
		for (int i = 0; i < N; i++) printf(" %.6lf", ans[i]);
		printf("\n");
	}
	return 0;
}
