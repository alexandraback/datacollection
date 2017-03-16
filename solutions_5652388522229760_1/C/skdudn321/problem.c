#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int T;
	int N;
	int i, j, k;
	int answer;
	int check[10];
	char num[20];
	char * str = "INSOMNIA";

	freopen("A-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		for (j = 0; j < 10; j++) {
			check[j] = 0;
		}
		scanf("%d", &N);
		if (N == 0) {
			printf("Case #%d: %s\n", i, str);
			continue;
		}
		for (j = 1; ; j++) {
			answer = j * N;
			_itoa(answer, num, 10);
			for (k = 0; ; k++) {
				if (num[k] == 0) {
					break;
				}
				check[num[k] - '0'] = 1;
			}

			for (k = 0; k < 10; k++) {
				if (check[k] == 0) {
					break;
				}
			}
			if (k == 10) {
				break;
			}
		}

		printf("Case #%d: %d\n", i, answer);
	}


}