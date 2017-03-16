#include<stdio.h>

int main(int agrc, char *argv[]){
  int T; scanf("%d", &T);
  for(int tc=1; tc<=T; tc++){
    bool found[10];
    for(int i=0; i<10; i++)
      found[i] = false;
    int N; scanf("%d", &N);
    int val = 0;
    int foundcnt = (N==0)?10:0;
    while(foundcnt<10){
      val += N;
      int r = val;
      while(r){ 
        if(!found[r%10]){
          foundcnt++;
          found[r%10] = true;
        }
        r /= 10;
      }
    }
    if(N==0){
      printf("Case #%d: INSOMNIA\n", tc);
    }else{
      printf("Case #%d: %d\n", tc, val);
    }
  }
  return 0;
}
