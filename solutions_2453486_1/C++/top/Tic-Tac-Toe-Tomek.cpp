#include <cstdio>
#include <algorithm>

using namespace std;

int test;
char s[4][5];

int main () {
  scanf ("%d", &test);

  for (int Case = 1;Case <= test;Case ++) {
    for (int i = 0;i < 4;i ++) {
      scanf ("%s", s[i]);
    }

    int result = 2,dot = 0;
    for (int i = 0;i < 4;i ++) {
      int cnt0 = 0,cnt1 = 0;
      for (int j = 0;j < 4;j ++) {
	if (s[i][j] != '.' && s[i][j] != 'O') cnt0 ++;
	if (s[i][j] != '.' && s[i][j] != 'X') cnt1 ++;
	if (s[i][j] == '.') dot = 1;
      }
      if (cnt0 == 4) result = 0;
      if (cnt1 == 4) result = 1;
    }
    for (int i = 0;i < 4;i ++) {
      int cnt0 = 0,cnt1 = 0;
      for (int j = 0;j < 4;j ++) {
	if (s[j][i] != '.' && s[j][i] != 'O') cnt0 ++;
	if (s[j][i] != '.' && s[j][i] != 'X') cnt1 ++;
      }
      if (cnt0 == 4) result = 0;
      if (cnt1 == 4) result = 1;
    }

    int cnt0 = 0,cnt1 = 0;
    for (int i = 0;i < 4;i ++) {
      if (s[i][i] != '.' && s[i][i] != 'O') cnt0 ++;
      if (s[i][i] != '.' && s[i][i] != 'X') cnt1 ++;
    }
    if (cnt0 == 4) result = 0;
    if (cnt1 == 4) result = 1;

    cnt0 = cnt1 = 0;
    for (int i = 0;i < 4;i ++) {
      if (s[i][3-i] != '.' && s[i][3-i] != 'O') cnt0 ++;
      if (s[i][3-i] != '.' && s[i][3-i] != 'X') cnt1 ++;
    }
    if (cnt0 == 4) result = 0;
    if (cnt1 == 4) result = 1;

    printf ("Case #%d: ", Case);
    if (result == 0) printf ("X won\n");
    else if (result == 1) printf ("O won\n");
    else if (result == 2 && dot == 0) printf ("Draw\n");
    else printf ("Game has not completed\n");
  }
}
