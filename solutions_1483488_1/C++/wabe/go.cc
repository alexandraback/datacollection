#include <iostream>
#include <string>
using namespace std;

#include <assert.h>

const unsigned maxT = 50;
const unsigned maxAB = 2000000;
const unsigned maxDigits = 7;

void doCase() {
   unsigned A, B;
   cin >> A >> B;
   assert(A >= 1 && A <= B && B <= maxAB);

   unsigned D = 1;
   unsigned digits = 1;
   while (D * 10 <= A) {
      D *= 10;
      digits++;
   }
   assert(D * 10 > B);
   unsigned oldD = D;

   unsigned x[maxDigits-1];
   unsigned y[maxDigits-1];
   unsigned got[maxDigits-1];

   for (int d = 0; d < digits - 1; d++) {
      y[d] = D;
      D /= 10;
   }
   for (int d = 0; d < digits - 1; d++) {
      x[d] = y[digits - 2 - d];
      assert(x[d] * y[d] == oldD * 10);
   }

   unsigned count = 0;
   for (unsigned n = A; n < B; n++) {
      for (int d = 0; d < digits - 1; d++) {
         unsigned m = y[d] * (n%x[d]) + n/x[d];
         got[d] = m;
         if (n < m && m <= B) {
            bool ok = true;
            for (int k = 0; k < d; k++) {
               if (got[k] == m) {
                  ok = false;
               }
            }
            if (ok) {
               count++;
            }
         }
      }
   }

   cout << count << endl;
}

int main() {
   unsigned T;
   cin >> T;
   assert(T >= 1 && T <= maxT);

   for (unsigned t = 1; t <= T; t++) {
      cout << "Case #" << t << ": ";
      doCase();
   }
   return 0;
}
