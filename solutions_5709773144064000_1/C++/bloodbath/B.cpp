#include <cstdio>
#include <cstdlib>
#include <cmath>
double C, F, X;
// The number of factories is a unimodal function
double check(){
   double rate = 2.0, tim = 0.0, nxt_cost, combien = 0.0, mn = X / 2.0;
   int num = (int) ceil(X);
   for (int i = 0; i< num; i++){
      nxt_cost = C / rate;
      tim += nxt_cost;
      rate += F;
      combien = tim + X / rate;
      if (combien < mn) mn = combien;
   }
   return mn;
}
int main(){
   int t;
   freopen("in.in", "r", stdin);
   freopen("out.out", "w", stdout);
   scanf("%d", &t);
   for (int kl = 1; kl<=t; kl++){
      scanf("%lf%lf%lf", &C, &F, &X);
      printf("Case #%d: %.7lf\n", kl, check());
   }
   return 0;
}
   
