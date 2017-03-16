#include <iostream>
#include <algorithm>
using namespace std;

int R, C, M;
char ** grid;

void possible() {
  for (int i = 0; i < R; ++i)
  {
    for (int j = 0; j < C; ++j)
    {
      cout << grid[i][j];
    }
    cout << endl;
  }
}

void impossible() {
  cout << "Impossible" << endl;
}

void solveCase() {
  cin >> R >> C >> M;
  cout << endl;

  grid = new char*[R];

  for(int i = 0; i < R; i++) {
    grid[i] = new char[C];
    for(int j = 0; j < C; j++) {
      grid[i][j] = '.';
    }
  }

  grid[R-1][C-1] = 'c';
  if(M == 0) {
    possible();
    return;
  }

  if(M == R * C - 1) {
    for (int i = 0; i < R; ++i)
    {
      for (int j = 0; j < C; ++j)
      {
        grid[i][j] = '*';
      }
    }
    grid[R-1][C-1] = 'c';
    possible();
    return;
  }

  if(C==1 || R == 1) {
    bool d = C == 1;

    for (int i = 0; i < M; ++i)
    {
      grid[d?i:R-1][d?C-1:i] = '*';
    }
    possible();
    return;
  }

  if(C==2) {
    if(M % 2 != 0) {
      impossible();
      return;
    }
    else {
      if(R*2 - M < 4) {
        impossible();
        return;
      }
      for(int i = 0; M!= 0;i++)
      {
        grid[i][C-1] = '*';
        grid[i][C-2] = '*';
        M-=2;
      }
    }
    possible();
    return;
  }

  if(R==2) {
    if(M % 2 != 0) {
      impossible();
      return;
    }
    else {
      if(C*2 - M < 4) {
        impossible();
        return;
      }
      for(int i = 0; M!= 0;i++)
      {
        grid[R-1][i] = '*';
        grid[R-2][i] = '*';
        M-=2;
      }
    }
    possible();
    return;
  }

  int temp = M;
  for (int i = 0; i < (C-2) && temp!= 0; ++i) 
  {
    for (int j = 0; j < (R-2) && temp != 0; ++j)
    {
      grid[j][i] = '*';
      temp--;
    }
  }

  if((C-2)*(R-2) >= M) {
    possible();
    return;
  }

  int rem = M - (C-2)*(R-2);

  if(rem % 2 == 0) {
    for(int i=0;i<R-2 && rem != 0;i++){
      grid[i][C-2] = '*';
      grid[i][C-1] = '*';
      rem-=2;
    }

    for(int i=0;i<C-2 && rem != 0;i++){
      grid[R-2][i] = '*';
      grid[R-1][i] = '*';
      rem-=2;
    }

    if(rem) {
      impossible();
      return;
    }
    possible();
    return;

  }
  else
  {
    rem++;
    grid[R-3][C-3] = '.';
    for(int i=0;i<C-3 && rem != 0;i++){
      grid[R-2][i] = '*';
      grid[R-1][i] = '*';
      rem-=2;
    }

    for(int i=0;i<R-3 && rem != 0;i++){
      grid[i][C-2] = '*';
      grid[i][C-1] = '*';
      rem-=2;
    }

    if(rem){
      impossible();
    }
    else
    {
      possible();
    }
    return;
  }


}

int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; i++) {
    cout << "Case #" << i << ":";
    solveCase();
  }
}