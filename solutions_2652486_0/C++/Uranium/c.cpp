#include <cstdio>
#include <algorithm>

#define MAXK 7
#define MAXM 5

int R, N, M, K;

void solve() {
	int exists[MAXM+1];
	int prod;

	for(int i = 0; i < R; ++i) {
		std::fill(exists, exists + MAXM + 1, 0);
		for(int j = 0; j < K; ++j) {
			scanf("%d", &prod);

			int prev = -1;
			while(prev != prod) {
				prev = prod;


				if(prod % 125 == 0) {
					exists[5] = std::max(exists[5], 3);
					prod /= 125;
				}
				if(prod % 25 == 0) {
					exists[5] = std::max(exists[5], 2);
					prod /= 25;
				}
				if(prod % 5 == 0) {
					exists[5] = std::max(exists[5], 1);
					prod /= 5;
				}


				if(prod % 27 == 0) {
					exists[3] = std::max(exists[3], 3);
					prod /= 27;
				}
				if(prod % 9 == 0) {
					exists[3] = std::max(exists[3], 2);
					prod /= 9;
				}
				if(prod % 3 == 0) {
					exists[3] = std::max(exists[3], 1);
					prod /= 3;
				}

				if(prod % 64 == 0) {
					exists[4] = std::max(exists[4], 3);
					prod /= 64;
				}

				if(prod % 2 == 0 && prod % 4 != 0) {
					exists[2] = std::max(exists[2], 1);
					prod /= 2;
				}

				if(exists[3] + exists[5] >= 2) {
					if(prod == 4) exists[4] = 1;
					if(prod == 2) exists[2] = 1;
				}
			}
		}

		int output = 0;
		for(int j = 2; j <= M; ++j) {
			for(int k = 0; k < exists[j]; ++k) {
				printf("%d", j);
				++output;
			}
		}

		for(; output < N; ++output) {
			printf("2");
		}

		printf("\n");
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int i = 0; i < T; ++i) {
		scanf("%d%d%d%d", &R, &N, &M, &K);
		printf("Case #%d:\n", i+1);
		solve();
	}

	return 0;
}
