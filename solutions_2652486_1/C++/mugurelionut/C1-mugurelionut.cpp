#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <time.h>

using namespace std;

#define NMAX 13
#define MAX_DONE 2240

set<long long> prod, pfound;
set<long long>::iterator itprod, itpfound;
int sol[NMAX];
int R, N, M, K, conf, i, j, nmissed, idxstart;
long long p;

int prime[5] = {0, 2, 3, 5, 7}, cntmax[5], cntmin[5];

#define MAX_SUBSETS 256

int GenerateNumbers(int idx) {
	if (idx > N) {
		// Test the numbers.
		pfound.clear();
		
		for (i = 0; i < MAX_SUBSETS; i++) {
			p = 1;
			for (j = 1; j <= N; j++)
				if (((rand() & 1023) & 512) == 0)
					p *= (long long) sol[j];
			pfound.insert(p);
		}
	
		itprod = prod.begin();
		itpfound = pfound.begin();

		nmissed = 0;
		while (itprod != prod.end() && itpfound != pfound.end()) {
			if (*itprod < *itpfound) {
				nmissed++;
				itprod++;
			} else if (*itprod == *itpfound) {
				itprod++;
				itpfound++;
			} else
				itpfound++;
		}

		while (itprod != prod.end()) {
			itprod++;
			nmissed++;
		}

		if (nmissed <= 1) {
			fprintf(stderr, "nmissed=%d/%d\n", nmissed, prod.size());
			return 1;
		}
		return 0;
	} else {
		if (idx == idxstart)
			sol[idx] = 2;
		else
			sol[idx] = sol[idx - 1];

		for (; sol[idx] <= M; sol[idx]++)
			if (GenerateNumbers(idx + 1))
				return 1;
		sol[idx] = M;
		return 0;
	}
}

int main() {
	int tstart = clock();

	srand(12345);

	freopen("C-small-2-attempt1.in", "r", stdin);
	freopen("C2small.out", "w", stdout);

	int T, i, j, k, done = 0;
	long long x, y;
	
	scanf("%d", &T);
	printf("Case #1:\n");
	scanf("%d %d %d %d", &R, &N, &M, &K);
	sol[0] = 2;

	while (R--) {
		memset(cntmin, 0, sizeof(cntmin));
		memset(cntmax, 0, sizeof(cntmax));
		
		prod.clear();
		for (i = 1; i <= K; i++) {
			scanf("%lld", &x);
			prod.insert(x);
			
			for (j = 1; j <= 4; j++) {
				y = x;
				k = 0;
				while ((y % prime[j]) == 0) {
					k++;
					y /= prime[j];
				}
				
				if (k > cntmax[j])
					cntmax[j] = k;
				
				if (k > 0 && (k < cntmin[j] || cntmin[j] == 0))
					cntmin[j] = k;
			}
		}

		i = 0;
		for (j = 3; j <= 4; j++) {
			//fprintf(stderr, "j=%d: %d %d\n", j, cntmin[j], cntmax[j]);
			for (k = 1; k <= cntmax[j]; k++) {
				i++;
				sol[i] = prime[j];
			}
		}

		//fprintf(stderr, "   i=%d: %d %d\n", i, cntmin[1], cntmax[1]);
		
		while (cntmax[2] >= 1) {
			if (cntmax[1] >= 1) {
				i++;
				sol[i] = 6;
				cntmax[1]--;
				cntmin[1]--;
			} else {
				i++;
				sol[i] = prime[2];
			}
			cntmax[2]--;
		}

		//fprintf(stderr, "   i=%d: %d %d\n", i, cntmin[1], cntmax[1]);
		
		if ((cntmin[1] % 2) == 1 || (cntmax[1] % 2) == 1) {
			i++;
			sol[i] = 2;
		} else if ((cntmin[1] % 3) == 2 || (cntmax[1] % 3) == 2) {
			i++;
			sol[i] = 4;
		}
		
		for (j = 3; j <= cntmax[1]; j += 3) {
			i++;
			sol[i] = 8;
		}

		idxstart = i + 1;
		if (idxstart >= N + 2) {
			fprintf(stderr, "too many numbers!\n");
			//exit(1);
			idxstart = N + 1;
		}

		GenerateNumbers(i + 1);

		for (i = 1; i <= N; i++)
			printf("%d", sol[i]);
		printf("\n");
		
		for (i = 1; i <= N; i++)
			fprintf(stderr, "%d", sol[i]);
		fprintf(stderr, "\n");

		done++;
		if (R % 100 == 0)
			fprintf(stderr, " remaining=%d done=%d duration=%.3lf sec\n", R, done, (double) (clock() - tstart) / CLOCKS_PER_SEC);
	}

	fprintf(stderr, "Duration=%.3lf sec\n", (double) (clock() - tstart) / CLOCKS_PER_SEC);
	return 0;
}
