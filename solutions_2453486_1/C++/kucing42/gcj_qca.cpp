#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm> 
#include <iostream>
#include <cmath>
using namespace std;
char board[100][100];
int t;
char c;
int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	scanf("%d",&t);
	for (int tc = 1; tc <=t; ++tc){
		printf("Case #%d: ",tc);
		for (int i = 0; i < 4; ++i)
			scanf("%s",board[i]);
		//for (int i = 0; i < 4; ++i)
		//	puts(board[i]);
		bool lol = 0;
		for (int i = 0; i < 4; ++i){
			c = 'X';
			lol = 1;
			for (int j = 0; j < 4; ++j)
				if (board[i][j] != c && board[i][j] != 'T'){
					lol = 0; break;
				}
			if (lol) puts("X won");
			if (lol) break;
			lol = 1;
			for (int j = 0; j < 4; ++j)
				if (board[j][i] != c && board[j][i] != 'T'){
					lol = 0; break;
				}
			if (lol) puts("X won");
			if (lol) break;
			c = 'O';
			lol = 1;
			for (int j = 0; j < 4; ++j)
				if (board[i][j] != c && board[i][j] != 'T'){
					lol = 0; break;
				}
			if (lol) puts("O won");
			if (lol) break;
			lol = 1;
			for (int j = 0; j < 4; ++j)
				if (board[j][i] != c && board[j][i] != 'T'){
					lol = 0; break;
				}
			if (lol) puts("O won");
			if (lol) break;
		}
		if (lol) continue;
		lol = 1;
		c = 'X';
		for (int i = 0; i < 4; ++i)
			if (board[i][i] != c && board[i][i] != 'T'){
				lol = 0; break;
			}
		if (lol) puts("X won");
		if (lol) continue;
		lol = 1;
		for (int i = 0; i <4; ++i)
			if (board[i][3-i] != c && board[i][3-i] != 'T'){
				lol = 0; break;
			}
		if (lol) puts("X won");
		if (lol) continue;
		c = 'O';
		lol = 1;
		for (int i = 0; i < 4; ++i)
			if (board[i][i] != c && board[i][i] != 'T'){
				lol = 0; break;
			}
		if (lol) puts("O won");
		if (lol) continue;
		lol = 1;
		for (int i = 0; i <4; ++i)
			if (board[i][3-i] != c && board[i][3-i] != 'T'){
				lol = 0; break;
			}
		if (lol) puts("O won");
		if (lol) continue;
		lol = 1;
		for (int i = 0; i <4; ++i)
			for (int j = 0; j < 4; ++j)
				if (board[i][j] == '.') lol = 0;
		if (lol) puts("Draw"); else puts("Game has not completed");
		
	}
}