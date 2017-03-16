#include<stdio.h>

void solve(int K, int C, int S){
  if(S*C<K){
    printf(" IMPOSSIBLE");
    return;
  }
  int id = K-1;
  while(id>=0){
    long long int val = 0;
    for(int d=0; d<C; d++){
      val = val*K;
      if(id>=0) val += id;
      id--;
    }
    printf(" %lld", val+1);
  }
}


int main(int agrc, char *argv[]){
  int T; scanf("%d", &T);
  for(int tc=1; tc<=T; tc++){
    int K, C, S;
    scanf("%d %d %d", &K, &C, &S);
    printf("Case #%d:", tc);
    solve(K, C, S);
    printf("\n");
  }
  return 0;
}
