#include <cstdio>
#include <algorithm>

using namespace std;

int tc;
char a[5][5];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &tc);
	for (int tn = 0; tn < tc; tn++) {
		gets(a[0]);
		for (int i = 0; i < 4; i++)
			gets(a[i]);
		int w = 0;
		int X = 0, O = 0;
		for (int i = 0; i < 4; i++) {
			int e = 0, r = 0;
			for (int j = 0; j < 4; j++) {
				if (a[i][j] == 'X' || a[i][j] == 'T')
					e ++;
				if (a[i][j] == 'O' || a[i][j] == 'T')
					r ++;
			}
			X = max(X, e);
			O = max(O, r);
			e = 0, r = 0;
			for (int j = 0; j < 4; j++) {
				if (a[j][i] == 'X' || a[j][i] == 'T')
					e ++;
				if (a[j][i] == 'O' || a[j][i] == 'T')
					r ++;
			}
			X = max(X, e);
			O = max(O, r);
		}
		int e = 0, r = 0;
		for (int i = 0; i < 4; i++) {
			if (a[i][i] == 'X' || a[i][i] == 'T')
				e ++;
			if (a[i][i] == 'O' || a[i][i] == 'T')
				r ++;
		}
		X = max(X, e);
		O = max(O, r);
		e = 0, r = 0;
		for (int i = 0; i < 4; i++) {
			if (a[i][3-i] == 'X' || a[i][3-i] == 'T')
				e ++;
			if (a[i][3-i] == 'O' || a[i][3-i] == 'T')
				r ++;
		}
		X = max(X, e);
		O = max(O, r);
		int c = 0;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				 c += a[i][j] == '.';
		printf("Case #%d: ", tn+1);
		if (X == 4)
			puts("X won");
		else if (O == 4)
			puts("O won");
		else if (c)
			puts("Game has not completed");
		else
			puts("Draw");
	}
	return 0;
}