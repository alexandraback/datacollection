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

const int MAX = 6;

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

int Rek(int a, int b)
{
  if (b == n)
    return Rek(a + 1, a + 2);

  if (a == n)
    return Prov();

  e[a][b] = 0;
  if (Rek(a, b + 1))
    return 1;

  e[a][b] = 1;
  return Rek(a, b + 1);
}

int main()
{
  int brt;

  scanf("%d", &brt);

  for (int br=1; br<=brt; br++) {
    scanf("%d%lld", &n, &brnac);

    printf("Case #%d: ", br);
    if (!Rek(0, 1))
      printf("IMPOSSIBLE\n");
    else {
      printf("POSSIBLE\n");
      for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++)
          printf("%d", e[i][j]);
        printf("\n");
      }
    }
  }

  return 0;
}
