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

  int prepare() {
    vector <int> cs;
    for (int i = 0; i < (int)days.size(); i++) {
      for (int j = 0; j < (int)days[i].size(); j++) {
        const Event &e = days[i][j];
        cs.push_back (e.l);
        cs.push_back (e.r);
      }
    }
    
    sort (cs.begin(), cs.end());
    cs.erase (unique (cs.begin(), cs.end()), cs.end());
    vector <vector <Event> > new_days;

    for (int i = 0; i < (int)days.size(); i++) {
      if (days[i].empty()) {
        continue;
      }
      new_days.push_back (vector <Event>());
      for (int j = 0; j < (int)days[i].size(); j++) {
        const Event &e = days[i][j];
        int nl = lower_bound (cs.begin(), cs.end(), e.l) - cs.begin();
        int nr = lower_bound (cs.begin(), cs.end(), e.r) - cs.begin();
        new_days.back().push_back (Event(e.s, nl, nr));
      }
    }
    days = new_days;
    return cs.size();
  }
};


struct StupidTree {
  vector <int> v;
  StupidTree (int n) {
    v = vector <int> (n);
  }

  int get_min (int l, int r) {
    int res = v[l];
    for (int i = l; i <= r; i++) {
      if (v[i] < res) {
        res = v[i];
      }
    }
    return res;
  }
  void build (int l, int r, int s) {
    for (int i = l; i <= r; i++) {
      if (v[i] < s) {
        v[i] = s;
      }
    }
  }
};
const int inf = 2000000000;
struct Tree {
  vector <int> min_val;
  vector <int> todo;
  int act_len;
  Tree (int n) {
    act_len = 1;
    int len = 1;
    while (act_len < n) {
      act_len *= 2;
      len += act_len;
    }
    
    min_val = vector <int> (len);
    todo = vector <int> (len);
  }
  void upd (int v, int vl, int vr) {
    if (todo[v]) {
      if (min_val[v] < todo[v]) {
        min_val[v] = todo[v];
      }
      if (vl != vr) {
        todo[v * 2 + 1] = max (todo[v * 2 + 1], todo[v]);
        todo[v * 2 + 2] = max (todo[v * 2 + 2], todo[v]);
      }
      todo[v] = 0;
    }
  }
  int get_min_impl (int v, int vl, int vr, int l, int r) {
     if (r < vl || l > vr) {
       return inf;
     }
     upd (v, vl, vr);
     if (l <= vl && r >= vr) {
       return min_val[v];
     }
    
     int vc = (vl + vr) / 2;
     int a = get_min_impl (v * 2 + 1, vl, vc, l, r);
     int b = get_min_impl (v * 2 + 2, vc + 1, vr, l, r);
     return min (a, b);
  }
  void build_impl (int v, int vl, int vr, int l, int r, int s) {
    upd (v, vl, vr);
    if (r < vl || l > vr) {
      return;
    }
    if (l <= vl && r >= vr) {
      todo[v] = s;
      upd (v, vl, vr);
      return;
    }

    int vc = (vl + vr) / 2;
    int a = v * 2 + 1;
    int b = v * 2 + 2;
    build_impl (a, vl, vc, l, r, s);
    build_impl (b, vc + 1, vr, l, r, s);
    min_val[v] = min (min_val[a], min_val[b]);
  }

  int get_min (int l, int r) {
    return get_min_impl (0, 0, act_len - 1, l, r);
  }
  void build (int l, int r, int s) {
    build_impl (0, 0, act_len - 1, l, r, s);
  }
};


void run() {
  InputData input;
  input.read();
  int max_c = input.prepare();
  vector <vector <Event> >days = input.days;

  Tree tree(max_c);
  //StupidTree stree(max_c);
  
  vector <int> h (1000, 0);
  int res = 0;
  for (int i = 0; i < (int)days.size(); i++) {
    for (int j = 0; j < (int)days[i].size(); j++) {
      const Event &e = days[i][j];
      int ok = 0;
      int x = tree.get_min (e.l, e.r - 1);
      //int sx = stree.get_min (e.l, e.r - 1);
      //if (x != sx) {
        //fprintf (stderr, "%d %d | %d %d\n", x, sx, e.l, e.r - 1);
      //}
      res += x < e.s;
    }
    for (int j = 0; j < (int)days[i].size(); j++) {
      const Event &e = days[i][j];
      tree.build (e.l, e.r - 1, e.s);
      //stree.build (e.l, e.r - 1, e.s);
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
