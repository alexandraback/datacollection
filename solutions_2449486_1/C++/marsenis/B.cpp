#include <cstdio>
#include <algorithm>
#define MAX 105

using namespace std;

int lawn[MAX][MAX], maxr[MAX], maxc[MAX];

int main() {
   //freopen("B.in", "r", stdin);
   int tests, n, m, stop;

   scanf("%d", &tests);

   for (int t = 0; t < tests; t++) {
      scanf("%d%d", &n, &m);

      for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
            scanf("%d", &lawn[i][j]);

      for (int i = 0; i < n; i++) maxr[i] = 0;
      for (int i = 0; i < m; i++) maxc[i] = 0;

      for (int i = 0; i < n; i++)
         for (int j = 0; j < m; j++)
            maxr[i] = max( maxr[i], lawn[i][j] );

      for (int i = 0; i < m; i++)
         for (int j = 0; j < n; j++)
            maxc[i] = max( maxc[i], lawn[j][i] );

      stop = 0;

      for (int i = 0; !stop && i < n; i++)
         for (int j = 0; !stop && j < m; j++)
            if (lawn[i][j] != maxr[i] && lawn[i][j] != maxc[j]) {
               printf("Case #%d: NO\n", t+1);
               stop = 1;
            }

      if (!stop) printf("Case #%d: YES\n", t +1);
   }
	return 0;
}

