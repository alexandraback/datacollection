#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cmath>
#include<list>
#include<deque>

using namespace std;

int main() {
	int t;
	char s[4];

	char c[4][4];

	scanf("%d", &t);

	for (int caseCount = 1; caseCount <= t; ++caseCount) {
		int notComplete = 0;

		for (int i = 0; i < 4; ++i) {
			scanf("%s", s);
			for (int j = 0; j < 4; ++j) {
				c[i][j] = s[j];
				if (s[j] == '.') {
					notComplete = 1;
				}
			}
		}

		int flag = 0;

		//Diagonals

		char last = c[0][0];
		if (last != '.') {
			flag = 0;
			for (int i = 1, j = 1; i < 4; ++i, j++) {
				if ((c[i][j] != last && (last != 'T' && c[i][j] != 'T'))
						|| c[i][j] == '.') {
					flag = 1;
					break;
				}

				if (last == 'T') {
					last = c[i][j];
				}
			}
			if (flag == 0) {
				printf("Case #%d: %c won\n", caseCount, last);
				continue;
			}
		}

		last = c[0][3];
		if (last != '.') {
			flag = 0;
			for (int i = 1, j = 2; i < 4; ++i, j--) {
				if ((c[i][j] != last && (last != 'T' && c[i][j] != 'T'))
						|| c[i][j] == '.') {
					flag = 1;
					break;
				}

				if (last == 'T') {
					last = c[i][j];
				}
			}
			if (flag == 0) {
				printf("Case #%d: %c won\n", caseCount, last);
				continue;
			}
		}
		int winflag = 0;

		for (int i = 0; i < 4; ++i) {
			flag = 0;
			last = c[i][0];
			for (int j = 1; j < 4; ++j) {
				if ((c[i][j] != last && (last != 'T' && c[i][j] != 'T'))
						|| c[i][j] == '.') {
					flag = 1;
					break;
				}
				if (last == 'T') {
					last = c[i][j];
				}
			}
			if (flag == 0) {
				printf("Case #%d: %c won\n", caseCount, last);
				winflag = 1;
				break;
			}
		}

		if (winflag) {
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			flag = 0;
			last = c[0][i];
			for (int j = 1; j < 4; ++j) {
				if ((c[j][i] != last && (last != 'T' && c[j][i] != 'T'))
						|| c[j][i] == '.') {
					flag = 1;
					break;
				}
				if (last == 'T') {
					last = c[j][i];
				}
			}
			if (flag == 0) {
				printf("Case #%d: %c won\n", caseCount, last);
				winflag = 1;
				break;
			}
		}

		if (winflag) {
			continue;
		}

		if (notComplete) {
			printf("Case #%d: Game has not completed\n", caseCount);
		} else {
			printf("Case #%d: Draw\n", caseCount);
		}
	}

	return 0;
}

