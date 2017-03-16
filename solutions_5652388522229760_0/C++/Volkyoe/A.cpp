#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
using namespace std;
int TC, T, N, A[10], C;
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.txt", "w", stdout);
	scanf("%d", &TC);
	while (T < TC) {
		scanf("%d", &N);
		if (N == 0) {
			printf("Case #%d: INSOMNIA\n", ++T);
			continue;
		}
		int M = 0;
		for (int i = 0; i < 10; i++)
			A[i] = 0;
		C = 0;
		do {
			M += N;
			for (int K = M; K > 0; K /= 10) {
				int B = K % 10;
				if (A[B] == 0) {
					A[B] = 1;
					C++;
				}
			}
		} while (C < 10);
		printf("Case #%d: %d\n", ++T, M);
	}
}
