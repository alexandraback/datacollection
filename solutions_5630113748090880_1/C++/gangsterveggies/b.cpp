#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long int lld;
typedef pair<int, int> pii;
typedef pair<pii, pii> line;

#define F first
#define S second

int h[3000];

int main()
{
  int t, T;
  scanf("%d", &T);

  for (t = 1; t <= T; t++)
  {
    int i, j;
    int n, vl;
    memset(h, 0, sizeof h);
    scanf("%d", &n);

    for (i = 0; i < 2 * n - 1; i++)
      for (j = 0; j < n; j++)
      {
        scanf("%d", &vl);
        h[vl]++;
      }

    printf("Case #%d:", t);
    for (i = 0; i < 3000; i++)
      if (h[i] % 2)
        printf(" %d", i);
    printf("\n");
  }
  
  return 0;
}
