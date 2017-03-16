#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> P;
#define X first
#define Y second

const int MAX = 52;

int e[MAX][MAX];
int n;
ll brnac;

int Prov()
{
  ll dp[MAX];
  memset(dp, 0, sizeof dp);

  dp[0] = 1;
  for (int i=0; i<n; i++)
    for (int j=i+1; j<n; j++)
      if (e[i][j])
        dp[j] += dp[i];

  return brnac == dp[n-1];
}

int main()
{
  int brt;

  scanf("%d", &brt);

  for (int br=1; br<=brt; br++) {
    scanf("%d%lld", &n, &brnac);

    printf("Case #%d: ", br);

    if (brnac > (1ll << (n-2))) {
      printf("IMPOSSIBLE\n");
      continue;
    }
    else
      printf("POSSIBLE\n");

    memset(e, 0, sizeof e);
    for (int i=0; i<n-1; i++)
      for (int j=i+1; j<n-1; j++)
        e[i][j] = 1;

    if (brnac == (1ll << (n-2)))
      for (int i=0; i<n-1; i++)
        e[i][n-1] = 1;
    else {
      for (int i=0; i<n-1; i++)
        if ((brnac>>i) & 1)
          e[i+1][n-1] = 1;
    }

    for (int i=0; i<n; i++) {
      for (int j=0; j<n; j++)
        printf("%d ", e[i][j]);
      printf("\n");
    }
    assert(Prov());
  }

  return 0;
}

