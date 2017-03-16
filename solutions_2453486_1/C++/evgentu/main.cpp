#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

char s[5][5];

bool calc(char* cur) {
	int cx = 0, co = 0;
	for(int j = 0; j < 4; ++j) {
		if(cur[j] == 'X')
			++cx;
		if(cur[j] == 'O')
			++co;
		if(cur[j] == 'T')
			++cx, ++co;
	}
	if(cx == 4) {
		printf("X won\n");
		return true;
	}
	if(co == 4) {
		printf("O won\n");
		return true;
	}
	return false;
}

void solve() {
	int empty = 0;
	char tmp[5];
	for(int i = 0; i < 4; ++i) {
		scanf("\n%s", s[i]);
		for(int j = 0; j < 4; ++j) if(s[i][j] == '.') {
			++empty;
		}
	}
	for(int i = 0; i < 4; ++i) {
		if(calc(s[i]))
			return;
	}
	for(int i = 0; i < 4; ++i) {
		for(int j = 0; j < 4; ++j) {
			tmp[j] = s[j][i];
		}
		if(calc(tmp))
			return;
	}
	tmp[0] = s[0][0];
	tmp[1] = s[1][1];
	tmp[2] = s[2][2];
	tmp[3] = s[3][3];
	if(calc(tmp))
		return;
	tmp[0] = s[0][3];
	tmp[1] = s[1][2];
	tmp[2] = s[2][1];
	tmp[3] = s[3][0];
	if(calc(tmp))
		return;
	if(empty) {
		printf("Game has not completed\n");
	} else {
		printf("Draw\n");
	}
}

int main(int argc, char **argv) {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for(int t = 1; t <= tt; ++t) {
		printf("Case #%d: ", t);
		solve();
		scanf("\n");
	}
	return 0;
}
