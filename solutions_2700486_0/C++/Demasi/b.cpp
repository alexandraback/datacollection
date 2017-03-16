#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX 16
double P[MAX][MAX];

int main(void)
{
  int T, N, X, Y;

  for(int i = 1; i < MAX; i++)
    for(int j = 0; j < MAX; j++)
      P[i][j] = 0.0;
  for(int j = 0; j < MAX; j++)
    P[0][j] = 1.0;

  for(int i = 1; i < MAX; i++)
    for(int j = 1; j < MAX; j++)
      P[i][j] = 0.5*P[i-1][j-1] + 0.5*P[i][j-1];

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    printf("Case #%d: ", caso);

    scanf("%d %d %d", &N, &X, &Y);
    double p = 0.0;

    if (X == 0 && Y == 0) p = 1.0;
    else if (Y == 0 && (X == -2 || X == 2))
    {
      if (N > 1 && N <= 3)
        p = P[1][N-1];
      else if (N > 3) p = 1.0;
    }
    else if (Y == 1 && (X == -1 || X == 1))
    {
      if (N > 2 && N <= 4)
        p = P[2][N-1];
      else if (N > 4) p = 1.0;
    }
    else if (Y == 2 && X == 0)
    {
      if (N >= 6) p = 1.0;
    }
    else if (Y == 0 && (X == 4 || X == -4))
    {
      if (N > 6 && N <= 10)
        p = P[1][N-6];
      else if (N > 10) p = 1.0;
    }
    else if (Y == 1 && (X == 3 || X == -3))
    {
      if (N > 7 && N <= 11)
        p = P[2][N-6];
      else if (N > 11) p = 1.0;
    }
    else if (Y == 2 && (X == 2 || X == -2))
    {
      if (N > 8 && N <= 12)
        p = P[3][N-6];
      else if (N > 12) p = 1.0;
    }
    else if (Y == 3 && (X == 1 || X == -1))
    {
      if (N > 9 && N <= 13)
        p = P[4][N-6];
      else if (N > 13) p = 1.0;
    }
    else if (Y == 4 && X == 0)
    {
      if (N >= 15) p = 1.0;
    }
    else if (Y == 0 && (X == 6 || X == -6))
    {
      if (N > 15 && N <= 27)
        p = P[1][N-15];
    }
    else if (Y == 1 && (X == 5 || X == -5))
    {
      if (N > 16 && N <= 28)
        p = P[2][N-15];
    }
    else if (Y == 2 && (X == 4 || X == -4))
    {
      if (N > 17 && N <= 29)
        p = P[3][N-15];
    }
    else if (Y == 3 && (X == 3 || X == -3))
    {
      if (N > 18 && N <= 30)
        p = P[4][N-15];
    }
    else if (Y == 4 && (X == 2 || X == -2))
    {
      if (N > 19 && N <= 31)
        p = P[5][N-15];
    }

    printf("%.10lf\n", p);
  }
}
