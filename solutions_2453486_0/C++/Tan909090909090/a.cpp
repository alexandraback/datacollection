#include<stdio.h>

char m[4][4];

bool IsWin(char player){
	auto IsWinAtSeq = [player](int x1, int dx, int y1, int dy){
		auto IsOwned = [player](char c){
			return c==player || c=='T';
		};
		for(int x=x1, y=y1, times=4; times--; x+=dx, y+=dy){
			if(!IsOwned(m[y][x]))
				return false;
		}
		return true;
	};

	// diagonal
	bool isWin =
		IsWinAtSeq(0,1,0,1) || 
		IsWinAtSeq(3,-1,0,1);
	// row
	for(int i=0; i<4; ++i)
		isWin = isWin || IsWinAtSeq(0,1,i,0);
	// col
	for(int i=0; i<4; ++i)
		isWin = isWin || IsWinAtSeq(i,0,0,1);

	return isWin;
}



int main() {
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum = 1; caseNum <= T; ++caseNum) {

		int emptyCount = 0;
		for(int y=0; y<4; ++y)
			for(int x=0; x<4; ++x){
				scanf(" %c",&m[y][x]);
				if(m[y][x]=='.')
					++emptyCount;
			}



		char *result = 
			IsWin('X') ? "X won" :
			IsWin('O') ? "O won" :
			emptyCount ? "Game has not completed" : 
			"Draw";

		printf("Case #%d: ", caseNum);
		puts(result);
	}
	return 0;
}
