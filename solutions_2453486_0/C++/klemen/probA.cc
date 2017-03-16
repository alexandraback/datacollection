#include <stdio.h>

#define SIZE 4

int T = 0;
char field[SIZE][SIZE + 2];

char message[4][30] = {"X won", "O won", "Draw", "Game has not completed"};

bool won(char player) {
  // rows
  for (int y = 0; y < SIZE; y++) {
    int count = 0;
    for (int x = 0; x < SIZE; x++)
      if (field[y][x] == player || field[y][x] == 'T')
        count++;
    if (count == SIZE)
      return true;
  }
  // columns
  for (int x = 0; x < SIZE; x++) {
    int count = 0;
    for (int y = 0; y < SIZE; y++)
      if (field[y][x] == player || field[y][x] == 'T')
        count++;
    if (count == SIZE)
      return true;
  }
  // diagonals
  int cd1 = 0;
  int cd2 = 0;
  for (int y = 0; y < SIZE; y++) {
    if (field[y][y] == player || field[y][y] == 'T')
      cd1++;
    if (field[y][SIZE - 1 - y] == player || field[y][SIZE - 1 - y] == 'T')
      cd2++;
  }
  return cd1 == SIZE || cd2 == SIZE;
}

bool full() {
  for (int y = 0; y < SIZE; y++)
    for (int x = 0; x < SIZE; x++)
      if (field[y][x] == '.')
        return false;
  return true;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    for (int i = 0; i < SIZE; i++)
      scanf("%s", field[i]);

    int answer = 0;
    if (won('X'))
      answer = 0;
    else if (won('O'))
      answer = 1;
    else if (full())
      answer = 2;
    else
      answer = 3;
    printf("Case #%d: %s\n", t + 1, message[answer]);
  }
}
