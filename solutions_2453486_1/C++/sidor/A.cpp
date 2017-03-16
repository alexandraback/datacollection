#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int ntc;

const int N = 4;
const char EMPTY = '.';
const char GX = 'X';
const char GO = 'O';
const char GT = 'T';

char x[10][10];

bool checkwin(char p) {
  //diagonal
  bool assume = true;
  for(int i=0; i<N; ++i) {
    if(x[i][i] != GT && x[i][i] != p) assume = false;
  }
  if(assume) return true;
  assume = true;
  for(int i=0; i<N; ++i) {
    if(x[i][N-i-1] != GT && x[i][N-i-1] != p) assume = false;
  }
  if(assume) return true;
  for(int i=0; i<N; ++i) {
    assume = true;
    for(int j=0; j<N; ++j) {
      if(x[i][j] != GT && x[i][j] != p) assume = false;
    }
    if(assume) return true;
    assume = true;
    for(int j=0; j<N; ++j) {
      if(x[j][i] != GT && x[j][i] != p) assume = false;
    }
    if(assume) return true;
  }
  return false;
}

void solve(int c) {
  for(int i=0; i<N; ++i) {
    scanf(" %s", x[i]);
  }
  bool filled = true;
  bool owin = checkwin(GO);
  bool xwin = checkwin(GX);
  for(int i=0; i<N; ++i) {
    for(int j=0; j<N; ++j) {
      if(x[i][j] == EMPTY) filled = false;
    }
  }
  string res;
  if(owin && xwin) {
    res = string("INVALID");
  } else if(owin) {
    res = string("O won");
  } else if(xwin) {
    res = string("X won");
  } else if(filled) {
    res = string("Draw");
  } else {
    res = string("Game has not completed");
  }
  printf("Case #%d: %s\n",c, res.c_str() );
}



int main() {
  scanf("%d", &ntc);
  for(int i=1; i<=ntc; ++i) {
    solve(i);
  }
}
