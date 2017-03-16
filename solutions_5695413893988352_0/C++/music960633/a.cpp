#include <stdio.h>
#include <string.h>
#include <cassert>

long long pow(int a, int b){
   long long ret = 1;
   while(b--) ret *= a;
   return ret;
}
long long abs(long long a){
   return a < 0? -a : a;
}
bool match(long long a, char* s){
   int n = strlen(s);
   for(int i=n-1; i>=0; --i){
      if(s[i] != '?' && s[i] != '0' + a%10)
         return false;
      a /= 10;
   }
   return true;
}

void print(long long a, int n){
   char s[20];
   s[n] = '\0';
   for(int i=n-1; i>=0; --i){
      s[i] = '0' + a%10;
      a /= 10;
   }
   printf("%s", s);
}

int main(){
   int T, n;
   long long mx;
   long long ansa, ansb;
   char s1[20], s2[20];
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d: ", t);
      scanf("%s%s", s1, s2);
      n = strlen(s1);
      mx = pow(10, n);
      ansa = mx;
      ansb = 0;
      for(int i=0; i<mx; ++i){
         for(int j=0; j<mx; ++j){
            if(match(i, s1) && match(j, s2)){
               if(abs(i-j) < abs(ansa-ansb) || 
                     (abs(i-j) == abs(ansa-ansb) && i < ansa)){
                  ansa = i;
                  ansb = j;
               }
            }
         }
      }
      print(ansa, n);
      printf(" ");
      print(ansb, n);
      printf("\n");
   }
   return 0;
}
