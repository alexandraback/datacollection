#include <stdio.h>
#include <iostream>
#include <cstring>
int main(void) {
	freopen("a.out", "w", stdout);
	freopen("a.in", "r", stdin);
	int cha[26];
	int num[10];
	char in[2005];
	int cs;
	scanf("%d", &cs);

	for (int T = 1; T <= cs; T++) {
		scanf(" %s", in);

		int la = strlen(in);

		for (int i = 0; i < 26; i++) {
			cha[i] = 0;
		}

		for (int i = 0; i < 10; i++) {
			num[i] = 0;
		}

		for (int i = 0; i < la; i++) {
			cha[in[i] - 'A']++;
		}
		num[6] = cha[(int)('X' - 'A')];
		cha[(int)('S' - 'A')] -= num[6];
		num[7] = cha[(int)('S' - 'A')];
		cha[(int)('V' - 'A')] -= num[7];
		num[5] = cha[(int)('V' - 'A')];
		cha[(int)('F' - 'A')] -= num[5];
		num[4] = cha[(int)('F' - 'A')];
		cha[(int)('O' - 'A')] -= num[4];
		num[0] = cha[(int)('Z' - 'A')];
		cha[(int)('O' - 'A')] -= num[0];
		num[8] = cha[(int)('G' - 'A')];
		cha[(int)('H' - 'A')] -= num[8];
		num[3] = cha[(int)('H' - 'A')];

		num[2] = cha[(int)('W' - 'A')];
		cha[(int)('O' - 'A')] -= num[2];
		num[1] = cha[(int)('O' - 'A')];
		cha[(int)('O' - 'A')] -= num[0];
		num[9] = la - num[0] * 4 - num[1] * 3 - num[2] * 3 - num[3] * 5 - num[4] * 4 - num[5] * 4 - num[6] * 3 - num[7] * 5 - num[8] * 5;
		num[9] = num[9] / 4;
		printf("Case #%d: ", T);

		for (int i = 0; i <= 9; i++) {
			int now = num[i];

			for (int j = 0; j < now; j++) {
				printf("%d", i);
			}
		}

		printf("\n");
	}

	return 0;
}
