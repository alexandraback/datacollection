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

struct Tournament {
  int n;
  vector<int> data;

  Tournament(int _n) : n(_n) {
    data.resize(_n, 0);
  }

  int getMin(int l, int r) {
    int mini = data[l];

    for (int i = l; i < r; ++i)
      if (data[i] < mini)
        mini = data[i];

    return mini;
  }

  void pushMax(int l, int r, int s) {
    for (int i = l; i < r; ++i)
      if (data[i] < s)
        data[i] = s;
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
