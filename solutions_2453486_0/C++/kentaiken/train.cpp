#include<iostream>
#include<fstream>

using namespace std;

char board[4][4];
char currentBoard[4][4];
string ans;
bool found;
int bcount;
int ccount;
ifstream input("input.txt");
ofstream output("output.txt");

bool isEqual()
{
	int i,j;
	
	for(i =0 ; i < 4; ++i)
		for(j = 0; j< 4; ++j)
			if(board[i][j] != currentBoard[i][j]) return 0;
	return 1;
}

bool isFilled()
{
	int i,j;
	
	for(i =0 ; i < 4; ++i)
		for(j = 0; j < 4; ++j)
			if(currentBoard[i][j]=='.') return 0;
	return 1;
}

char hasWon()
{
	char prev = '!';
	int i,j;
	int count = 0;
	int xwin,owin;
	int winX,winO;
	int k;
	int t = 0;
	
	
	xwin = owin  = 0;
	for(i = 0; i < 4; ++i)
	{
		t = 0;
		winX = winO = t;
		for(j =0 ; j < 4; ++j)
		{
			if(currentBoard[i][j] == 'X') ++winX;
			else if(currentBoard[i][j] == 'O') ++winO;
			else if(currentBoard[i][j] == 'T') ++t;
		}
		if((t == 1 && (winX == 3 || winO == 3)) || winX == 4 || winO == 4)
		{
			if(winX) xwin = 1;
			else owin = 1;
		}
	}
	
	for(j = 0; j < 4; ++j)
	{
		t = 0;
		winX = winO = t;
		for(i =0 ; i < 4; ++i)
		{
			if(currentBoard[i][j] == 'X') ++winX;
			else if(currentBoard[i][j] == 'O') ++winO;
			else if(currentBoard[i][j] == 'T') ++t;
		}
		if( (t == 1 && (winX == 3 || winO == 3)) || winX == 4 || winO == 4)
		{
			if(winX) xwin = 1;
			else owin = 1;
		}
	}
	
	i = 0, j = 0;
	t = winX = winO = 0;
	
	while( i < 4)
	{
		if(currentBoard[i][j] == 'X') ++winX;
		else if(currentBoard[i][j] == 'O') ++winO;
		else if(currentBoard[i][j] == 'T') ++t;
		++i,++j;
	}
	if((t == 1 && (winX == 3 || winO == 3)) || winX == 4 || winO == 4)
	{
			if(winX) xwin = 1;
			else owin = 1;
	}
	
	i = 0, j = 3;
	t = winX = winO = 0;
	while( i < 4)
	{
		if(currentBoard[i][j] == 'X') ++winX;
		else if(currentBoard[i][j] == 'O') ++winO;
		else if(currentBoard[i][j] == 'T') ++t;
		++i,--j;
	}
	if((t == 1 && (winX == 3 || winO == 3)) || winX == 4 || winO == 4)
	{
			if(winX) xwin = 1;
			else owin = 1;
	}
	
	if(xwin and owin) return 'B';
	else if(xwin) return 'X';
	else if(owin) return 'O';
	return 'N';
}
	
		

			
	
	
				

void dfs(int turn)
{
	int i,j;
	char p;
	char r;
	if(ccount > bcount) return;
	if(isEqual())
	{
		r = hasWon();
		if(r == 'X') ans = "X won";
		else if(r == 'O') ans = "O won";
		else if(r == 'B') ans = "Draw";
		else if(isFilled()) ans = "Draw";
		else ans = "Game has not completed";
		found = true;
	}
	
	if(turn == 0) p = 'X';
	else p = 'O';
	for(i = 0; i < 4 and !found; ++i)
	{
		for(j =0 ; j < 4 and !found; ++j)
		{
			if(currentBoard[i][j] == '.' and board[i][j] == p)
			{
				currentBoard[i][j] = p;
				ccount++;
				dfs(turn^1);
				ccount--;
				currentBoard[i][j] = '.';
			}
		}
	}
}



int main()
{
	int tests;
	int i,j;
	int k;
	string buffer;
	cin.ios_base::sync_with_stdio(false);
	
	input>>tests;
	
	for(k = 1; k <= tests; ++k)
	{
		ccount = 0;
		bcount = 0;
		for(i =0 ; i < 4; ++i)
		{
			input>>buffer;
			for(j =0 ; j < 4; ++j)
			{
				board[i][j] = buffer[j];
				if(board[i][j] == 'T') currentBoard[i][j] = 'T',ccount++;
				else currentBoard[i][j] = '.';
				if(board[i][j] != '.') bcount++;
			}
		}
		found = false;
		dfs(0);
		output<<"Case #"<<k<<": "<<ans<<"\n";
	}
	input.close();
	output.close();
	return 0;
}