#include <algorithm>
#include <functional>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <map>

using namespace std;

#define FOR_EACH(it, V) for(__typeof((V).begin()) it = (V).begin(); it != (V).end(); ++it)

struct Attack {
  int l, r, s;

  Attack() {}
  Attack(int _l, int _r, int _s) : l(_l), r(_r), s(_s) {}
};

vector<int> rez;
inline int getIdx(int x) {
  int val = lower_bound(rez.begin(), rez.end(), x) - rez.begin(); 
  assert(rez[val] == x);
  return val;
}

struct State {
  State() { minVal = 0; push = 0; } 
  
  int minVal;
  int push;

  void updatePush(int val) {
    push = max(push, val);
    if (minVal < push) {
      minVal = push;
    }
  }
};

const int inf = 1e9;

struct Tournament {
  int offset;
  vector<State> data;

  int from;
  int to;
  int push;

  Tournament(int _n) {
    for (offset = 1; offset < _n; offset *= 2);
    data.clear();
    data.resize(2 * offset);
  }

  int getMin(int l, int r) {
    from = l;
    to = r;

    int ret = getMin(1, 0, offset);
    return ret;
  }
  int getMin(int x, int lo, int hi) {
    if (to <= lo || hi <= from) return +inf;
    if (from <= lo && hi <= to) return data[x].minVal;
    if (data[x].push) {
      data[2*x].updatePush(data[x].push);
      data[2*x+1].updatePush(data[x].push);
      data[x].push = 0;
    }
    return min(getMin(2*x, lo, (lo+hi) / 2), getMin(2*x+1, (lo+hi) / 2, hi));
  }

  void pushMax(int l, int r, int s) {
    from = l;
    to = r;
    push = s;

    doPush(1, 0, offset);
  }
  void doPush(int x, int lo, int hi) {
    if (to <= lo || hi <= from) return;
    if (from <= lo && hi <= to) {
      data[x].updatePush(push);
      return;
    }
    if (data[x].push) {
      data[2*x].updatePush(data[x].push);
      data[2*x+1].updatePush(data[x].push);
      data[x].push = 0;
    }
    doPush(2*x, lo, (lo+hi)/2);
    doPush(2*x+1, (lo+hi)/2, hi);
    data[x].minVal = min(data[2*x].minVal, data[2*x+1].minVal);
  }
};



int main(void)
{
  int T; scanf("%d", &T);

  for (int counter = 0; counter < T; ++counter) {
    int N; scanf("%d", &N);

    map<int, vector<Attack> > attacks;
    rez.clear();

    for (int i = 0; i < N; ++i) {
      int d, n; scanf("%d %d", &d, &n);
      int l, r, s; scanf("%d %d %d", &l, &r, &s);
      int d_d, d_p, d_s; scanf("%d %d %d", &d_d, &d_p, &d_s);

      for (int t = 0; t < n; ++t) {
        int L = l + t*d_p;
        int R = r + t*d_p;
        attacks[d + t*d_d].push_back(Attack(L, R, s + t*d_s));
        rez.push_back(L);
        rez.push_back(R);
      }
    }
    
    sort(rez.begin(), rez.end());
    rez.resize(unique(rez.begin(), rez.end()) - rez.begin());

    Tournament tour((int)rez.size());

    int cnt = 0;

    // FOR_EACH(it, rez) {
    //   printf("%d ", *it);
    // }    
    // putchar('\n');
    

    FOR_EACH(it, attacks) {
      // printf("day = %d attacks = %d\n", it->first, (int)it->second.size());
      // FOR_EACH(it_v, it->second) { 
      //   printf("[%d (%d), %d (%d)] s = %d\n", it_v->l, getIdx(it_v->l), it_v->r, getIdx(it_v->r), it_v->s);
      // }
      // putchar('\n');

      FOR_EACH(it_v, it->second) {
        int l = getIdx(it_v->l);
        int r = getIdx(it_v->r);
        int s = it_v->s;
        if (tour.getMin(l, r) < s)
          ++cnt;
      }

      FOR_EACH(it_v, it->second) {
        int l = getIdx(it_v->l);
        int r = getIdx(it_v->r);
        int s = it_v->s;
        tour.pushMax(l, r, s);
      }
    }

    printf("Case #%d: %d\n", counter + 1, cnt);
    fflush(stdout);
  }

  return (0-0);
}
