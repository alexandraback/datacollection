#include <stdio.h>

enum Square {
  Player_X  = 0x1,
  Player_O  = 0x2,
  Special_T = 0x3,
  Nothing   = 0x0
};

static Square board[4][4];

static
bool CheckWin(Square aPlayer)
{
  for (int i=0; i<4; ++i) {
    if ((board[i][0] & aPlayer) && (board[i][1] & aPlayer) &&
        (board[i][2] & aPlayer) && (board[i][3] & aPlayer)) {
      return true;
    }
  }

  for (int i=0; i<4; ++i) {
    if ((board[0][i] & aPlayer) && (board[1][i] & aPlayer) &&
        (board[2][i] & aPlayer) && (board[3][i] & aPlayer)) {
      return true;
    }
  }

  if ((board[0][0] & aPlayer) && (board[1][1] & aPlayer) &&
      (board[2][2] & aPlayer) && (board[3][3] & aPlayer)) {
    return true;
  }

  if ((board[0][3] & aPlayer) && (board[1][2] & aPlayer) &&
      (board[2][1] & aPlayer) && (board[3][0] & aPlayer)) {
    return true;
  }

  return false;
}

int main()
{
  int T;
  scanf("%d\n", &T);

  for (int t=1; t<=T; ++t) {
    bool hasEmptySpace = false;

    for (int i=0; i<4; ++i) {
      char line[4];
      scanf("%s\n", &line);
      for (int j=0; j<4; ++j) {
        Square square = Nothing;
        switch (line[j]) {
          case 'X':
            square = Player_X;
            break;
          case 'O':
            square = Player_O;
            break;
          case 'T':
            square = Special_T;
            break;
          case '.':
            hasEmptySpace = true;
            break;
        }
        board[i][j] = square;
      }
    }

    if (CheckWin(Player_X)) {
      printf("Case #%d: X won\n", t);
      continue;
    }

    if (CheckWin(Player_O)) {
      printf("Case #%d: O won\n", t);
      continue;
    }

    if (!hasEmptySpace) {
      printf("Case #%d: Draw\n", t);
    } else {
      printf("Case #%d: Game has not completed\n", t);
    }
  }

  return 0;
}
