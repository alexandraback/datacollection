#include <iostream>
#include <cstdio>
using namespace std;
#define forn(i,n) for(int i = 0;i < (int)(n); i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;i--)

char board[4][4];

bool won(char player)
{
	forn(r,4){
		 int symb = 0, t = 0;
		 forn(c,4){
			if(board[r][c] == player) symb++;
			if(board[r][c] == 'T') t++;
		 }
		 if(symb + t == 4 && t < 2) return true;
	}

	forn(c,4){
		 int symb = 0, t = 0;
		 forn(r,4){
			if(board[r][c] == player) symb++;
			if(board[r][c] == 'T') t++;
		 }
		 if(symb + t == 4 && t < 2) return true;
	}
	int symb = 0, t = 0;
	forn(dr,4){
		if(board[dr][dr] == player) symb++;
		if(board[dr][dr] == 'T') t++;
	}
	if(symb + t == 4 && t < 2) return true;
	symb = t = 0;
	forn(dr,4){
		if(board[3-dr][dr] == player) symb++;
		if(board[3-dr][dr] == 'T') t++;
	}
	if(symb + t == 4 && t < 2) return true;
	return false;	
}

bool no_moves()
{
	forn(i,4) forn(j,4) 
		if(board[i][j] == '.')
			return false;
	return true;
}

string solve()
{
	if(won('X')) return "X won";
	if(won('O')) return "O won";
	if(no_moves()) return "Draw";
	return "Game has not completed";
}
int main()
{
	int tcases; cin >> tcases;
	forsn(tcase,1,tcases+1){
		forn(i,4) forn(j,4) cin >> board[i][j];
		cout << "Case #" << tcase << ": " << solve() << endl;
	}
	return 0;
}
