#include <stdio.h>

int trial[10];
int need[10];
bool meet[10];

int R, N, M, K;
bool found;

void test(){
  int mult;
  int top = 1<<N;
  int temp, ct;
  
  for(int i=0; i<K; i++) meet[i] = false;
  
  for(int i=0; i<top; i++){
    temp = i;
    ct = 0;
    mult = 1;
    
    while(temp > 0){
      if(temp & 1) mult *= trial[ct];
      
      temp >>= 1;
      ct++;
    }
    
    for(int i=0; i<K; i++){
      if(need[i] == mult){
        meet[i] = true;
      }
    }
  }
  
  for(int i=0; i<K; i++){
    if(!meet[i]) return;
  }
  
  found = true;
  for(int i=0; i<N; i++) printf("%d", trial[i]);
  printf("\n");
  return;
}

void rec1(int lv){
  if(found) return;
  
  if(lv == N){
    test();
    return;
  }
  for(int i=2; i<=M; i++){
    trial[lv] = i;
    rec1(lv+1);
    if(found) return;
  }
}

int main(){
  int jcase;
  
  freopen("C-small-1-attempt0.in", "r", stdin);
  freopen("C-small-1-attempt0.out", "w", stdout);
  //freopen("A-large.in", "r", stdin);
  scanf("%d", &jcase);
  
  for(int icase=0; icase<jcase; icase++){
    printf("Case #%d:\n", icase+1);
    scanf("%d %d %d %d", &R, &N, &M, &K);
    for(int i=0; i<R; i++){
      for(int j=0; j<K; j++) scanf("%d", &need[j]);
      found = false;
      rec1(0);
    }
  }
  return 0;
}
