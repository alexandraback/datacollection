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
    return p*a.q < q*a.p;
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
    Rat curw((360*2-q[i].first)*1LL*q[i].second, 360);
    //cerr << "Here fraction for i=" << i << " is: " << (360*2.-q[i].first)/360.0*q[i].second << endl;
    if (curw < worst) {
      worst = curw;
    }
  }
  /*
  cerr << "SIZE: " << SIZE(q) << endl;
  cerr << "Here best: " << best.p << "/" << best.q << endl;
  cerr << "Here worst: " << worst.p << "/" << worst.q << endl;
  */
  return best < worst;
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
