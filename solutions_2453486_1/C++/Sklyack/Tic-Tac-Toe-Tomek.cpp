#include <cstdio>

const int BoardSize=4;
char board[BoardSize][BoardSize+1];

bool check_line(int x0, int y0, int dx, int dy, char p)
{
	int x, y;
	for(x=x0, y=y0; 0<=x && x<BoardSize && 0<=y && y<BoardSize; x+=dx, y+=dy)
		if(board[x][y]!=p && board[x][y]!='T')
			return false;
	return true;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	const int Not_ended=-1, Draw=0, X_won=1, O_won=2;
	int t, T;
	int x, y, i;
	int state;

	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		for(x=0; x<BoardSize; ++x)
			scanf("%s", board[x]);

		printf("Case #%d: ", t);
		state=Draw;
		for(i=0; i<BoardSize; ++i)
		{
			if(check_line(i, 0, 0, 1, 'X') ||
				check_line(0, i, 1, 0, 'X'))
				state=X_won;
			if(check_line(i, 0, 0, 1, 'O') ||
				check_line(0, i, 1, 0, 'O'))
				state=O_won;
		}
		if(check_line(0, 0, 1, 1, 'X') ||
			check_line(0, BoardSize-1, 1, -1, 'X'))
			state=X_won;
		if(check_line(0, 0, 1, 1, 'O') ||
			check_line(0, BoardSize-1, 1, -1, 'O'))
			state=O_won;
		if(state==X_won)
		{
			printf("X won\n");
			continue;
		}
		if(state==O_won)
		{
			printf("O won\n");
			continue;
		}
		for(x=0; x<BoardSize; ++x)
			for(y=0; y<BoardSize; ++y)
				if(board[x][y]=='.')
					state=Not_ended;
		if(state==Draw)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	return 0;
}
