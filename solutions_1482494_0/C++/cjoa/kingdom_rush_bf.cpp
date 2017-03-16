#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

int P3[12];

#define INF 100000000

int N;
PII V[1004];
int memo[ 22 ][ 60000 ];
int go(int stars, int mask) {
   if (mask == 0)
      return 0;
   int& res = memo[stars][mask];
   if (res < 0) {
      res = INF;
      for (int m = mask, j = 0; j < N; ++j) {
         int d = m % 3;
         if (d == 2) {
            if (stars >= V[j].second)
               res = min(res, 1+go(min(stars + 2, 21), mask - 2 * P3[j]));
            if (stars >= V[j].first)
               res = min(res, 1+go(min(stars + 1, 21), mask - P3[j]));
         }
         if (d == 1) {
            if (stars >= V[j].second)
               res = min(res, 1+go(min(stars + 1, 21), mask - P3[j]));
         }
         m /= 3;
      }
   }
   return res;
}

int main(int argc, char* argv[]) {
   P3[0] = 1;
   for (int i = 1; i <= 11; ++i)
      P3[i] = P3[i-1] * 3;

   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      scanf("%d", &N);
      for (int i = 0; i < N; ++i)
         scanf("%d %d", &V[i].first, &V[i].second);
      memset(memo, -1, sizeof(memo));
   // printf("%d\n", P3[N]);
      int res = go(0, P3[N]-1);
      if (res >= INF)
         printf("Case #%d: Too Bad\n", tc);
      else
         printf("Case #%d: %d\n", tc, res);
   }
   return 0;
}
