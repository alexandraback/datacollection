#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define MAXN 105
using namespace std;

long long a[MAXN], b[MAXN];
int A[MAXN], B[MAXN];

void augment(int pA, int pB, long long* lA, long long* lB, long long* sum) {
	if(A[pA] == B[pB]) {
		long long add = min(*lA, *lB);
		*lB -= add;
		*lA -= add;
		*sum += add;
	}
}

int main() {
	int T;

	scanf("%d", &T);
	for(int t = 1; t <= T; ++t) {
		int N, M;
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; ++i) {
			scanf("%lld%d", &a[i], &A[i]);
		}
		for(int i = 0; i < M; ++i) {
			scanf("%lld%d", &b[i], &B[i]);
		}

		long long max_sum = 0;
		for(int sw1 = 0; sw1 < M; ++sw1) {
			for(int sw2 = sw1; sw2 < M; ++sw2) {
				long long sum = 0;
				long long lA = a[0];
				long long lB = b[0];

				int pA = 0, pB;
				for(pB = 0; pB < M; ++pB) {
					lB = b[pB];

					if(pB == sw1) {
						augment(pA, pB, &lA, &lB, &sum);
						if(pA < N-1) {
							pA++;
							lA = a[pA];
						}
					}

					if(pB == sw2) {
						augment(pA, pB, &lA, &lB, &sum);
						if(pA < N-1) {
							pA++;
							lA = a[pA];
						}
					}

					augment(pA, pB, &lA, &lB, &sum);
				}

				max_sum = max(max_sum, sum);
			}
		}

		printf("Case #%d: %lld\n", t, max_sum);
	}

	return 0;
}
