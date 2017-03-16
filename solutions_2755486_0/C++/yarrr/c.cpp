#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stdint.h>
#include <map>
#include <queue>

using namespace std;

typedef int64_t ll;

const int add = 1000, m = 2 * add + 1, days = 676070;

struct attack {
  int l, r, s;

  attack(int l, int r, int s) :
    l(l), r(r), s(s)
  { }
};

int solve() {
  int n;
  cin >> n;

  vector < vector < attack > > attacks(days);

  for(int i = 0; i < n; i++) {
    int start_day, number_attack, l, r, s, delta_d, delta_p, delta_s;

    cin >> start_day >> number_attack >> l >> r >> s >> delta_d >> delta_p >> delta_s;

    l += add;
    r += add;

    for(int j = 0; j < number_attack; j++) {
      assert(l >= 0 && l < m && r >= 0 && r < m && l < r);

      attacks[start_day].push_back(attack(l, r - 1, s));

      start_day += delta_d;
      l += delta_p;
      r += delta_p;
      s += delta_s;
    }
  }

  vector < int > wall(m, 0), new_wall(m, 0);

  int res = 0;

  for(int day = 0; day < days; day++) {
    if(attacks[day].size() > 0) {
      copy(wall.begin(), wall.end(), new_wall.begin());

      for(vector < attack > :: const_iterator it = attacks[day].begin(); it != attacks[day].end(); ++it) {
        const attack& a = *it;

        bool success = false;

        for(int x = a.l; x <= a.r; x++) {
          if(wall[x] < a.s)
            success = true;

          new_wall[x] = max(new_wall[x], a.s);
        }

        if(success)
          ++res;
      }

      copy(new_wall.begin(), new_wall.end(), wall.begin());
    }
  }



  return res;
}

int main() {
  int tests;
  cin >> tests;

  for(int i = 1; i <= tests; i++) {
    cout << "Case #" << i << ": " << solve() << endl;
  }

  return 0;
}