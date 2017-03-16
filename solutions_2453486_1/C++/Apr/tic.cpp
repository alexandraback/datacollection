#include <cstdio>

char board[4][4];

bool solve_for(char c) {
  bool win = false;
  for(int i = 0;i < 4; i++) {
    int count = 0;
    for(int j = 0; j < 4; j++)  {
      count += (board[i][j] == c || board[i][j] == 'T');
    }
    //printf("%c: %d\n", c, count);
    win |= (count == 4);
  }
  for(int i = 0;i < 4; i++) {
    int count = 0;
    for(int j = 0; j < 4; j++)  {
      count += (board[j][i] == c || board[j][i] == 'T');
    }
    win |= (count == 4);
  }
  for(int i = 0;i < 1; i++) {
    int count = 0;
    for(int j = 0; j < 4; j++)  {
      count += (board[j][j] == c || board[j][j] == 'T');
    }
    win |= (count == 4);
  }
  for(int i = 0;i < 1; i++) {
    int count = 0;
    for(int j = 0; j < 4; j++)  {
      count += (board[j][3-j] == c || board[j][3-j] == 'T');
    }
    win |= (count == 4);
  }
  return win;
}
unsigned char solve() {
  bool win_x = solve_for('X');
  bool win_o = solve_for('O');
  if(win_x && win_o) {
    return 1;
  }
  if(win_x) return 'X';
  if(win_o) return 'O';
  return 0;
}


int main(){
  int N;
  scanf("%d\n", &N);
  for(int n = 1; n <= N; n++) {
    bool finish = true;
    for(int i=0; i < 4; i++) 
    {
      for(int j = 0; j < 4; j++) {
        scanf("%c", &board[i][j]);
        if(board[i][j] == '.') finish = false;
      }
      scanf("\n");
    }
    printf("Case #%d: ", n);
    unsigned char res = solve();
    if(res == 0) {
      if(finish) {
      printf("Draw");
      } else {
      printf("Game has not completed");
      }
    } else {
      if(res == 1) { // draw
        printf("Draw");
      } else {
        printf("%c won", res);
      }
    }
    printf("\n");
  }
  return 0;
}
