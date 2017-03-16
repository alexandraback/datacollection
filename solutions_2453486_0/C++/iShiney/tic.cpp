#include <cstdio>

using namespace std;

char G[10][10];
int T;

bool is_win(char type) {
	int num=0, isT = 0;
	for(int i=0; i<4; i++) {
		for(int j=0; j<4; j++) {
			if(G[i][j] == type) {
				num++;
			} else if(G[i][j] == 'T') {
				isT = 1;
			}
		}
		if ((num == 3 && isT == 1) || num == 4)
			return 1;
		num=0, isT = 0;
	}
	for(int j=0; j<4; j++) {
		for(int i=0; i<4; i++) {
			if(G[i][j] == type) {
				num++;
			} else if(G[i][j] == 'T') {
				isT = 1;
			}
		}
		if ((num == 3 && isT == 1) || num == 4)
			return 1;
		num=0, isT = 0;
	}
	for(int i=0; i<4; i++) {
		if(G[i][i] == type) {
			num++;
		} else if(G[i][i] == 'T') {
			isT = 1;
		}
	}
	if ((num == 3 && isT == 1) || num == 4)
		return 1;
	num=0, isT = 0;
	for(int i=0; i<4; i++) {
		if(G[i][3-i] == type) {
			num++;
		} else if(G[i][3-i] == 'T') {
			isT = 1;
		}
	}
	if ((num == 3 && isT == 1) || num == 4)
		return 1;
	return 0;
}

bool is_game_over() {
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if (G[i][j] == '.')
				return false;
	return true;
}

int main() {
	freopen("tic.in", "r", stdin);
	scanf("%d", &T);
	for(int asdf=1; asdf<=T; asdf++) {
		if (asdf != 1) scanf("\n");
		for(int i=0; i<4; i++)
			scanf("%s\n", &G[i]);
		if (is_win('X'))
			printf("Case #%d: X won\n", asdf);
		else if (is_win('O'))
			printf("Case #%d: O won\n", asdf);
		else if (!is_game_over())
			printf("Case #%d: Game has not completed\n", asdf);
		else
			printf("Case #%d: Draw\n", asdf);
	}

	return 0;
}
