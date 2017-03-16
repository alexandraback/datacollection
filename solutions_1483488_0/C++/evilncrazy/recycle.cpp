#include <cstdio>
#include <algorithm>

int exp(int x) {
   if(x == 0) return 1;
   return exp(x / 10) * 10;
}

int main() {
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   
   int tc;
   scanf("%d", &tc);
   
   for(int t = 1; t <= tc; t++) {
      int a, b;
      scanf("%d %d", &a, &b);
      
      int count = 0;
      for(int i = a; i <= b; i++) {
         int x = i, xp = exp(i/10);
         do {
            int xt = x % 10;
            x /= 10;
            x += xt * xp;
            if(x != i && x >= a && x <= b) ++count;
         } while(x != i);
      }
      
      printf("Case #%d: %d\n", t, count / 2);
   }
}
