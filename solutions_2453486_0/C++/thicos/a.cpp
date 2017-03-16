#include <cstdio>
#include <cstring>
#define REP(i,n) for(int i = 0; i<(n); i++)
char board[10][10];

char solve(){
	char tmp;
	bool complete = true;
	REP(i,4) REP(j,4) if (board[i][j] == '.') complete = false;
	REP(i, 4){
		tmp = board[i][0];
		if (tmp == 'T') tmp = board[i][1];
		if (tmp == '.') continue;
		bool flag = true;
		REP(j, 4){
			if (board[i][j] != tmp && board[i][j] != 'T'){
				flag = false;
				break;
			}
		}
		if (flag) return tmp;
	}
	REP(i, 4){
		tmp = board[0][i];
		if (tmp == 'T') tmp = board[1][i];
		if (tmp == '.') continue;
		bool flag = true;
		REP(j, 4){
			if (board[j][i] != tmp && board[j][i] != 'T'){
				flag = false;
				break;
			}
		}
		if (flag) return tmp;
	}
	tmp = board[0][0];
	if (tmp == 'T') tmp = board[1][1];
	if (tmp != '.'){
		bool flag = true;
		REP(i, 4){
			if (board[i][i] != tmp && board[i][i] != 'T'){
				flag = false;
				break;
			}
		}
		if (flag) return tmp;
	}
	tmp = board[0][3];
	if (tmp == 'T') tmp = board[1][2];
	if (tmp != '.'){
		bool flag = true;
		REP(i, 4){
			if (board[i][3-i] != tmp && board[i][3-i] != 'T'){
				flag = false;
				break;
			}
		}
		if (flag) return tmp;
	}
	if (complete) return 'D';
	return 'N';
}

int main(){
	int T;
	scanf("%d", &T);
	REP(t,T){
		REP(i,4) scanf("%s\n", board[i]);
		char res = solve();
		printf("Case #%d: ",t+1);
		switch (res){
			case 'X':
			case 'O':
				printf("%c won\n", res);
				break;
			case 'D':
				printf("Draw\n");
				break;
			case 'N':
				printf("Game has not completed\n");
				break;
		}
	}
	return 0;
}