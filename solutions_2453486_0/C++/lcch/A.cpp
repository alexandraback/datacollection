#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10;
char st[maxn][maxn];

bool check(char ch)
{
	bool tmp, tmp2;
	for (int i = 0; i != 4; i++) {
		tmp = tmp2 = true;
		for (int j = 0; j != 4; j++) {
			if (st[i][j] != ch && st[i][j] != 'T') tmp = false;
			if (st[j][i] != ch && st[j][i] != 'T') tmp2 = false;
		}
		if (tmp || tmp2) return true;
	}
	tmp = tmp2 = true;
	for (int i = 0; i != 4; i++) {
		if (st[i][i] != ch && st[i][i] != 'T') tmp = false;
		if (st[i][3 - i] != ch && st[i][3-i] != 'T') tmp2 = false;
	}
	return (tmp || tmp2);
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int TextN = 0, TT = 0;
	scanf("%d", &TextN);
	while (TextN--) {
		bool ful = true;
		for (int i = 0; i != 4; i++) {
			scanf("%s", st[i]);
			for (int j = 0; j != 4; j++)
				if (st[i][j] == '.') ful = false;
		}
		bool Xw = check('X');
		bool Ow = check('O');

		printf("Case #%d: ", ++TT); 
		if (Xw) printf("X won\n");
		else if (Ow) printf("O won\n");
		else if (ful) printf("Draw\n");
		else printf("Game has not completed\n");
	}
	return 0;
}