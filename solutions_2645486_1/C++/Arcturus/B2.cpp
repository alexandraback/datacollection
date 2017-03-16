#include <stdio.h>

int arr[10010];

int main(){
  int jcase;
  int E, R, N;
  int f, e, itemp;
  long long sum;
  int idx, ct;
  
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  scanf("%d", &jcase);
  
  for(int icase=0; icase<jcase; icase++){
    scanf("%d %d %d", &E, &R, &N);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    arr[N] = -1;
    arr[N+1] = -1;
    
    sum = 0;
    e = E;
    idx = 0;
    while(idx < N){
      itemp = e - (E-R);
      if(R > E) itemp = e;
      
      if(itemp > 0){
        sum += (long long)itemp * arr[idx];
        e = e - itemp;
        //printf("if %lld %d\n", sum, e);
      }
      ct = 1;
      
      while((e > 0) && (arr[idx] > arr[idx+ct])){
        itemp = R;
        if(e - itemp < 0) itemp = e;
        sum += (long long)itemp * arr[idx];
        ct++;
        e -= itemp;
        //printf("while %lld %d\n", sum, e);
        if(arr[idx + ct] < 0){
          sum += (long long)e * arr[idx];
          e = 0;
          //printf("all %lld %d\n", sum, e);
        }
      }
      
      idx++;
      e += R;
      if(e > E) e = E;
    }
    
    printf("Case #%d: %lld\n", icase+1, sum);
  }
  return 0;
}
