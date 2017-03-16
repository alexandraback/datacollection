#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

char b[10][10];

string strfrom(int res) {
	if(res == 0) return "Game has not completed";
	if(res == 1) return "Draw";
	if(res == 2) return "X won";
	if(res == 3) return "O won";

}

bool chval(char a, char c) {
	if(a==c || a=='T') return true;
	return false;
}

int check(char a, char b, char c, char d) {
	if(chval(a, 'X') && chval(b, 'X') && chval(c, 'X') && chval(d, 'X')) return 2;
	if(chval(a, 'O') && chval(b, 'O') && chval(c, 'O') && chval(d, 'O')) return 3;
	return 0;
}

void test(int t) {
	for(int i=1; i<=4; ++i)
		scanf("%s", b[i]+1);

	int res = 0;
	for(int i=1; i<=4 && res == 0; ++i)
		res = check(b[i][1], b[i][2], b[i][3], b[i][4]);
	for(int i=1; i<=4 && res == 0; ++i)
		res = check(b[1][i], b[2][i], b[3][i], b[4][i]);

	if(res == 0) res = check(b[1][1], b[2][2], b[3][3], b[4][4]);
	if(res == 0) res = check(b[1][4], b[2][3], b[3][2], b[4][1]);

	if(res == 0) {
		res = 1;
		for(int i=1; i<=4 && res; ++i)
			for(int j=1; j<=4; ++j)
				if(b[i][j] == '.') { res = 0; break; }
	}

	printf("Case #%d: %s\n", t, strfrom(res).c_str());
}

int main() {
	int T; scanf("%d", &T);
	for(int i=1; i<=T; ++i) test(i);

	return 0;
}
