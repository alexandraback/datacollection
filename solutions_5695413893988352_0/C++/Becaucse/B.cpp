#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

FILE *wfp;
unsigned long long c, j;
char input_c[30], input_j[30];
char ans_c[30], ans_j[30];
int len;

int dif(int a, int b);

int main() {
	int ts;

	wfp = fopen("output.txt", "w");

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d", &ts);

	for (int t = 1; t <= ts; t++) {
		scanf("%s %s", input_c, input_j);
		len = strlen(input_c);

		c = 0;
		j = 0;

		for (int i = 0; i < len; i++) {
			if (input_c[i] == '?' && input_j[i] == '?') {
				if (c == j) {
					ans_c[i] = '0';
					ans_j[i] = '0';
				}
				else if (c > j) {
					ans_c[i] = '0';
					ans_j[i] = '9';
				}
				else {
					ans_c[i] = '9';
					ans_j[i] = '0';
				}
				c *= 10;
				j *= 10;
				c += ans_c[i] - '0';
				j += ans_j[i] - '0';
			}
			else if (input_c[i] == '?' && input_j[i] != '?') {
				if (c == j) {
					ans_c[i] = input_j[i];
					ans_j[i] = input_j[i];
				}
				else if (c > j) {
					ans_c[i] = '0';
					ans_j[i] = input_j[i];
				}
				else {
					ans_c[i] = '9';
					ans_j[i] = input_j[i];
				}
				c *= 10;
				j *= 10;
				c += ans_c[i] - '0';
				j += ans_j[i] - '0';
			}
			else if (input_c[i] != '?' && input_j[i] == '?') {
				if (c == j) {
					ans_c[i] = input_c[i];
					ans_j[i] = input_c[i];
				}
				else if (c > j) {
					ans_c[i] = input_c[i];
					ans_j[i] = '9';
				}
				else {
					ans_c[i] = input_c[i];
					ans_j[i] = '0';
				}
				c *= 10;
				j *= 10;
				c += ans_c[i] - '0';
				j += ans_j[i] - '0';
			}
			else {
				ans_c[i] = input_c[i];
				ans_j[i] = input_j[i];
				c *= 10;
				j *= 10;
				c += ans_c[i] - '0';
				j += ans_j[i] - '0';

				if (c - (ans_c[i] - '0') == j - (ans_j[i] - '0') && i >= 1) {
					if (ans_c[i] > ans_j[i]) {
						if (input_j[i - 1] == '?') {
							if (ans_j[i - 1] != '9' &&
								dif(10 * (ans_j[i - 1] - '0' + 1) + ans_j[i] - '0', 10 * (ans_c[i - 1] - '0') + ans_c[i] - '0') <
								dif(10 * (ans_j[i - 1] - '0') + ans_j[i] - '0', 10 * (ans_c[i - 1] - '0') + ans_c[i] - '0')) {
								ans_j[i - 1] = ans_j[i - 1] + 1;
								j += 10;
							}
						}
						else if (input_c[i - 1] == '?' && input_j[i - 1] != '?') {
							if (input_c[i - 1] != '0' && 
								dif(10 * (ans_j[i - 1] - '0') + ans_j[i] - '0', 10 * (ans_c[i - 1] - '0' - 1) + ans_c[i] - '0') <=
								dif(10 * (ans_j[i - 1] - '0') + ans_j[i] - '0', 10 * (ans_c[i - 1] - '0') + ans_c[i] - '0')) {
								ans_c[i - 1] = ans_c[i - 1] - 1;
								c -= 10;
							}
						}
					}
					else if (ans_c[i] < ans_j[i]) {
						if (input_c[i - 1] == '?') {
							if (ans_c[i - 1] != '9' &&
								dif(10 * (ans_c[i - 1] - '0' + 1) + ans_c[i] - '0', 10 * (ans_j[i - 1] - '0') + ans_j[i] - '0') <
								dif(10 * (ans_c[i - 1] - '0') + ans_c[i] - '0', 10 * (ans_j[i - 1] - '0') + ans_j[i] - '0')) {
								ans_c[i - 1] = ans_c[i - 1] + 1;
								c += 10;
							}
						}
						else if (input_j[i - 1] == '?' && input_c[i - 1] != '?') {
							if (input_j[i - 1] != '0' &&
								dif(10 * (ans_c[i - 1] - '0') + ans_c[i] - '0', 10 * (ans_j[i - 1] - '0' - 1) + ans_j[i] - '0') <=
								dif(10 * (ans_c[i - 1] - '0') + ans_c[i] - '0', 10 * (ans_j[i - 1] - '0') + ans_j[i] - '0')) {
								ans_j[i - 1] = ans_j[i - 1] - 1;
								j -= 10;
							}
						}
					}
				}
			}
		}

		ans_c[len] = 0;
		ans_j[len] = 0;

		//output
		fprintf(wfp, "Case #%d: %s %s\n", t, ans_c, ans_j);

	}

	fclose(wfp);

	return 0;
}

int dif(int a, int b) {
	if (a > b)
		return a - b;
	else
		return b - a;
}