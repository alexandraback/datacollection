#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int test_number = 0;
#define SIZE(A) (int((A).size()))
#define pb push_back
#define mp make_pair
#define gout printf("Case #%d: ", ++test_number);cout

struct Rat {
  LL p, q;
  Rat () {
    p = 0;
    q = 1;
  }
  Rat(long long a, long long b) {
    p = a;
    q = b;
    LL g = __gcd(p, q);
    p /= g; q /= g;
  }
  bool operator < (const Rat &a) const {
    if (p/q != a.p/a.q) {
      return p/q < a.p/a.q;
    }
    __int128 v = p;
    v *= a.q;
    __int128 u = q;
    u *= a.p;
    return v < u;
  }
};

bool Solve(int msk, const vector<pair<int,int>> &qq) {
  vector<pair<int,int>> q;
  for (int i = 0; i < SIZE(qq); ++i) {
    if (msk & (1<<i)) {
      q.pb(qq[i]);
    }
  }

  if (!SIZE(q)) {
    return true;
  }

  Rat best((360-q[0].first)*1LL*q[0].second, 360);
  Rat worst((360*2-q[0].first)*1LL*q[0].second, 360);
  for (int i = 0; i < SIZE(q); ++i) {
    Rat cur((360-q[i].first)*1LL*q[i].second, 360);
    if (best < cur) {
      best = cur;
    }
    Rat curw((360*2-q[i].first)*1LL*q[i].second, 360LL);
    if (curw < worst) {
      worst = curw;
    }
  }
  return best < worst;
}

int Greedy(const vector<pair<int,int>> &q) {
  Rat best((360-q[0].first)*1LL*q[0].second, 360);
  for (int i = 0; i < SIZE(q); ++i) {
    Rat cur((360-q[i].first)*1LL*q[i].second, 360);
    if (best < cur) {
      best = cur;
    }
  }
  int p;
  for (int i = 0; i < SIZE(q); ++i) {
    Rat cur((360-q[i].first)*1LL*q[i].second, 360);
    if (!(best < cur) && !(cur < best)) {
      p = i;
      break;
    }
  }
  LL res = 0;
  for (int i = 0; i < SIZE(q); ++i) {
    int lo = 0, hi = SIZE(q), mi;
    for (; lo < hi;) {
      mi = (lo + hi+1)>>1;
      Rat v((360*1LL*mi-q[i].first)*1LL*q[i].second, 360LL);
      if (best < v) {
        hi = mi-1;
      } else {
        lo = mi;
      }
    }
    res += lo;
  }
  res = min(res, (LL)SIZE(q));
  return (int)res;
}

void Main() {
  int N;
  cin >> N;
  vector<pair<int,int>> q;
  for (int i = 0; i < N; ++i) {
    int xs;
    cin >> xs;
    int h, m;
    cin >> h >> m;
    for (; h--;) {
      q.pb(mp(xs, m++));
    }
  }
  int res = SIZE(q);
  for (int msk = 0; msk < (1<<SIZE(q)); ++msk) {
    int cnt = SIZE(q)-__builtin_popcount(msk);
    if (cnt < res) {
      if (Solve(msk, q)) {
        res = cnt;
      }
    }
  }
  res = min(res, Greedy(q));
  gout << res << endl;
}

int main() {
  //std::ios_base::sync_with_stdio (false);
  int test;
  cin >> test;
  for (; test--;) {
    Main(); 
  }
  return 0;
}
