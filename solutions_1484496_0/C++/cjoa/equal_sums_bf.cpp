#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int N;
int A[20];

int main(int argc, char* argv[]) {
   int TC;
   scanf("%d", &TC);
   for (int tc = 1; tc <= TC; ++tc) {
      int N;
      scanf("%d", &N);
      for (int i = 0; i < N; ++i)
         scanf("%d", A+i);
      int res = -1;
      map<int, vector<int> > M;
      for (int mask = 1; mask < (1<<N); ++mask) {
         int sum = 0;
         for (int j = 0; j < N; ++j)
            if (mask & (1<<j))
               sum += A[j];
         M[ sum ].push_back( mask );
         if (M[ sum ].size() > 1) {
            res = sum;
            break;
         }
      }
      printf("Case #%d:\n", tc);
      if (res < 0)
         puts("Impossible\n");
      else {
      // printf("sum = %d\n", res);
         vector<int> V = M[res];
         for (int i = 0; i < V.size(); ++i) {
            int mask = V[i];
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
               if (mask & (1<<j)) {
                  if (cnt > 0) putchar(' ');
                  printf("%d", A[j]);
                  ++cnt;
               }
            }
            putchar('\n');
         }
      }
   }
   return 0;
}
