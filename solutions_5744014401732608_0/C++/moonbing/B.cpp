#include <stdio.h>
using namespace std;

int T;
int B;
long long int M;
long long int d[100];
int map[100][100];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t, i, j;

	d[1] = 1;
	for (i = 2; i <= 50; i++) {
		long long int value = 0;
		for (j = 1; j < i; j++) value += d[j];
		d[i] = value;
	}

	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d", &B, &M);

		printf("Case #%d: ", t);
		if (M > d[B]) printf("IMPOSSIBLE\n");
		else {
			for (i = 1; i <= B; i++) {
				for (j = i + 1; j <= B; j++)
					map[i][j] = 1;
			}
			for (i = 1; i <= B; i++) map[i][B] = 0;
			while (true) {
				if (M == 1) { map[1][B] = 1; break; }
				int index = 2;
				long long int temp = 1;
				while (true) {
					if (temp >= M) break;
					temp *= 2; index++;
				}
				temp /= 2; index--;

				map[index][B] = 1;
				M -= temp;
			}

			printf("POSSIBLE\n");
			for (i = 1; i <= B; i++) {
				for (j = 1; j <= B; j++)
					printf("%d", map[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
