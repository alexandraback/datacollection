#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
   int T;
   scanf("%d", &T);
   for(int _i=1; _i<=T; _i++)
   {
      int J, P, S, K;
      scanf("%d%d%d%d", &J, &P, &S, &K);
      int W = min(S, K);
      printf("Case #%d: %d\n",_i,W*J*P);
      for(int j=1; j<=J; j++)
         for(int p=1; p<=P; p++) {
            for(int k=0; k<W; k++) {
               printf("%d %d %d\n", j, p, (k + j + p + S - 2) % S + 1 );
            }
         }
   }
   return 0;
}
