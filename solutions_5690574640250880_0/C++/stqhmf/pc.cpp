#include <cstdio>
#include <cctype>
#include <cstring>

const int MAX_R = 50;
const int MAX_C = 50;

int R; // number of rows
int C; // number of columns
int M; // number of mines

char board[MAX_R][MAX_C+1];

int di[8] = {-1,-1,-1, 0, 0,+1,+1,+1};
int dj[8] = {-1, 0,+1,-1,+1,-1, 0,+1};

bool inBoard(int i, int j)
{
  return i>=0 && i<R && j>=0 && j<C;
}

void initBoard(bool enum_mines)
{
  for ( int i=0; i<R; ++i ) {
    for ( int j=0; j<C; ++j ) {
      if ( enum_mines )
	board[i][j] = '.';
      else
	board[i][j] = '*';
    }
    board[i][C] = '\0';
  }
}

void printBoard(bool display_numbers = true)
{
  for ( int i=0; i<R; ++i ) {
    for ( int j=0; j<C; ++j ) {
      if ( isdigit(board[i][j]) && !display_numbers )
	putchar('.');
      else
	putchar(board[i][j]);
    }
    putchar('\n');
  }
  //putchar('\n');
}

void clearDigits()
{
  for ( int i=0; i<R; ++i )
    for ( int j=0; j<C; ++j )
      if ( isdigit(board[i][j]) )
	board[i][j] = '.';
}

void fill(int i, int j)
{
  board[i][j] = '0';
  for ( int k=0; k<8; ++k ) {
    int ni = i + di[k];
    int nj = j + dj[k];
    if ( inBoard(ni, nj) && board[ni][nj]=='*' ) {
      ++board[i][j];
    }
  }
  if ( board[i][j] == '0' ) {
    for ( int k=0; k<8; ++k ) {
      int ni = i + di[k];
      int nj = j + dj[k];
      if ( inBoard(ni, nj) && board[ni][nj]=='.' ) {
	fill(ni, nj);
      }
    }
  }
}

bool complete()
{
  for ( int i=0; i<R; ++i ) {
    for ( int j=0; j<C; ++j ) {
      if ( board[i][j]=='.' ) {
	return false;
      }
    }
  }
  return true;
}

bool placeClick()
{
  for ( int i=0; i<R; ++i ) {
    for ( int j=0; j<C; ++j ) {
      if ( board[i][j]=='.' ) {
	board[i][j] = 'c';
	fill(i, j);
	if ( complete() ) {
	  board[i][j] = 'c';
	  printBoard(false);
	  return true;
	}
	else {
	  clearDigits();
	}
	board[i][j] = '.';
      }
    }
  }
  return false;
}

bool placeMine(int mines_placed, int k_start, bool enum_mines)
{
  if ( mines_placed == M ) {
    //printBoard(false);puts("");
    if ( placeClick() ) {
      return true;
    }
  }
  else {
    for ( int k=k_start; k<R*C; ++k ) {
      int i = k / C;
      int j = k % C;
      if ( enum_mines ) {
	if ( board[i][j]=='.' ) {
	  board[i][j] = '*';
	  if ( placeMine(mines_placed+1, k+1, enum_mines) )
	    return true;
	  board[i][j] = '.';
	}
      }
      else {
	if ( board[i][j]=='*' ) {
	  board[i][j] = '.';
	  if ( placeMine(mines_placed-1, k+1, enum_mines) )
	    return true;
	  board[i][j] = '*';
	}
      }
    }
  }
  return false;
}

int main()
{
  int T;
  scanf("%d", &T);
  for ( int t=1; t<=T; ++t ) {
    scanf("%d %d %d", &R, &C, &M);
    bool enum_mines = M < R*C;
    enum_mines = true;

    printf("Case #%d:\n", t);
    initBoard(enum_mines);
    if ( enum_mines ) {
      if ( !placeMine(0, 0, enum_mines) )
	puts("Impossible");
    }
    else {
      if ( !placeMine(R*C, 0, enum_mines) )
	puts("Impossible");
    }
  }
}
