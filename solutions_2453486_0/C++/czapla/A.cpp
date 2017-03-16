#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<cassert>
using namespace std;
#define X first
#define Y second
#define RED 0
#define GREEN 1
#define BLUE 2
typedef long long LL;
//typedef __int128_t VL;
typedef long double LD;

char board[4][5];

bool won(char player){
	for(int i = 0; i < 4; i++){
		bool OK = true;
		for(int j = 0; j < 4; j++)
			if(board[i][j] == 'T' || board[i][j] == player){}
			else
				OK = false;
		if(OK)
			return true;
	}
	for(int j = 0; j < 4; j++){
		bool OK = true;
		for(int i = 0; i < 4; i++)
			if(board[i][j] == 'T' || board[i][j] == player){}
			else
				OK = false;
		if(OK)
			return true;
	}
	{
		bool OK = true;
		for(int i = 0; i < 4; i++)
			if(board[i][i] == 'T' || board[i][i] == player){}
			else
				OK = false;
		if(OK)
			return true;
	}
	{
		bool OK = true;
		for(int i = 0; i < 4; i++)
			if(board[i][3-i] == 'T' || board[i][3-i] == player){}
			else
				OK = false;
		if(OK)
			return true;
	}
}

bool full(){
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(board[i][j] == '.')
				return false;
	return true;
}

int main(){
	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		for(int i = 0; i < 4; i++)
			scanf(" %s", board[i]);
			
		printf("Case #%d: ", t);
		
		if(won('X'))
			printf("X won");
		else if(won('O'))
			printf("O won");
		else if(!full())
			printf("Game has not completed");
		else
			printf("Draw");
		printf("\n");
	
	
	

	}
	return 0;
}
