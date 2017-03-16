#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int T;
	int i, j, k;
	int answer;
	char check;
	char bae[200];

	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		answer = 0;
		scanf("%s", bae);
		check = bae[0];
		for (j = 0; ; j++) {
			if (bae[j] == 0) {
				if (bae[j - 1] == '-') {
					answer++;
				}
				break;
			}
			if (bae[j] != check) {
				answer++;
				check = bae[j];
			}
		}
		printf("Case #%d: %d\n", i, answer);
	}


}