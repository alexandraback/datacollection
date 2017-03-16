#include<stdio.h>

void solve(int t) {
  int N, C, S, s;
  scanf("%d %d %d",&N,&C,&S);
  
  if(S < (N+C-1)/C) {
    printf("Case #%d: IMPOSSIBLE\n",t);
    return;
  }
  long long num;
  printf("Case #%d:",t);
  for(int i=0;i<N;i+=C) {
    num = 0;
    for(int j=0;i+j<N && j<C;j++) {
      num = num*N + i+j;
    }
    printf(" %lld",num+1);
  }
  printf("\n");
}

int main() {
  int t,T;
  scanf("%d",&T);
  for(t=1;t<=T;t++) solve(t);
  return 0;
}
