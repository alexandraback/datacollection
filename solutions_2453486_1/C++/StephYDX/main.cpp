#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool checkwin(char game[][5], char player){
	for(int i = 0;i < 4; ++i){
		bool checkRow = true, checkCol = true;
		for(int j = 0;j < 4; ++j){
			if(game[i][j] != player && game[i][j] != 'T') checkRow = false;
			if(game[j][i] != player && game[j][i] != 'T') checkCol = false;
		}
		if(checkRow || checkCol) return true;
	}
	bool checkDiag1 = true, checkDiag2 = true;
	for(int i = 0;i < 4; ++i){
		if(game[i][i] != player && game[i][i] != 'T') checkDiag1 = false;
		if(game[i][3 - i] != player && game[i][3 - i] != 'T') checkDiag2 = false;
	}
	return checkDiag1 || checkDiag2;
}

bool checkFilled(char game[][5]){
	for(int i = 0;i < 4; ++i){
		for(int j = 0;j < 4; ++j){
			if(game[i][j] == '.') return false;
		}
	}
	return true;
}

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	for(int cas = 1;cas <= TT; ++cas){
		char game[4][5];
		scanf("%s %s %s %s", game, game + 1, game + 2, game + 3);
		printf("Case #%d: ", cas);
		if(checkwin(game, 'X')){
			puts("X won");
		}
		else if(checkwin(game, 'O')){
			puts("O won");
		}
		else if(checkFilled(game)){
			puts("Draw");
		}
		else puts("Game has not completed");
	}
	return 0;
}
