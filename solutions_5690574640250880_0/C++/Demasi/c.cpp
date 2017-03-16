#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
#define MAX 8

int R,C,M;
int dX[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dY[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int f[MAX][MAX];
int total;

void fill(int i, int j, vector<string> &b)
{
  f[i][j] = 1;
  total++;
  int c = 0;
  for(int k = 0; k < 8; k++)
  {
    int y = i+dY[k];
    int x = j+dX[k];
    if (y >= 0 && x >= 0 && y < R && x < C)
      if (b[y][x] == '*')
        c++;
  }
  if (c == 0)
    for(int k = 0; k < 8; k++)
    {
      int y = i+dY[k];
      int x = j+dX[k];
      if (y >= 0 && x >= 0 && y < R && x < C)
        if (b[y][x] == '.' && f[y][x] == 0)
          fill(y, x, b);
    }
}

int avalia(int i, int j, vector<string> &b, int m)
{
  b[i][j] = '*';

  if (m == 0)
  {
    memset(f, 0, sizeof(f));
    total = 0;
    fill(0, 0, b);
    if (total == (R*C)-M)
      return 1;

    b[i][j] = '.';
    return 0;
  }

  int y = i;
  int x = j;

  while (y < R)
  {
    x++;
    if (x == C)
    {
      x = 0;
      y++;
    }
    if (y < R && avalia(y, x, b, m-1))
      return 1;
  }

  b[i][j] = '.';

  return 0;
}

int main(void)
{
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    scanf("%d %d %d", &R, &C, &M);
    printf("Case #%d:\n", caso);

    vector<string> b;
    string s = "";
    for(int i = 0; i < C; i++)
      s += '.';
    for(int i = 0; i < R; i++)
      b.push_back(s);

    b[0][0] = 'c';
    int ok = (M == 0);
    for(int i = 0; i < R && !ok; i++)
      for(int j = 0; j < C && !ok; j++)
        if (i != 0 || j != 0)
          ok = avalia(i, j, b, M-1);

    if (!ok) printf("Impossible\n");
    else
    {
      for(int i = 0; i < R; i++)
        printf("%s\n", b[i].c_str());
    }
  }
}
