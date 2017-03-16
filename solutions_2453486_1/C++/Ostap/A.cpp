#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory.h>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long double Double;
typedef vector<int> VInt;
typedef vector< vector<int> > VVInt;
typedef long long Int;
typedef pair<int, int> PII;

#define FOR(i, n, m) for(i = n; i < m; ++i)
#define RFOR(i, n, m) for(i = (n) - 1; i >= (m); --i)
#define CLEAR(x, y) memset(x, y, sizeof(x))
#define COPY(x, y) memcpy(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SIZE(v) ((int)((v).size()))
#define ALL(v) (v).begin(), (v).end()

char B[10][10];

bool check(char turn) {
  bool won = false;
  int j;
  for (int i = 0; i < 4; ++i) {
    for (j = 0; j < 4; ++j)
      if (B[i][j] != turn && B[i][j] != 'T')
	break;
    if (j == 4)
      won = true;
    for (j = 0; j < 4; ++j)
      if (B[j][i] != turn && B[j][i] != 'T')
	break;
    if (j == 4)
      won = true;
  }
  for (j = 0; j < 4; ++j)
    if (B[j][j] != turn && B[j][j] != 'T')
      break;
  if (j == 4)
    won = true;
  for (j = 0; j < 4; ++j)
    if (B[j][3-j] != turn && B[j][3-j] != 'T')
      break;
  if (j == 4)
    won = true;

  return won;
}

int main()
{
  int T, t;
  scanf("%d", &T);
  for (t = 0; t < T; ++t) {
    for (int i = 0; i < 4; ++i)
      scanf("%s", B[i]);
    bool xWon, oWon;
    xWon = check('X');
    oWon = check('O');
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
	if (B[i][j] == '.')
	  ++cnt;
    printf("Case #%d: ", t+1);
    if (xWon)
      printf("X won\n");
    else if (oWon)
      printf("O won\n");
    else if (cnt == 0)
      printf("Draw\n");
    else
      printf("Game has not completed\n");
  }

  return 0;
};
