#include <cstdio>

using namespace std;

char field[10][10];

bool any(char c){
	for(int i=0; i<4; ++i)
		for(int j=0; j<4; ++j)
			if(field[i][j] == c)
				return true;
	return false;
}

bool win(char c){
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			if(field[i][j] != c && field[i][j] != 'T')
				goto next0;
		}
		return true;
next0:
		;
	}
	for(int i=0; i<4; ++i){
		for(int j=0; j<4; ++j){
			if(field[j][i] != c && field[j][i] != 'T')
				goto next1;
		}
		return true;
next1:
		;
	}
	for(int i=0; i<4; ++i){
		if(field[i][i] != c && field[i][i] != 'T')
			goto next2;
	}
	return true;
next2:
	;
	for(int i=0; i<4; ++i){
		if(field[3-i][i] != c && field[3-i][i] != 'T')
			goto next3;
	}
	return true;
next3:
	;
	return false;
}

int main(){
	int tc, tcn;
	scanf("%d", &tcn);
	for(tc=0; tc<tcn; ++tc){
		printf("Case #%d: ", tc+1);
		for(int i=0; i<4; ++i){
			scanf("%s", field[i]);
		}
		if(win('X')){
			puts("X won");
		}else if(win('O')){
			puts("O won");
		}else if(any('.')){
			puts("Game has not completed");
		}else{
			puts("Draw");
		}
	}
}
