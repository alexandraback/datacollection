#include <stdio.h>

bool check(bool* arr){
   for(int i=0; i<10; ++i){
      if(!arr[i]) return false;
   }
   return true;
}

void addDigits(int val, bool* arr){
   while(val != 0){
      arr[val%10] = true;
      val /= 10;
   }
}

int f(int n){
   if(n == 0)
      return -1;
   bool rec[10];
   for(int i=0; i<10; ++i) rec[i] = false;
   for(int m = n; ; m += n){
      addDigits(m, rec);
      if(check(rec)) return m;
   }
   return -1;
}

int main(){
   int T, n;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      printf("Case #%d: ", t);
      scanf("%d", &n);
      int ret = f(n);
      if(ret == -1)
         printf("INSOMNIA\n");
      else
         printf("%d\n", ret);
   }
   return 0;
}
