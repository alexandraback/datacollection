#include <iostream>
#include <string>
using namespace std;

#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned u;

const u maxT = 20;
const u maxA = 99999;
const u maxB = 100000;

double p[maxA];

void doCase() {
   u a, b;
   cin >> a >> b;
   assert(1 <= a && a < b && a <= maxA && b <= maxB);

   for (u n = 0; n < a; n++) {
      double x;
      cin >> x;
      assert(x >= 0 && x <= 1);
      p[n] = x;
   }

   double best = b + 2;
   double good = 1;
   for (u n = 0; n <= a; n++) {
      double chance = (a - n + b - n + 1) + (1 - good) * (b + 1);
      if (chance < best) best = chance;
      good *= p[n];
   }

   printf("%.6f\n", best);
}

int main() {
   unsigned T;
   cin >> T;
   assert(T >= 1 && T <= maxT);

   for (unsigned t = 1; t <= T; t++) {
      printf("Case #%u: ", t);
      doCase();
   }
   return 0;
}
