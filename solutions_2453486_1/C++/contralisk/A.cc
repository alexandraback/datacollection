#include <ctype.h>
#include <stdio.h>
#include <string.h>

char board[4][4 + 1];
char a[100];

const char* result[] = {
  "X won",
  "O won",
  "Draw",
  "Game has not completed",
};

int main() {
  int num_tests = 0;
  scanf("%d", &num_tests);
  gets(a);
  for (int test = 1; test <= num_tests; ++test) {
    for (int i = 0; i < 4; ++i)
      gets(board[i]);
    gets(a);
    /*
    for (int i = 0; i < 4; ++i)
      printf("%s\n", board[i]);
    */
    int r = 2;
    bool has_empty_cells = false;
    int d_x = 0, d_o = 0, b_x = 0, b_o = 0;
    for (int i = 0; i < 4; ++i) {
      char c;
      c = board[i][i];
      if (c == 'X' || c == 'T')
        ++d_x;
      if (c == 'O' || c == 'T')
        ++d_o;
      c = board[i][3 - i];
      if (c == 'X' || c == 'T')
        ++b_x;
      if (c == 'O' || c == 'T')
        ++b_o;
      int h_x = 0, h_o = 0, v_x = 0, v_o = 0;
      for (int j = 0; j < 4; ++j) {
        // -
        c = board[i][j];
        if (c == 'X' || c == 'T')
          ++h_x;
        if (c == 'O' || c == 'T')
          ++h_o;
        // |
        c = board[j][i];
        if (c == 'X' || c == 'T')
          ++v_x;
        if (c == 'O' || c == 'T')
          ++v_o;
        if (c == '.')
          has_empty_cells = true;
      }
      if (h_x == 4 || v_x == 4) {
        r = 0;
        break;
      }
      if (h_o == 4 || v_o == 4) {
        r = 1;
        break;
      }
    }
    if (d_x == 4 || b_x == 4) {
      r = 0;
    }
    else if (d_o == 4 || b_o == 4) {
      r = 1;
    }
    else if (r == 2 && has_empty_cells) {
      r = 3;
    }
    printf("Case #%d: %s\n", test, result[r]);
  }
  return 0;
}
