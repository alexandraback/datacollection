#include <stdio.h>
#include <string.h>

int flip(char* s){
   int n = strlen(s), ret = 0;
   s[n] = '+';
   for(int i=0; i<n; ++i){
      if(s[i] != s[i+1])
         ret += 1;
   }
   return ret;
}

int main(){
   int T;
   char s[1001];
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d: ", t);
      scanf("%s", s);
      printf("%d\n", flip(s));
   }
   return 0;
}
