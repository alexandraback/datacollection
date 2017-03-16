#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 10;

char s[MAXN][MAXN];

bool win(const char x) {
	int tot = 0;
	for (int i=0; i<4; ++i)	if (s[i][i] == x || s[i][i] == 'T') ++tot;
	if (tot == 4) return true;
	tot = 0;
	for (int i=0; i<4; ++i)	if (s[i][3-i] == x || s[i][3-i] == 'T') ++tot;
	if (tot == 4) return true;
	for (int i=0; i<4; ++i) {
		tot = 0;
		for (int j=0; j<4; ++j) if (s[i][j] == x || s[i][j] == 'T') ++tot;
		if (tot == 4) return true;
	}
	for (int j=0; j<4; ++j) {
		tot = 0;
		for (int i=0; i<4; ++i) if (s[i][j] == x || s[i][j] == 'T') ++tot;
		if (tot == 4) return true;
	}
	return false;
}

int main() {
	int cn = 0, tc;	
	int tot;

	scanf("%d", &tc);
	while (tc--) {
		tot = 0;
		for (int i=0; i<4; ++i) {
			scanf("%s", s[i]);
			for (int j=0; j<4; ++j) {
				if (s[i][j] == '.') ++tot;
			}
		}
		printf("Case #%d: ", ++cn);
		if (win('X')) puts("X won");
		else if (win('O')) puts("O won");
		else if (tot) puts("Game has not completed");
		else puts("Draw");
	}

	return 0;
}
