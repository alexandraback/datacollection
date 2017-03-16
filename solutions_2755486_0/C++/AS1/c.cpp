#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int max_days = 700000;

struct Event {
  int s, l, r;
  Event (int s, int l, int r) : s(s), l(l), r(r){}
};

struct InputData {
  vector <vector <Event> > days;

  void read() {
    days.resize (max_days);
    int tribes_n;
    scanf ("%d", &tribes_n);
    for (int i = 0; i < tribes_n; i++) {
      int d, n, w, e, s, delta_d, delta_p, delta_s;
      scanf ("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
      while (n-- > 0) {
        days[d].push_back (Event (s, w, e));
        d += delta_d;
        w += delta_p;
        e += delta_p;
        s += delta_s;
      }
    }
  }

  void prepare() {
    for (int i = 0; i < (int)days.size(); i++) {
      for (int j = 0; j < (int)days[i].size(); j++) {
        Event &e = days[i][j];
        e.l += 500;
        e.r += 500;
        assert (e.l < 1000);
        assert (e.r < 1000);
      }
    }
  }
};

void run() {
  InputData input;
  input.read();
  input.prepare();
  vector <vector <Event> >days = input.days;

  vector <int> h (1000, 0);
  int res = 0;
  for (int i = 0; i < (int)days.size(); i++) {
    for (int j = 0; j < (int)days[i].size(); j++) {
      const Event &e = days[i][j];
      int ok = 0;
      //printf ("%d %d %d\n", e.l, e.r, e.s);
      for (int pos = e.l; pos < e.r; pos++) {
        ok |= h[pos] < e.s;
      }
      res += ok;
    }
    for (int j = 0; j < (int)days[i].size(); j++) {
      const Event &e = days[i][j];
      for (int pos = e.l; pos < e.r; pos++) {
        if (h[pos] < e.s) {
          h[pos] = e.s;
        }
      }
    }
  }
  printf ("%d\n", res);
}

int main (void) {
  int test_n;
  scanf ("%d", &test_n);
  for (int test_i = 0; test_i < test_n; test_i++) {
    fprintf (stderr, "%d\n", test_i);
    printf ("Case #%d: ", test_i + 1);
    run();
  }

  return 0;
}
