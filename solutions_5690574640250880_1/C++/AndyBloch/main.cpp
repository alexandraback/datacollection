// code jam c
int verbose = 0 ;

#include <iostream>
#include <math.h>

using namespace std ;

int countNeighbors(char board[][51],int rows, int columns, int rr, int cc) {
  int r,c;
  int count = 0;
  for (r= rr-1;r<=rr+1;r++) {
    if (r<0) continue;
    if (r>= rows) continue ;
    for (c= cc-1;c<=cc+1;c++) {
      if (c<0) continue;
      if (c>=columns) continue ;
      if ((r==rr)&&(c==cc))
        continue ;
      count += board[r][c] == '*';
    }
  }
  return count ;
}

int clickBoard(char board[][51], char board2[][51],int rows, int columns, int rr, int cc) {
  if (board[rr][cc]=='*')
    return 0;
  if (board2[rr][cc]!=' ')
    return 0;
  int n = countNeighbors(board, rows, columns, rr, cc);
  board2[rr][cc] = n+'0';
  if (n)
    return 1;
  int r,c;
  int count = 1;
  for (r= rr-1;r<=rr+1;r++) {
    if (r<0) continue;
    if (r>= rows) continue ;
    for (c= cc-1;c<=cc+1;c++) {
      if (c<0) continue;
      if (c>=columns) continue ;
      if ((r==rr)&&(c==cc))
        continue ;
      count += clickBoard(board,board2,rows,columns,r,c);
    }
  }
  return count ;
}

void clearBoard(char board[][51],int rows,int columns){
  int r;
  int c;
  for (r = 0 ; r < rows ; r++) {
    for (c = 0 ; c < columns ; c++) {
      board[r][c] = ' ' ;
    }
    board[r][c]=0;
  }
}
int runTest() {
  int rows ;
  int columns ;
  int mines ;
  cin >> rows ;
  cin >> columns ;
  cin >> mines ;
//  if (verbose)
//    cout << "// A=" << A << " B=" << B << endl ;
  char board[50][51];
  int r;
  int c;
  int m = 0 ;
  int emptySpots = rows*columns - mines ;
  for (r = 0 ; r < rows ; r++) {
    for (c = 0 ; c<columns; c++) {
      board[r][c] = '.';
    }
    board[r][c] = 0;
  }
  if (emptySpots<=0) {
    cout << endl << "Impossible" << endl ;
    return 1;
  }
  if (emptySpots==1) {
    for (r = 0 ; r < rows ; r++) {
      for (c = 0 ; c<columns; c++) {
        board[r][c] = '*';
      }
    }
    board[rows-1][columns-1] = 'c' ;
  }
  else if ((rows==2)&&(columns==2)) {
    if (emptySpots != 4) {
      cout << endl << "Impossible" << endl ;
      return 1;
    }
    board[rows-1][columns-1] = 'c' ;
  }
  else if (mines == 0) {
    board[rows-1][columns-1] = 'c' ;
  }
  else if (rows == 1) {
    for (c = 0 ; c < mines ; c++)
      board[0][c] = '*';
  }
  else if (columns == 1) {
    for (r = 0 ; r < mines ; r++)
      board[r][0] = '*';
  }
  else if (rows==2) {
    if ((mines&1)||(emptySpots==2)) {
      cout << endl << "Impossible" << endl ;
      return 1;
    }
    for (c = 0 ; c < mines/2 ; c++) {
      board[0][c] = '*';
      board[1][c] = '*';
    }
  }
  else if (columns==2) {
    if ((mines&1)||(emptySpots==2)) {
      cout << endl << "Impossible" << endl ;
      return 1;
    }
    for (r = 0 ; r < mines/2 ; r++) {
      board[r][0] = '*';
      board[r][1] = '*';
    }
  }
  else if (emptySpots <=9) {
    if ((emptySpots == 7) || (emptySpots == 5) || (emptySpots == 3) || (emptySpots == 2)) {
      cout << endl << "Impossible" << endl ;
      return 1;
    }
    for (r = 0 ; r < rows ; r++) {
      for (c = 0 ; c<columns; c++) {
        board[r][c] = '*';
      }
    }
    board[rows-1][columns-1] = 'c' ;
    if (emptySpots >= 4) {
      board[rows-1][columns-2] = '.' ;
      board[rows-2][columns-2] = '.' ;
      board[rows-2][columns-1] = '.' ;
    }
    if (emptySpots >= 6) {
      board[rows-1][columns-3] = '.' ;
      board[rows-2][columns-3] = '.' ;
    }
    if (emptySpots >= 8) {
      board[rows-3][columns-2] = '.' ;
      board[rows-3][columns-1] = '.' ;
    }
    if (emptySpots == 9) {
      board[rows-3][columns-3] = '.' ;
      board[rows-3][columns-3] = '.' ;
    }
  }
  else {
    if (verbose)
      cout << "General solution." << endl ;
    int i ;
    for (i = 0 ; (i < rows-2) || (i<columns-2) ; i++ ) {
      for (r = 0 ; r < i ; r++) {
        if (r >= rows-2)
          break;
        if (i >= columns-2)
          break;
        if (m < mines) {
          board[r][i] = '*' ;
          m++;
          if (verbose)
            cout << "i: " << i<< " r: " << r << " *" << endl ;
        }
      }
      for (c = 0 ; c < i  ; c++) {
        if (c >= columns-2)
          break;
        if (i >= rows-2)
          break;
        if (m < mines) {
          board[i][c] = '*' ;
          m++;
          if (verbose)
            cout << "i: " << i<< " c: " << c << " *" << endl ;
        }
      }
      if ((m < mines) &&(i < rows-2) &&(i<columns-2)){
        board[i][i] = '*' ;
        m++;
      }

    }
    if (m < mines) {
      if (verbose) {
        cout << endl ;
        for (r = 0; r<rows ; r++)
          cout << board[r]<<endl;
        cout << "Mines still left: " << mines-m << endl ;
      }
      if ((mines-m)&1) {
        if (verbose)
          cout << "Odd number of mines left." << endl ;
        board[rows-3][columns-3] = '.';
        m--;
      }
      for (r = 0 ; r < rows-3 ; r++) {
        if (m < mines) {
          board[r][columns-2]='*';
          board[r][columns-1]='*';
          m+=2;
        }
      }
      for (c = 0 ; c < columns-3 ; c++) {
        if (m < mines) {
          board[rows-2][c]='*';
          board[rows-1][c]='*';
          m+=2;
        }
      }
    }
  }
  board[rows-1][columns-1]='c';
  char board2[50][51];
  
  int count ;
  clearBoard(board2, rows, columns);
  count = clickBoard(board, board2, rows, columns, rows-1, columns-1);
  if (count != emptySpots) {
    cout << "Error! Count = " << count << ", empty spots = " << emptySpots << endl;
    cout << "Input: " << rows << " " << columns << " " << mines << endl;
    cout << endl ;
    for (r = 0; r<rows ; r++)
      cout << board2[r]<<endl;
    cout << endl ;
  }
  
  
  cout << endl ;
  for (r = 0; r<rows ; r++)
    cout << board[r]<<endl;
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

