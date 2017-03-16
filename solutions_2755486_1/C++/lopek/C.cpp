#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <functional>
#include <bitset>
#include <list>
#include <cstring>
#include <complex>
using namespace std;

typedef int ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define FOR(i, p, k) for(int i = (p); i <= (k); ++i)
#define FORD(i, p, k) for(int i = (p); i >= (k); --i)
#define FOREACH(x,Z) for(__typeof((Z).begin()) x=(Z).begin();x!=(Z).end();++x)

#define mp make_pair
#define pb push_back
#define st first
#define nd second

#define INF 1000000000

struct node {
  int w, e, mins, ms;
  int l, r;
  node() {}
  node(int w, int e) : w(w), e(e), mins(0), ms(0), l(-1), r(-1) {}
};

struct attack {
  int d;
  ll s, w, e;
  
  attack(int d, int s, int w, int e) : d(d), s(s), w(w), e(e) {}
};

bool operator<(const attack &A, const attack &B) {
  return A.d < B.d;
}

vector<attack> A;
node T[31000000];
int last = 0;

ll inline gets(int w, int e) {
    ll s = w + e;
    if (s < 0) s--;
    return s / 2;
}

int get_min(int w, int e, int i) {
  if (T[i].w == w && T[i].e == e) return T[i].mins;
  ll s = gets(T[i].w, T[i].e);
  ll mins = INF;
  if (w <= s) {
    if (T[i].l == -1) mins = T[i].ms;
    else mins = get_min(w, min(s, e), T[i].l);
  }
  if (e > s) {
    if (T[i].r == -1) mins = T[i].ms;
    else mins = min(mins, get_min(max(s + 1, w), e, T[i].r));
  }
  return max(T[i].ms, mins);
}

void tree_max(ll w, ll e, ll str, int i) {
  if (T[i].w == w && T[i].e == e) {
    T[i].ms = max(T[i].ms, str);
  } else {
    ll s = gets(T[i].w, T[i].e);
    if (w <= s) {
      if (T[i].l == -1) {
        T[i].l = ++last;
        T[last] = node(T[i].w, s);
      }
      tree_max(w, min(s, e), str, T[i].l);
    }
    if (e > s) {
      if (T[i].r == -1) {
        T[i].r = ++last;
        T[last] = node(s + 1, T[i].e);
      }
      tree_max(max(s + 1, w), e, str, T[i].r);
    }
  }
  
  if (T[i].l == -1 && T[i].r == -1) T[i].mins = T[i].ms;
  else {
    T[i].mins = INF;
    T[i].mins = T[i].l == -1 ? 0 : T[T[i].l].mins;
    T[i].mins = min(T[i].mins, T[i].r == -1 ? 0 : T[T[i].r].mins);
    T[i].mins = max(T[i].mins, T[i].ms);
  }
}

int main() {
  int Z; scanf("%d", &Z);
  FOR(t, 1, Z) {
    A.clear();
    T[0].w = -INF;
    T[0].e = INF;
    T[0].mins = T[0].ms = 0;
    T[0].l = T[0].r = -1;
    last = 0;
    int N; scanf("%d", &N);
    while (N--) {
      int d, n, dd, dp, ds;
      ll w, e, s;
      scanf("%d %d %d %d %d %d %d %d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
      --e;
      while (n--) {
        A.pb(attack(d, s, w, e));
        d += dd;
        s += ds;
        w += dp;
        e += dp;
      }
    }
    sort(A.begin(), A.end());
    int prevd = -1;
    vector<attack> upd;
    int res = 0;
    FOREACH(a, A) {
      if (a->d != prevd) {
        FOREACH(u, upd) {
          tree_max(u->w, u->e, u->s, 0);
        }
        upd.clear();
        prevd = a->d;
      }
      if (get_min(a->w, a->e, 0) < a->s) res++;
      //printf("Attack: d = %d, w = %lld, e = %lld, s = %lld, min = %lld\n", a->d, a->w, a->e, a->s, get_min(a->w, a->e, 0));
      upd.pb(*a);
    }
    printf("Case #%d: %d\n", t, res);
  }
  return 0;
}
