#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forn1(i, n) for (int i = 1; i <= (int)(n); i++)

struct Hiker {
   int start_pos;
   int inv_speed; // minute / revolution
   double speed; // degrees / minute
   double zero_time; // The first moment he reaches zero, in minutes

   Hiker( int p, int s) : start_pos (p), inv_speed (s)
   {
      speed = 360.0 / s; // Degrees / minute
      zero_time = ((360 - start_pos) / speed);
   }
};

void solve()
{
   // Get hikers
   vector<Hiker> v_hik;
   int lines;
   cin >> lines;
   forn( i, lines ) {
      int pos, num, inv_spd;
      cin >> pos >> num >> inv_spd;

      while (num > 0) {
         v_hik.push_back( Hiker( pos, inv_spd ) );
         inv_spd++;
         num--;
      }
   }

   if (v_hik.size() <= 1) {
      cout << "0" << endl;
      return;
   }

   // Easy Solution to two hikers
   if (v_hik.size() == 2) {
      Hiker h1 = v_hik.at(0);
      Hiker h2 = v_hik.at(1);
      if (h1.speed == h2.speed) {
         cout << "0" << endl;
         return;
      }
      if (h1.speed < h2.speed) {
         h1 = v_hik.at(1);
         h2 = v_hik.at(0);
      }
      // h2 is slower - if we catch up, then travel at his speed, will we meet h1?
      if ((h2.zero_time <= h1.zero_time)) {
         cout << "0" << endl;
         return;
      }
      double h1_zero2 = h1.zero_time + h1.inv_speed;
      if (h1_zero2 > h2.zero_time) {
         cout << "0" << endl;
         return;
      }

      cout << "1" << endl;
      return;
   }

   cout << "0" << endl;
}

int main()
{
   freopen("three.in", "r", stdin);
   freopen("three.out", "w", stdout);

   long count;
   cin >> count;
   forn1(i, count) {
      cout << "Case #" << i << ": ";
      solve();
   }
   return 0;
} 
