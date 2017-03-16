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

int N, M;
int G[105][105];

int isPossible()
{
  int i, j, k;
  for (i = 0; i < N; i++) {
    for (j = 0; j < M; j++) {
      bool increasing = false;
      for (k = j + 1; k < M; k++)
        if (G[i][k] > G[i][j])
          increasing = true;

      for (k = j - 1; k >= 0; k--)
        if (G[i][k] > G[i][j])
          increasing = true;

      if (!increasing)
        continue;

      increasing = false;
      for (k = i + 1; k < N; k++)
        if (G[k][j] > G[i][j])
          return false;

      for (k = i - 1; k >= 0; k--)
        if (G[k][j] > G[i][j])
          return false;
    }
  }

  return true;
}


int main(int argc, char *argv[])
{
  int t, tc, i, j;

  scanf("%d", &t);

  for (tc = 1; tc <= t; tc++) {
    scanf("%d %d", &N, &M);

    for (i = 0; i < N; i++)
      for (j = 0; j < M; j++)
        scanf("%d", &G[i][j]);

    if (isPossible())
      printf("Case #%d: YES\n", tc);
    else
      printf("Case #%d: NO\n", tc);
  }

  return EXIT_SUCCESS;
}

