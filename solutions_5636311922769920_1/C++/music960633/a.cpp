#include <stdio.h>

void solve(int K, int C, int S){
   if(C*S < K){
      printf(" IMPOSSIBLE\n");
      return;
   }
   for(int i=0; i<K; i+=C){
      long long num = 0;
      for(int j=0; j<C; ++j)
         num = (num * K) + ((i+j) < K ? (i+j) : 0);
      printf(" %lld", num+1);
   }
   printf("\n");
}

int main(){
   int T, K, C, S;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d:", t);
      scanf("%d%d%d", &K, &C, &S);
      solve(K, C, S);
   }
   return 0;
}
