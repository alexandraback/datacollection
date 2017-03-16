#include <iostream>

using namespace std;

char B[10][10];

bool check_row(int x, char s) {
  for (int i=0;i<4;i++) {
    if (B[x][i] != s && B[x][i] != 'T') return false;
  }
  return true;
}
bool check_col(int x, char s) {
  for (int i=0;i<4;i++) {
    if (B[i][x] != s && B[i][x] != 'T') return false;
  }
  return true;
}

bool all_good(char s, char p1, char p2, char p3, char p4) {
  if (p1 != 'T' && p1 != s) return false;
  if (p2 != 'T' && p2 != s) return false;
  if (p3 != 'T' && p3 != s) return false;
  if (p4 != 'T' && p4 != s) return false;
  return true;
}

bool checkd1(char s) {
  return all_good(s, B[0][0], B[1][1], B[2][2], B[3][3])
    || all_good(s, B[0][3], B[1][2], B[2][1], B[3][0]);
}

bool check(char s) {
  for (int i=0;i<4;i++) {
    if (check_row(i, s)) { return true; }
    if (check_col(i, s)) { return true; }
  }
  if (checkd1(s)) return true;
  return false;
}

bool check_x() {
  return check('X');
}
bool check_o() {
  return check('O');
}

bool has_dot() {
  for (int i=0;i<4;i++) {
    for (int j=0; j<4; j++) {
      if (B[i][j] == '.') return true;
    }
  }
  return false;
}

int main() {
  int N;
  scanf("%d", &N);
  for (int c=1; c<=N; c++) {
    for (int j=0; j<4; j++) {
      scanf("%s", B[j]);
    }
    printf("Case #%d: ", c);
    if (check_x()) {
      printf("X won");
    } else if (check_o()) {
      printf("O won");
    } else if (has_dot()) {
      printf("Game has not completed");
    } else {
      printf("Draw");
    }
    printf("\n");
  }
}
