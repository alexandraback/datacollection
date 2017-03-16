#include<stdio.h>

int main(int agrc, char *argv[]){
  int T; scanf("%d", &T);
  for(int tc=1; tc<=T; tc++){
    int res = 0;
    char c; 
    char last;
    scanf(" %c", &last);
    while(scanf("%c", &c) &&(c=='+' || c=='-')){
      if(c!=last)
        res++;
      last = c;
    }
    if(last!='+') res++;

    printf("Case #%d: %d\n", tc, res);
  }
  return 0;
}
