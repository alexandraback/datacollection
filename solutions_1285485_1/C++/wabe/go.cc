#include <iostream>
#include <string>
using namespace std;

#include <assert.h>

const unsigned maxT = 100;
const unsigned maxHW = 100;
const unsigned maxD = 50;

unsigned H, W, D;
unsigned myH, myW;
char map[maxHW][maxHW];

unsigned gcd(int m, int n) {
   assert(m > 0 && n > 0);
   if (m > n) {
      int t = m;
      m = n;
      n = t;
   }
   while (m > 1) {
      int rem = n % m;
      if (rem == 0) {
         return m;
      }
      n = m;
      m = rem;
   }
   return 1;
}

unsigned straight(int dh, int dw) {
   unsigned dots = 0;
   int h = myH;
   int w = myW;
   for (;;) {
      h += dh;
      w += dw;
      if (map[h][w] == '.') {
         dots++;
      } else {
         break;
      }
   }
   if (2 * dots + 1 <= D) {
      return 1;
   } else {
      return 0;
   }
}

int test(int hcoord, int wcoord, int dh, int dw, int mult) {
int odh = dh; int odw = dw;
   int hgrid = 2 * wcoord;
   int wgrid = 2 * hcoord;
   int dist = 2 * hcoord * wcoord * mult;

   int hstart = myH * hgrid + wcoord;
   int wstart = myW * wgrid + hcoord;
   int h = hstart;
   int w = wstart;
   for (; dist > 0; dist--) {
      int hcell = h;
      if (dh < 0) {
         hcell = h - 1;
      }
      int wcell = w;
      if (dw < 0) {
         wcell = w - 1;
      }
      char newtype = map[hcell/hgrid][wcell/wgrid];
      if (newtype == '#') {
         int hhcell = h;
         if (dh > 0) {
            hhcell = h - 1;
         }
         int wwcell = w;
         if (dw > 0) {
            wwcell = w - 1;
         }
         char htype = map[hhcell/hgrid][wcell/wgrid];
         char wtype = map[hcell/hgrid][wwcell/wgrid];
         if (htype == '#') {
            dw = -dw;
            if (wtype == '#') {
               dh = -dh;
            }
         } else if (wtype == '#') {
            dh = -dh;
         } else {
            return 0;
         }
      }

      h += dh;
      w += dw;
      if (h == hstart && w == wstart) {
         return 1;
      }
   }
   return 0;
}

void doCase() {
   cin >> H >> W >> D;
   assert(H >= 3 && H <= maxHW);
   assert(W >= 3 && W <= maxHW);
   assert(D >= 1 && D <= maxD);

   myH = maxHW;
   myW = maxHW;
   string line;
   for (unsigned h = 0; h < H; h++) {
      cin >> line;
      assert(line.length() == W);
      for (unsigned w = 0; w < W; w++) {
         char c = line[w];
         assert(c == '.' || c == '#' || c == 'X');
         map[h][w] = c;
         if (c == 'X') {
            assert(myH == maxHW);
            myH = h;
            myW = w;
         }
      }
   }
   assert(myH < maxHW);
   for (unsigned h = 0; h < H; h++) {
      assert(map[h][0] == '#' && map[h][W-1] == '#');
   }
   for (unsigned w = 0; w < W; w++) {
      assert(map[0][w] == '#' && map[H-1][w] == '#');
   }

   unsigned images = 0;
   images += straight(0, 1);
   images += straight(0, -1);
   images += straight(1, 0);
   images += straight(-1, 0);

   for (int h = 1; h < D; h++) {
      for (int w = 1; h*h + w*w <= D*D; w++) {
         if (gcd(h, w) == 1) {
            int mult = 1;
            while ((mult+1)*(mult+1)*(h*h + w*w) <= D*D) {
               mult++;
            }
            images += test(h, w, 1, 1, mult);
            images += test(h, w, 1, -1, mult);
            images += test(h, w, -1, 1, mult);
            images += test(h, w, -1, -1, mult);
         }
      }
   }

   cout << images << endl;
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
