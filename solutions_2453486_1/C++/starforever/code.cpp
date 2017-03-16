#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
using namespace std;

#define max2(a,b) (((a) > (b)) ? (a) : (b))
#define min2(a,b) (((a) < (b)) ? (a) : (b))

#define debug(x) cout << (#x) << ": " << (x) << endl
#define echo(x) cout << (#x) << endl
#define TIMER_A(timer) int timer = clock()
#define TIMER_B(timer) cerr << (#timer) << ": " << (double)(clock() - timer) / CLOCKS_PER_SEC << endl

typedef long long LL;
const double eps = 1e-9;
const double pi = M_PI;
const int inf = 2000000000; // 2e9
const LL inf64 = 9000000000000000000LL; // 9e18

int TN, TC;

char line[5];
char board[4][4];

bool canWin (char s)
{
  int c;
  for (int i = 0; i < 4; ++i)
  {
    c = 0;
    for (int j = 0; j < 4; ++j)
      if (board[i][j] == s || board[i][j] == 'T')
        ++c;
    if (c == 4)
      return true;
  }
  for (int i = 0; i < 4; ++i)
  {
    c = 0;
    for (int j = 0; j < 4; ++j)
      if (board[j][i] == s || board[j][i] == 'T')
        ++c;
    if (c == 4)
      return true;
  }
  c = 0;
  for (int i = 0; i < 4; ++i)
    if (board[i][i] == s || board[i][i] == 'T')
      ++c;
  if (c == 4)
    return true;
  c = 0;
  for (int i = 0; i < 4; ++i)
    if (board[i][3 - i] == s || board[i][3 - i] == 'T')
      ++c;
  if (c == 4)
    return true;
  return false;
}

bool allFill ()
{
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      if (board[i][j] == '.')
        return false;
  return true;
}

int getState ()
{
  if (canWin('X'))
    return 1;
  if (canWin('O'))
    return 2;
  if (allFill())
    return 3;
  else
    return 4;
}

int main ()
{
  scanf("%d ", &TN);
  for (TC = 1; TC <= TN; ++TC)
  {
    for (int i = 0; i < 4; ++i)
    {
      gets(line);
      memcpy(board[i], line, 4);
    }
    gets(line);
    int t = getState();
    printf("Case #%d: ", TC);
    switch (t)
    {
      case 1:
        printf("X won");
        break;
      case 2:
        printf("O won");
        break;
      case 3:
        printf("Draw");
        break;
      case 4:
        printf("Game has not completed");
        break;
    }
    printf("\n");
  }
}
