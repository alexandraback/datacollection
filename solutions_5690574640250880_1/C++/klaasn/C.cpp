#include "cmath"
#include "iostream"
#include "iomanip"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "cassert"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long ll;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;

#define REP(i, a, b)                                                    \
	for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define ITER(c, it) \
	for (auto it = (c).begin(); it != (c).end(); it++)

char board[51][51];
int R,C,M;

bool search() { 
  int target = R*C-M;
  // sweep the first 2 rows
  
  REP(i,1,R) {
    REP(j,1,C) {
      board[i][j] = '*';
    }
  }
  
  board[1][1] = 'c';
  if (target == 1) { return true;}

  if (C==1) {
    REP(i,2,target) { board[i][1] = '.';} 
    return true;
  }
  if (R==1) {
    REP(i,2,target) { board[1][i] = '.';} 
    return true;
  }

  board[1][2] = '.';
  board[2][1] = '.';
  board[2][2] = '.';

  for (int i=2;i<=C;i++) {
    int sweeped = 2*i;
    board[1][i] = '.';
    board[2][i] = '.';

    // clear rest of board before scan
    REP(i,3,R) {
      REP(j,1,C) {
        board[i][j] = '*';
      }
    }
    if (sweeped == target) { return true;}
    for (int row=3;row<=R;row++) {
      board[row][1] = '.';
      // single row sweep
      for (int col=2;col<=i;col++) {
        board[row][col] = '.';
        sweeped = 2*i + (row-3) * i + col;

        if (sweeped == target) { return true; }
        
      }
    }
  }

  
  // generative starting with bombs, start from top corner
  REP(i,1,R) {
    REP(j,1,C) {
      board[i][j] = '.';
    }
  }
  board[1][1] = 'c';
  int col = C;
  int sweeped = R*C;
    
  for (int row = R; row > 2 ;) {
    while(col > 2) {
      board[row][col] = '*';
      col --;
      sweeped --;
      if (sweeped == target) { return true;}
    }
    col = C;
    row--;
  }
  return false;
}


int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    cout << "Case #" << Ti << ":" << endl;
    cin >> R >> C >> M;
    int target = R*C-M;
    // sweep the first row
    // special case, single row
    // special case, only 1.
    if (target==0) { cout << "Impossible\n";}
    
    bool res = search();
    if (res) {
      int mines = 0;
      int blank = 0;
      REP(i,1,R) {
        REP(j,1,C) {
          cout << board[i][j];
          if (board[i][j] == '*') { mines++;}
          if (board[i][j] == '.') { blank++;}
        }
        cout << endl;
      }
      assert(mines == M);
      assert(blank+mines+1 == R*C);
    } else {
      // swap board
      swap(R,C);
      res = search();
      if (res) {
        REP(j,1,C) {
          REP(i,1,R) {
            cout << board[i][j];
          }
          cout << endl;
        }
      } else {
        cout << "Impossible" << endl;
      }
    }
  }
  return 0;


}
