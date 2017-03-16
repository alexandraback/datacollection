#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define MAX 16
int f[MAX][MAX], E, R, N, v[MAX];

int faz(int e, int i)
{
  int &home = f[e][i];

  if (i == N) home = 0;

  if (home < 0)
  {
    home = 0;
    for(int r = 0; r <= e; r++)
    {
      int nE = min(E, e-r+R);
      faz(nE, i+1);
      home = max(home, r*v[i] + f[nE][i+1]);
    }
  }

  return home;
}

int main(void)
{
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    printf("Case #%d: ", caso);

    scanf("%d %d %d", &E, &R, &N);
    for(int i = 0; i < N; i++)
      scanf("%d", v+i);

    memset(f, -1, sizeof(f));

    printf("%d\n", faz(E, 0));
  }
}
