#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

struct Hiker {
  int pos, period;
  friend bool operator < (const Hiker &a, const Hiker &b) {
    if (a.pos != b.pos) return a.pos < b.pos;
    return a.period > b.period;
  }
};

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp, fflush(stdout)) {
    int m;
    scanf("%d", &m);

    vector<Hiker> v;
    REP(i, m) {
      int d, h, mm;
      scanf("%d %d %d", &d, &h, &mm);
      REP(j, h) v.push_back({d, mm + j});
    }
    sort(v.begin(), v.end());

    int n = v.size();
    llint ans = n;
    
    REP(i, n) {
      llint cnt = i;
      REP(j, n) {
        llint p1 = v[i].period, d1 = v[i].pos;
        llint p2 = v[j].period, d2 = v[j].pos;
        
        if (p1 == p2) continue;
        
        long double rem = p1 * (360 - d1) / 360.0;
        long double v1 = 1.0 / p1;
        long double v2 = 1.0 / p2;
        if (v1 > v2) {
          llint diff = (d2-d1+360)%360;
          long double t = (diff / 360.0) / (v1 - v2);
          if (v1*t <= rem && d1 != d2) cnt++;
        } else {
          llint diff = (d1-d2+360)%360;
          long double t = (diff / 360.0) / (v2 - v1);
          long double p = 1.0 / (v2 - v1);

          if (v1*t <= rem) {
            if (d1 != d2) cnt++;
            rem -= v1*t;
            cnt += (rem-1e-12) / (p*v1);
          }
        }
      }

      ans = min(ans, cnt);
    }

    printf("Case #%d: ", tp);
    printf("%lld\n", ans);
  }
  return 0;
}
