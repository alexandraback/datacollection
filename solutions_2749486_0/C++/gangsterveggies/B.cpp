#include <stdio.h>
#include <string.h>
#include <string>

#define MX 6000
#define FL 1000000

using namespace std;

char dp[12000][500];
char ctd[12000][500];
string aDP[12000][500];
int stuck = 0;

char DP(int vl, int uni)
{
  if (uni < 0 || vl < 0 || vl >= 12000)
    return 0;
  if (uni == stuck - MX)
  {
    if (DP(vl, uni - 1))
      aDP[vl][uni] = aDP[vl][uni - 1];
    return DP(vl, uni - 1);
  }
  if (ctd[vl][uni] != 0)
    return dp[vl][uni];
  ctd[vl][uni] = 1;
  if (DP(vl - uni, uni - 1))
  {
    dp[vl][uni] = 1;
    aDP[vl][uni] = aDP[vl - uni][uni - 1] + "+";
    return 1;
  }
  if (DP(vl + uni, uni - 1))
  {
    dp[vl][uni] = 1;
    aDP[vl][uni] = aDP[vl + uni][uni - 1] + "-";
    return 1;
  }
  dp[vl][uni] = 0;
  return 0;
}

int main()
{
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; t++)
  {
    memset(dp, 0, sizeof dp);
    memset(ctd, 0, sizeof dp);
    dp[MX][0] = 1;
    ctd[MX][0] = 1;
    aDP[MX][0] = "";
    printf("Case #%d: ", t);
    int x, y;
    scanf("%d %d", &x, &y);
    int tmp = x;
    x = y;
    y = tmp;
/*    if (x == 0 || y == 0)
    {
      if (x == 0 && y == 0)
        printf("\n");
      else if (x == 0)
      {
        printf("\n");
      }
      else if (y == 0)
      {
        printf("\n");
      }
      continue;
    }*/
    x += MX, y += MX;
    int i = x - MX + 1;
    stuck = x;
    if (stuck == MX)
    {
      stuck = FL;
      i = 0;
    }
    while (i < 500)
    {
      if (DP(y, i))
        break;
      i++;
    }
    if (i == 500 || y == MX)
    {
      int i = y - MX + 1;
      stuck = y;
      if (stuck == MX)
      {
        stuck = FL;
        i = 0;
      }
//      printf("%d\n", DP(101, 1));
//      continue;
      while (i < 500)
      {
        if (DP(x, i))
          break;
        i++;
      }
      int j, f = 0;
      for (j = 0; j < i; j++)
      {
        if (j + 1 == y - MX && stuck != FL)
        {
          printf("E");
          f = 1;
        }
        else
        {
          if (aDP[x][i][j - f] == '-')
            printf("S");
          else
            printf("N");
        }
      }

    }
    else
    {
      int j, f = 0;
      for (j = 0; j < i; j++)
      {
        if (j + 1 == x - MX && stuck != FL)
        {
          printf("N");
          f = 1;
        }
        else
        {
          if (aDP[y][i][j - f] == '-')
            printf("W");
          else
            printf("E");
        }
      }
    }
    printf("\n");
  }
  return 0;
}
