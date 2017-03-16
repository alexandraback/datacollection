#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>

using namespace std;

#define int_max 2000000000 // 20djr
#define int_min -2000000000 // -20djr
#define long_max ((long long)int_max*(long long)int_max) // 400kung
#define long_min -((long long)int_max*(long long)int_max) // -400kung

int ans;

int main(void) {
	int T;
	long long int N, M;
	long long int je;
	int i, j, k;

	freopen("B-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%lld %lld", &N, &M);
		je = 1;
		for (j = 1; j <= N - 2; j++) {
			je *= 2;
		}

		printf("Case #%d: ", i);

		if (je < M) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		else {
			printf("POSSIBLE\n");
		}

		M -= 1;
		M = M * 2 + 1;
		long long int chch = 1;
		for (j = 1; j < N; j++) {
			chch *= 2;
		}
		while (M != 0) {
			if (M / chch == 1) {
				printf("1");
				M %= chch;
			}
			else {
				printf("0");
			}
			chch /= 2;
		}
		printf("\n");
		for (j = 2; j <= N; j++) {
			for (k = 1; k <= j; k++) {
				printf("0");
			}
			for (; k <= N; k++) {
				printf("1");
			}
			printf("\n");
		}
	}


}