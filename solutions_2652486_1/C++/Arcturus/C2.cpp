#include <stdio.h>

int need[15];
int ans[15];
int R, N, M, K;
int ct;

void trial(int test){
  bool cand;
  cand = false;
  for(int i=0; i<K; i++){
    if(need[i] % test == 0) cand = true;
  }
  while(cand){
    cand = false;
    for(int i=0; i<K; i++){
      if(need[i] % test == 0){
        need[i] /= test;
        if(need[i] % test == 0) cand = true;
      }
    }
    ans[ct] = test;
    ct++;
  }
}

int main(){
  int jcase;
  
  freopen("C-small-2-attempt0.in", "r", stdin);
  freopen("C-small-2-attempt0.out", "w", stdout);
  scanf("%d", &jcase);
  
  for(int icase=0; icase<jcase; icase++){
    printf("Case #%d:\n", icase+1);
    scanf("%d %d %d %d", &R, &N, &M, &K);
    for(int i=0; i<R; i++){
      ct = 0;
      for(int j=0; j<K; j++) scanf("%d", &need[j]);
      
      trial(7);
      trial(5);
      trial(3);
      trial(8);
      trial(4);
      trial(2);
      trial(6);
      
      for(int i=ct; i<N; i++){
        ans[i] = 2;
      }
      
      for(int i=0; i<N; i++) printf("%d", ans[i]);
      printf("\n");
    }
  }
  return 0;
}
