#include <stdio.h>

void swap(int& x, int& y){
   int t = x;
   x = y;
   y = t;
}

int main(){
   int T, n, m, k;
   scanf("%d", &T);
   for(int t=1; t<=T; ++t){
      scanf("%d%d%d", &n, &m, &k);
      int ans;
      if(n>m) swap(n, m);

      if(n==1 || n==2) ans = k;
      
      if(n==3){
         if(m==3){
            if(k<5) ans = k;
            else ans = k-1;
         }
         if(m==4){
            if(k<5) ans = k;
            else if(k<8) ans = k-1;
            else ans = k-2;
         }
         if(m==5){
            if(k<5) ans = k;
            else if(k<8) ans = k-1;
            else if(k<11) ans = k-2;
            else ans = k-3;
         }
         if(m==6){
            if(k<5) ans = k;
            else if(k<8) ans = k-1;
            else if(k<11) ans = k-2;
            else if(k<14) ans = k-3;
            else ans = k-4;
         }
      }

      if(n==4){
         if(m==4){
            if(k<5) ans = k;
            else if(k<8) ans = k-1;
            else if(k<10) ans = k-2;
            else if(k<12) ans = k-3;
            else ans = k-4;
         }
         if(m==5){
            if(k<5) ans = k;
            else if(k<8) ans = k-1;
            else if(k<10) ans = k-2;
            else if(k<12) ans = k-3;
            else if(k<14) ans = k-4;
            else if(k<16) ans = k-5;
            else ans = k-6;
         }
      }
      printf("Case #%d: %d\n", t, ans);
   }

   return 0;
}
