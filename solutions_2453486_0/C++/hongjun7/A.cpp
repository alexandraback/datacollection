#include <stdio.h>
#define MN 10
char S[MN][MN];
bool chk(char ch) {
	int cnt;
	for (int i = 1; i <= 4; i++) {
		cnt = 0;
		for (int j = 1; j <= 4; j++)
			cnt += (S[i][j]=='T' || S[i][j]==ch);
		if (cnt == 4) return 1;

		cnt = 0;
		for (int j = 1; j <= 4; j++)
			cnt += (S[j][i]=='T' || S[j][i]==ch);
		if (cnt == 4) return 1;
	}
	cnt = 0;
	for (int i = 1; i <= 4; i++)
		cnt += (S[i][i]=='T' || S[i][i]==ch);
	if (cnt == 4) return 1;

	cnt = 0;
	for (int i = 1; i <= 4; i++)
		cnt += (S[i][5-i]=='T' || S[i][5-i]==ch);
	if (cnt == 4) return 1;

	return 0;
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T, sw, k;
	scanf("%d",&T);
	for (k = 1; k <= T; k++) {
		for (int i = 1; i <= 4; i++)
			scanf("%s",S[i]+1);
		if (chk('O') == 1) sw = 1;
		else if (chk('X') == 1) sw = 2;
		else {
			sw = 4;
			for (int i = 1; i <= 4; i++)
				for (int j = 1; j <= 4; j++)
					if (S[i][j]=='.') sw = 3;
		}
		printf("Case #%d: ",k);
		if (sw <= 2)
			printf("%c won\n", (sw==1?'O':'X'));
		else {
			if (sw == 3)
				printf("Game has not completed\n");
			else
				printf("Draw\n");
		}

	}
	fcloseall();
	return 0;
}