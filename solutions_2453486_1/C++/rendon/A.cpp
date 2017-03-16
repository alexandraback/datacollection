#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <complex>
#include <algorithm>
using namespace std;

const int BUFFER_SIZE = 1 * 1024;
const double EPS      = 10e-6;
const int MAX         = 100;
const int INF         = 1 << 30;


bool win(char B[5][5], char player)
{
  int i, j, t, count;
  for (i = 0; i < 4; i++) {
    count = t = 0;
    for (j = 0; j < 4; j++) {
      if (B[i][j] == player)
        count++;
      else if (B[i][j] == 'T')
        t++;
    }

    if (count == 4 || (count == 3 && t == 1))
      return true;
  }

  for (j = 0; j < 4; j++) {
    count = t = 0;
    for (i = 0; i < 4; i++) {
      if (B[i][j] == player)
        count++;
      else if (B[i][j] == 'T')
        t++;
    }

    if (count == 4 || (count == 3 && t == 1))
      return true;
  }

  t = count = 0;
  for (i = 0; i < 4; i++) {
    if (B[i][i] == player)
      count++;
    else if (B[i][i] == 'T')
      t++;
  }

  if (count == 4 || (count == 3 && t == 1))
    return true;

  count = t = 0;
  for (i = 0; i < 4; i++) {
    if (B[i][3-i] == player)
      count++;
    else if (B[i][3-i] == 'T')
      t++;
  }

  return (count == 4 || (count == 3 && t == 1));
}

int main(int argc, char *argv[])
{
  int t, tc, i, j;
  char B[5][5];

  scanf("%d", &t);

  for (tc = 1; tc <= t; tc++) {
    scanf("%s\n", B[0]);
    scanf("%s\n", B[1]);
    scanf("%s\n", B[2]);
    scanf("%s\n", B[3]);

    int dots = 0;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        if (B[i][j] == '.')
          dots++;

    string ans = "";
    if (win(B, 'X')) {
      ans = "X won";
    } else if (win(B, 'O')) {
      ans = "O won";
    } else if (dots == 0) {
      ans = "Draw";
    } else {
      ans = "Game has not completed";
    }

    printf("Case #%d: %s\n", tc, ans.c_str());
  }

  return EXIT_SUCCESS;
}

