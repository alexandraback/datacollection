#include <iostream>
#include <string>
using namespace std;

#include <algorithm>
#include <assert.h>
#include <stdio.h>
#include <string.h>

typedef unsigned u;

const u maxT = 100;
const u maxN = 1000;
const u maxNeed = 2001;

u a[maxN];
u b[maxN];

u at0a[maxN];
u at0b[maxN];

u at1[maxN];

bool comparea(u n1, u n2) {
   return a[n1] > a[n2];
}
bool compareb(u n1, u n2) {
   return b[n1] > b[n2];
}

void doCase() {
   u N;
   cin >> N;
   assert(N >= 1 && N <= maxN);

   for (u n = 0; n < N; n++) {
      cin >> a[n] >> b[n];
      assert(a[n] <= b[n] && b[n] <= maxNeed);
   }

   u c0 = N;
   u c1 = 0;
   for (u n = 0; n < N; n++) {
      at0a[n] = n;
      at0b[n] = n;
   }
   sort(at0a, at0a + N, comparea);
   sort(at0b, at0b + N, compareb);

   u stars = 0;
   u count = 0;
   while (c0 > 0 || c1 > 0) {
      bool got = false;
      while (c0 > 0 && stars >= b[at0b[c0-1]]) {
         u n = at0b[--c0];
         stars += 2;
         count++;
         got = true;
         u where = N;
         for (u k = 0; k <= c0; k++) {
            if (at0a[k] == n) {
               where = k;
               break;
            }
         }
         assert(where < N);
         while (where < c0) {
            at0a[where] = at0a[where + 1];
            where++;
         }
      }

      while (c1 > 0 && stars >= b[at1[c1-1]]) {
         c1--;
         stars += 1;
         count++;
         got = true;
      }

      if (got) {
         continue;
      }

      int best = -1;
      u bestk;
      for (int k = c0 - 1; k >= 0; k--) {
         if (a[at0a[k]] > stars) {
            break;
         }
         if ((int)b[at0a[k]] > best) {
            best = b[at0a[k]];
            bestk = k;
         }
      }
      if (best < 0) {
         cout << "Too Bad";
         return;
      }
      u n = at0a[bestk];
      stars += 1;
      count++;

      c0--;
      for (u k = bestk; k < c0; k++) {
         at0a[k] = at0a[k+1];
      }

      u where = N;
      for (u k = 0; k <= c0; k++) {
         if (at0b[k] == n) {
            where = k;
            break;
         }
      }
      assert(where < N);
      while (where < c0) {
         at0b[where] = at0b[where + 1];
         where++;
      }

      u k = c1++;
      while (k > 0 && b[at1[k-1]] < b[n]) {
         at1[k] = at1[k-1];
         k--;
      }
      at1[k] = n;
   }

   cout << count;
}

int main() {
   unsigned T;
   cin >> T;
   assert(T >= 1 && T <= maxT);

   for (unsigned t = 1; t <= T; t++) {
      cout << "Case #" << t << ": ";
      doCase();
      cout << endl;
   }
   return 0;
}
