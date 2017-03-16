#include <stdio.h>

#define N 32
#define J 500

int mod(unsigned long long n, int base, int m){
   int val = 0;
   for(int i=N-1; i>=0; --i){
      val = ( (val * base) + ((n>>i)&1) ) % m;
   }
   return val;
}

int diviser(unsigned long long n, int base){
   for(int i=2; i<=1000; ++i){
      if(mod(n, base, i) == 0) return i;
   }
   return -1;
}

bool check(unsigned long long n){
   int div[11];
   for(int base=2; base<=10; ++base){
      div[base] = diviser(n, base);
      if(div[base] == -1) return false;
   }
   for(int i=N-1; i>=0; --i)
      printf("%llu", (n>>i)&1);
   for(int i=2; i<=10; ++i)
      printf(" %d", div[i]);
   printf("\n");
   return true;
}

int main(){
   printf("Case #1:\n");
   for(unsigned long long i = (1ULL<<(N-1)) + 1, j = 0; j < J; i += 2){
      if(check(i)) j += 1;
   }
   return 0;
}
