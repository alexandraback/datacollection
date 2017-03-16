#include <cstdio>
#include <algorithm>

using namespace std;

#define X	1009 // MAX 

int T, N, A[X], B[X], C[X], R, S, D;

main()
{
	scanf("%d\n", &T);

	for (int t = 1; t <= T; ++t) {
		scanf("%d\n", &N);
		for (int n = 0; n < N; ++n) {
			scanf("%d %d\n", &A[n], &B[n]);
			C[n] = 0;
		}

		int j;

		for (R = S = D = 0;  D < N; ++R) {
			j = -1;
			for (int i = 0; i < N; ++i) {
				if (C[i] == 2) continue;
				if (S >= B[i]) {
					S += 2 - C[i];
					C[i] = 2;
					D++;
					j = i;
					break;
				}
				if (C[i] == 0 && S >= A[i]) {
					if (j < 0 || B[i] > B[j])
						j = i;
				}
			}
			if (j < 0) {
				printf("Case #%d: Too Bad\n", t);
				break;
			} else if (C[j] == 0) {
				C[j] = 1;
				S += 1;
			}
		}
		
		if (j >= 0) 
			printf("Case #%d: %d\n", t, R);
	}
}
