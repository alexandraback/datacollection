#include<cstdio>

bool comp(char board[][5], char a);
int main() {
	int t;
	scanf("%d", &t);
	freopen("output.txt", "w", stdout);
	for(int z = 1 ; z <= t ; z++) {
		char board[4][5];
		int tot = 0;
		for(int i = 0 ; i < 4 ; i++) scanf("%s", board[i]);

		bool O_check, X_check;
		O_check = comp(board, 'O');
		X_check = comp(board, 'X');
		for(int i = 0 ; i < 4 ; i++) for(int j = 0 ; j < 4; j++) {
			if( board[i][j] != '.' ) tot++;
		}
		printf("Case #%d: ", z);
		if( O_check && !X_check ) printf("O won\n");
		else if( !O_check && X_check ) printf("X won\n");
		else if( !O_check && !X_check && tot != 16 ) printf("Game has not completed\n");
		else printf("Draw\n");
	}
	fclose(stdout);
}

bool comp(char board[][5], char a) {
	int i, j;
	for(i = 0 ; i < 4 ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			if( board[i][j] != a && board[i][j] != 'T' ) break;
		}
		if( j == 4 ) return true;
	}

	for(i = 0 ; i < 4 ; i++) {
		for(j = 0 ; j < 4 ; j++) {
			if( board[j][i] != a && board[j][i] != 'T' ) break;
		}
		if( j == 4 ) return true;
	}
	for(i = 0 ; i < 4 ; i++) {
		if( board[i][i] != a && board[i][i] != 'T' ) break;
	}
	if( i == 4 ) return true;
	for(i = 0 ; i < 4 ; i++) {
		if( board[i][3-i] != a && board[i][3-i] != 'T' ) break;
	}
	if( i == 4 ) return true;
	return false;
}