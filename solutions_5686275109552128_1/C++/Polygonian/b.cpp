#include <iostream>
#include <assert.h>
#include <limits.h>
#include <vector>

using namespace std;

int A[2000];
int N;

int solve() {
	int best = INT_MAX;
	for (int h = 1;; h++) {
		if (h >= best) return best;
		int move = 0;
		for (int j = 0; j < N; j++) {
			int deficit = A[j] - h;
			if (deficit <= 0) continue;
			move += (deficit + (h - 1)) / h;
		}
		int cost = move + h;
		if (best > cost) best = cost;
	}
	return 0;
}

int main(void) {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[j]);
		}
		int answer = solve();
		printf("Case #%d: %d\n", i + 1, answer);
	}
	return 0;
}
