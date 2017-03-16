#include <iostream>

using namespace std;

int T;
int N;
char A[2000];
int sum[2000];

int solve() {
	int need = 0;
	int clapCount = 0;
	for (int i = 0; i <= N; i++) {
		sum[i] = (i == 0 ? 0 : sum[i - 1]) + (A[i] - '0');
		if (i < N && sum[i] < i + 1) {
			int delta = i + 1 - sum[i];
			need += delta;
			sum[i] += delta;
		}
	}
	return need;
}

int main(void) {
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%s", &N, A);
		int result = solve();
		printf("Case #%d: %d\n", i + 1, result);
	}
	return 0;
}
