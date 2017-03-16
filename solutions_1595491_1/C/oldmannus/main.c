#include <stdio.h>

int main() {
	int i, T;
	scanf("%d", &T);
	for(i = 0; i < T; i++) {
		int N, S, p, j, result;
		scanf("%d %d %d", &N, &S, &p);
		
		result = 0;
		for(j = 0; j < N; j++) {
			int t;
			int bs, bus;

			scanf("%d", &t);
			if (t == 0)
				bs = bus = 0;
			else if (t > 28)
				bs = bus = 10;
			else {
				bus = (t + 2) / 3;	
				bs = (t % 3 == 1 ? bus : bus + 1);
			}

			if (bus >= p)
				result++;
			else if (bs >= p && S > 0) {
				result++;
				S--;
			}
		}

		printf("Case #%d: %d\n", i+1, result);
	}
}

/*qsort(t, N, sizeof(int), compare);
		printf("Number of Googlers = %d\nNumber of surprising triplets = %d\nBest score = %d\n", N, S, p);
		for(j = 0; j < N; j++)
			printf("Score of #%d = %d\n", j, t[j]);*/
