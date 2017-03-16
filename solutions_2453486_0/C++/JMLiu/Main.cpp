#include <iostream>
#include <cstdio>

using namespace std;

char p[5][5];
char *a1 = "X won\n";
char *a2 = "O won\n";
char *a3 = "Draw\n";
char *a4 = "Game has not completed\n";
const int n = 4;

int main() {
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	int T;
	scanf("%d", &T);
	int c = T;
	while (T --){
		for (int i = 0 ; i < n ; i ++) scanf("%s", p[i]);
		int ans = 0;
		bool FlagD = false;
		for (int i = 0 ; i < n ; i ++) {
			for (int j = 0 ; j < n ; j ++) {
				if (p[i][j] == '.') {
					FlagD = true;
					break;
				}
			}
			if (FlagD) break;
		}
		for (int i = 0 ; i < n ; i ++) {
			bool FlagX = true;
			bool FlagO = true;
			for (int j = 0 ; j < n ; j ++) {
				if (p[i][j] != 'X' && p[i][j] != 'T') FlagX = false;
				if (p[i][j] != 'O' && p[i][j] != 'T') FlagO = false;
			}
			if (FlagX) {
				ans = 1;
				break;
			}
			if (FlagO) {
				ans = 2;
				break;
			}
		}
		if (ans == 0) {
			for (int i = 0 ; i < n ; i ++) {
				bool FlagX = true;
				bool FlagO = true;
				for (int j = 0 ; j < n ; j ++) {
					if (p[j][i] != 'X' && p[j][i] != 'T') FlagX = false;
					if (p[j][i] != 'O' && p[j][i] != 'T') FlagO = false;
				}
				if (FlagX) {
					ans = 1;
					break;
				}
				if (FlagO) {
					ans = 2;
					break;
				}
			}
		}
		if (ans == 0) {
			if ((p[0][0] == 'T' || p[0][0] == 'X') && (p[1][1] == 'T' || p[1][1] == 'X') && (p[2][2] == 'T' || p[2][2] == 'X') && (p[3][3] == 'T' || p[3][3] == 'X')) ans = 1;
			else if ((p[3][0] == 'T' || p[3][0] == 'X') && (p[2][1] == 'T' || p[2][1] == 'X') && (p[1][2] == 'T' || p[1][2] == 'X') && (p[0][3] == 'T' || p[0][3] == 'X')) ans = 1;
			else if ((p[0][0] == 'T' || p[0][0] == 'O') && (p[1][1] == 'T' || p[1][1] == 'O') && (p[2][2] == 'T' || p[2][2] == 'O') && (p[3][3] == 'T' || p[3][3] == 'O')) ans = 2;
			else if ((p[3][0] == 'T' || p[3][0] == 'O') && (p[2][1] == 'T' || p[2][1] == 'O') && (p[1][2] == 'T' || p[1][2] == 'O') && (p[0][3] == 'T' || p[0][3] == 'O')) ans = 2;
			else if (FlagD) ans = 4;
			else if (!FlagD) ans = 3;
		}
		switch (ans) {
			case 1:
				printf("Case #%d: %s", c - T, a1);
				break;
			case 2:
				printf("Case #%d: %s", c - T, a2);
				break;
			case 3:
				printf("Case #%d: %s", c - T, a3);
				break;
			case 4:
				printf("Case #%d: %s", c - T, a4);
				break;
		}
	}
	//system("pause");
}