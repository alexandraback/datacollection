#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
   int cas;
   double tsum, t2buy, tb2win, t2win, cost, add, rate, win;

   scanf("%d",&cas);
   for (int k=1; k<=cas; ++k) {
      scanf("%lf %lf %lf",&cost,&add,&win);
      tsum = 0; rate = 2;

      while (1) {
         t2buy = cost / rate;
         t2win = win / rate;
         tb2win = t2buy + win / (rate+add);
         if (t2win <= tb2win) {
            tsum += t2win;
            break;
         }
         else {
            tsum += t2buy;
            rate += add;
         }
      }
      printf("Case #%d: %.7lf\n",k,tsum);
   }

   return 0;
}
