#include <stdio.h>
#include <string.h>


int trans[10][6];
char chars[10][6] = {
	"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};

int R[10];

bool Solve(int t[30])
{
	bool done = true;
	for (int i = 0; i < 30; i++) {
		if (t[i] > 0) {
			done = false;
			break;
		}
	}
	if (done)
		return true;

	for (int i = 0; i < 10; i++) {
		bool flag = true;
		for (int m = 0; m < trans[i][0]; m++) {
			if (t[trans[i][m + 1]] <= 0) {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int m = 0; m < trans[i][0]; m++) {
				t[trans[i][m + 1]] --;
			}

			// if success
			if (Solve(t)) {
				R[i]++;
				return true;
			}

			for (int m = 0; m < trans[i][0]; m++) {
				t[trans[i][m + 1]]++;
			}
		}
	}

	return false;
}

int main()
{
	int T;

	for (int i = 0; i < 10; i++) {
		trans[i][0] = strlen(chars[i]);
		for (int m = 0; m < strlen(chars[i]); m++) {
			trans[i][m+1] = chars[i][m] - 'A';
		}
	}

	scanf("%d", &T);
	for (int w = 0; w < T; w++) {
		char S[3000];

		scanf("%s", S);

		int t[30] = { 0 };
		for (int i = 0; i < strlen(S); i++) {
			t[S[i] - 'A']++;
		}

		for (int i = 0; i < 10; i++)
			R[i] = 0;

		Solve(t);

		printf("Case #%d: ", w + 1);
		for (int i = 0; i < 10; i++) {
			for (int m = 0; m < R[i]; m++)
				printf("%d", i);
		}
		printf("\n");
	}

	return 0;
}