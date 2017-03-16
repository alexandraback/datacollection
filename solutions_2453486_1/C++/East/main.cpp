#include<stdio.h>

char LineVictor(char a, char b, char c, char d)
{
	char line[4]={a,b,c,d};
	int o=0, x=0, t=0;
	for(int i=0;i<4;i++) {
		if(line[i]=='O') ++o;
		else if(line[i]=='X') ++x;
		else if(line[i]=='T') ++t;
	}
	if(o==3 && t==1 || o==4) return 'O';
	else if(x==3 && t==1 || x==4) return 'X';
	return NULL;
}

class CTomek
{
	char board[4][5];
public:
	void ScanInput()
	{
		for(int i=0;i<4;i++)
			scanf("%s\n",board[i]);
	}
	bool IsBoardFull()
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(board[i][j]=='.') return false;
		return true;
	}
	char GetVictor()
	{
		for(int i=0;i<4;i++)
		{
			char v = LineVictor(board[i][0], board[i][1], board[i][2], board[i][3]);
			if(v) return v;
			v = LineVictor(board[0][i], board[1][i], board[2][i], board[3][i]);
			if(v) return v;
		}
		char v = LineVictor(board[0][0], board[1][1], board[2][2], board[3][3]);
		if(v) return v;
		v = LineVictor(board[0][3], board[1][2], board[2][1], board[3][0]);
		if(v) return v;
		if(IsBoardFull())
			return NULL;
		return '.';
	}
};

int main()
{
	int T;
	CTomek tictac;
	scanf("%d\n",&T);
	for(int i=1;i<=T;i++)
	{
		tictac.ScanInput();
		char v = tictac.GetVictor();
		printf("Case #%d: ",i);
		if(v=='X') printf("X won\n");
		else if(v=='O') printf("O won\n");
		else if(v=='.') printf("Game has not completed\n");
		else printf("Draw\n");
	}
	return 0;
}