#include <cstdio>
#include <algorithm>
using namespace std;

bool sol[50][50];
long long nbSol[50];

int main()
{
   int T;
   scanf("%d", &T);
   for(int _i=1; _i<=T; _i++)
   {
      int B;
      long long M;
      scanf("%d%lld", &B, &M);
      for(int i=0; i<B; i++) {
         nbSol[i] = 0;
         for(int j=0; j<B; j++)
            sol[i][j] = 0;
      }

      int m = 1;
      nbSol[B-1] = 1;
      for(int node=B-2; node>=0; node--){ 
         sol[node][node+1] = 1;
         nbSol[node] = nbSol[node+1];
         for(int i=node+2; i<B; i++) {
            if(m + nbSol[i] <= M) {
               sol[node][i] = 1;
               m += nbSol[i];
            }
         }
         nbSol[node] = m;
      }

      printf("Case #%d: ",_i);
      if(m < M)
         printf("IMPOSSIBLE\n");
      else {
         printf("POSSIBLE\n");
         for(int i=0; i<B; i++) {
            for(int j=0; j<B; j++)
               printf("%d", sol[i][j]);
            printf("\n");
         }
      }
   }
   return 0;
}
