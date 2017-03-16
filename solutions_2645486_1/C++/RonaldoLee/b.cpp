#include<stdio.h>
using namespace std;


int main() {
    int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int E, R, N;
		int V[10000];
		int C[10000];
		scanf("%d %d %d", &E, &R, &N);
		for (int j = 0; j < N; j++)
			scanf("%d", &V[j]);
		if (E <= R) {
			long long result = 0;
			for (int j = 0; j < N; j++)
				result += V[j] * E;
			printf("Case #%d: %lld\n", i, result);
		} else {
			long long result = 0;
			C[0] = E;
			for (int j = 1; j < N; j++) {
				C[j] = R;
			}
			int E_ = E;
			for (int j = N - 1; j >= 0; j--) {
				int k = j - 1;
				while (V[k] < V[j]) {
					if (C[k] + C[j] < E_) {
						C[j] = C[k] + C[j];
						C[k] = 0;
					} else {
						C[k] = C[k] + C[j] - E_;
						C[j] = E_;
						
						break;
					}
					k--;
				}
				E_ = (E < (E_ + R - C[j])) ? E : (E_ + R - C[j]);
			}
			
			for (int j = 0; j < N; j++) {
				result += C[j] * V[j];
			}
			printf("Case #%d: %lld\n", i, result);
		}
	}
	return 0;
}
