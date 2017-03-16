#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
  int jcase;
  int N, jsurp, p;
  int arr[100];
  int count;
  int ctemp;
  
  freopen("B-small-attempt0.in", "r", stdin);
  freopen("B-small-attempt0.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase < jcase; icase++){
    scanf("%d %d %d", &N, &jsurp, &p);
    for(int i=0; i<N; i++) scanf("%d", &arr[i]);
    
    count = ctemp = 0;
    for(int i=0; i<N; i++){
      if(arr[i] >= p*3-2) count++;
      else if(arr[i] >= p*3-4){
        if(p == 1 && arr[i] == 0) continue;
        if(jsurp > 0){
          jsurp--;
          count++;
        }
      }
    }
    printf("Case #%d: %d\n", icase+1, count);
  }
  return 0;
}
