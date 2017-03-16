#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
using namespace std;
int T, t, N, A[1005];
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.txt", "w", stdout);
	scanf("%d", &T);
	while (t < T) {
		scanf("%d", &N);
		int MIN = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
			MIN = max(MIN, A[i]);
		}
		for (int k = 1; k <= MIN; k++) {
			int count = 0;
			for (int i = 0; i < N; i++)
				count += (A[i] - 1) / k;
			MIN = min(MIN, count + k);
		}
		printf("Case #%d: %d\n", ++t, MIN);
	}
}
