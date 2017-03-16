#include <stdio.h>
char s[10][10];
int check() {
  for (int i = 0; i < 4; i++) {
    bool flag = true;
    char pat = '@';
    for (int j = 0; j < 4; j++) {
      if (s[i][j] == 'T') continue;
      if (s[i][j] == '.') flag = false;
      if (pat == '@') {
        pat = s[i][j];
      }
      if (s[i][j] != pat) flag = false;
    }
    if (flag) return pat == 'O' ? 0 : 1;
  }
  for (int i = 0; i < 4; i++) {
    bool flag = true;
    char pat = '@';
    for (int j = 0; j < 4; j++) {
      if (s[j][i] == 'T') continue;
      if (s[i][j] == '.') flag = false;
      if (pat == '@') {
        pat = s[j][i];
      }
      if (s[j][i] != pat) flag = false;
    }
    if (flag) return pat == 'O' ? 0 : 1;
  }
  bool flag = true;
  char pat = '@';
  for (int i = 0; i < 4; i++) {
    if (s[i][i] == 'T') continue;
      if (s[i][i] == '.') flag = false;
    if (pat == '@') pat = s[i][i];
    if (s[i][i] != pat) flag = false;
  }
  if (flag) return pat == 'O' ? 0 : 1;
  flag = true;
  pat = '@';
  for (int i = 0; i < 4; i++) {
    if (s[i][3 - i] == 'T') continue;
      if (s[i][3 - i] == '.') flag = false;
    if (pat == '@') pat = s[i][3 - i];
    if (s[i][3 - i] != pat) flag = false;
  }
  if (flag) return pat == 'O' ? 0 : 1;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++)
      if (s[i][j] == '.') return 3;
  return 2;
}
int main() {
  int T, cp = 0;
  for (scanf("%d", &T); T; T--) {
    for (int i = 0; i < 4; i++) scanf("%s", s[i]);
    int ans = check();
    printf("Case #%d: ", ++cp);
    if (ans == 0) puts("O won");
    if (ans == 1) puts("X won");
    if (ans == 2) puts("Draw");
    if (ans == 3) puts("Game has not completed");
  }
  return 0;
}
