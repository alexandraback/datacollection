#include <cstdio>

char board[4][5];

bool check(char c) {
	bool pos;
	for(int i=0; i<4; i++) {
		pos = true;
		for(int j=0; j<4; j++)
			if(board[i][j] != c && board[i][j] != 'T')
				pos = false;
		if(pos) return true;
		pos = true;
		for(int j=0; j<4; j++)
			if(board[j][i] != c && board[j][i] != 'T')
				pos = false;
		if(pos) return true;
	}
	pos = true;
	for(int i=0; i<4; i++)
		if(board[i][i] != c && board[i][i] != 'T')
			pos = false;
	if(pos) return true;
	pos = true;
	for(int i=0; i<4; i++)
		if(board[i][3-i] != c && board[i][3-i] != 'T')
			pos = false;
	if(pos) return true;
	return false;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		for(int i=0; i<4; i++)
			scanf("%s", board[i]);
		if(check('O'))
			printf("Case #%d: O won\n", tc);
		else if(check('X'))
			printf("Case #%d: X won\n", tc);
		else {
			int count = 0;
			for(int i=0; i<4; i++)
				for(int j=0; j<4; j++)
					if(board[i][j] != '.')
						count ++;
			if(count == 16)
				printf("Case #%d: Draw\n", tc);
			else
				printf("Case #%d: Game has not completed\n", tc);
		}
	}
}
