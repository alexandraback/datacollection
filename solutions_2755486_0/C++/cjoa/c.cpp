#include <iostream>

#include <algorithm>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define SZ(a) int((a).size())

typedef long long llong;

struct Tribe {
   int day;
   int nattacks;
   int west, east;
   int strength;
   int delta_d, delta_p, delta_s;

   int L, R, rem_attacks;
   llong cur_s;
};

struct Event {
   int day;
   int tribe_id;
   Event(int _d, int _id) : day(_d), tribe_id(_id) {}
   bool operator<(const Event& e) const {
      if (day != e.day) return day > e.day;
      return tribe_id > e.tribe_id;
   }
};

int main(int argc, char* argv[]) {
   ios_base::sync_with_stdio(false); 
   cin.tie(NULL);

   int TC;
   cin >> TC;
   for (int tc = 1; tc <= TC; ++tc) {
      vector<Tribe> tribes;
      priority_queue<Event> events;
      int N;
      cin >> N;
      for (int i = 0; i < N; ++i) {
         Tribe tr;
         cin >> tr.day >> tr.nattacks >> tr.west >> tr.east >> tr.strength
             >> tr.delta_d >> tr.delta_p >> tr.delta_s;
         tr.L = tr.west;
         tr.R = tr.east-1;
         tr.cur_s = tr.strength;
         tr.rem_attacks = tr.nattacks;
         tribes.push_back(tr);
         events.push(Event( tr.day, i ));
      }

      llong res = 0;
      const int OFFSET = 1002;
      vector<llong> wall(2004);
      for (llong last_day = -1, max_s = 0, L = -1, R = -1; !events.empty(); ) {
         Event ev = events.top();
         events.pop();
         Tribe& tr = tribes[ev.tribe_id];

         if (last_day != ev.day) {
            // raise heigth of wall
            if (L >= 0 && R >= 0) {
               for (int x = L; x <= R; ++x) {
               //   cerr << "Raising wall at pos " << x << endl;
                  wall[x + OFFSET] = max(wall[x + OFFSET], max_s);
               }
            }
            L = -1; R = -1;
            max_s = 0;
         }

         bool attacked = false;
         for (int x = tr.L; x <= tr.R; ++x) {
         //   if (ev.tribe_id == 1 && ev.day == 10)
         //      cerr << "* " << wall[x + OFFSET] << ' ' << tr.cur_s << endl;
            if (wall[x + OFFSET] < tr.cur_s) {
               attacked = true;
               break;
            }
         }
/*
         cerr << "Day " << ev.day
              << " Tribe " << ev.tribe_id
              << " [" << tr.L << ", " << tr.R << "]"
              << " " << tr.cur_s
              << " " << attacked 
              << endl;
*/

         if (attacked) {
            ++res;
            if (L < 0 || L > tr.L)
               L = tr.L;
            if (R < 0 || R < tr.R)
               R = tr.R;
            max_s = max(max_s, tr.cur_s);
         }
         tr.rem_attacks--;
         if (tr.rem_attacks > 0) {
            tr.L += tr.delta_p;
            tr.R += tr.delta_p;
            tr.cur_s += tr.delta_s;
            events.push(Event( ev.day + tr.delta_d, ev.tribe_id ));
         }

         last_day = ev.day;
      }
      
      cout << "Case #" << tc << ": " << res << endl;
   }

   return 0;
}
