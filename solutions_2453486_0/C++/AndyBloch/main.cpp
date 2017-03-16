// code jam a
int verbose = 0 ;

#include <iostream>
using namespace std ;

int runTest() {
  char boardchar[4][5] ;
  cin >> boardchar[0] ;
  cin >> boardchar[1] ;
  cin >> boardchar[2] ;
  cin >> boardchar[3] ;
  if (verbose) {
    cout << boardchar[0] << endl ;
    cout << boardchar[1] << endl ;
    cout << boardchar[2] << endl ;
    cout << boardchar[3] << endl ;
  }
  
  int emptySquares = 0 ;
  int r,c;
  for (r = 0 ; r < 4 ; r++) {
    char player = 'T' ;
    for (c = 0 ; c < 4 ; c++) {
      if (boardchar[r][c]=='.') {
        player = '.' ;
        emptySquares ++ ;
        break ;
      }
      if (boardchar[r][c]=='X') {
        if (player == 'O') {
          player = '.' ;
          break ;
        }
        player = 'X' ;
      }
      if (boardchar[r][c]=='O') {
        if (player == 'X') {
          player = '.' ;
          break ;
        }
        player = 'O' ;
      }
    }
    if (player != '.') {
      cout << player << " won" << endl ;
      return 1 ;
    }
  }
  for (c = 0 ; c < 4 ; c++) {
    char player = 'T' ;
    for (r = 0 ; r < 4 ; r++) {
      if (boardchar[r][c]=='.') {
        player = '.' ;
        break ;
      }
      if (boardchar[r][c]=='X') {
        if (player == 'O') {
          player = '.' ;
          break ;
        }
        player = 'X' ;
      }
      if (boardchar[r][c]=='O') {
        if (player == 'X') {
          player = '.' ;
          break ;
        }
        player = 'O' ;
      }
    }
    if (player != '.') {
      cout << player << " won" << endl ;
      return 1 ;
    }
  }

  char player = 'T' ;
  for (c = 0 ; c < 4 ; c++) {
    r = c ;
    if (boardchar[r][c]=='.') {
      player = '.' ;
      break ;
    }
    if (boardchar[r][c]=='X') {
      if (player == 'O') {
        player = '.' ;
        break ;
      }
      player = 'X' ;
    }
    if (boardchar[r][c]=='O') {
      if (player == 'X') {
        player = '.' ;
        break ;
      }
      player = 'O' ;
    }
  }
  if (player != '.') {
    cout << player << " won" << endl ;
    return 1 ;
  }
  player = 'T' ;
  for (c = 0 ; c < 4 ; c++) {
    r = 3-c ;
    if (boardchar[r][c]=='.') {
      player = '.' ;
      break ;
    }
    if (boardchar[r][c]=='X') {
      if (player == 'O') {
        player = '.' ;
        break ;
      }
      player = 'X' ;
    }
    if (boardchar[r][c]=='O') {
      if (player == 'X') {
        player = '.' ;
        break ;
      }
      player = 'O' ;
    }
  }
  if (player != '.') {
    cout << player << " won" << endl ;
    return 1 ;
  }

  if (emptySquares) {
    cout << "Game has not completed" << endl ;
    return 1;
  }
  cout << "Draw"<< endl ;
  return 1;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  if (verbose) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  int i;
  for (i=0 ; i < testCases ; i++) {
    if (verbose)
      cout << "// Running case #" << i+1 << endl ;
    cout << "Case #" << i + 1 << ": " ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  
  return 0;
}

