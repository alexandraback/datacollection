#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define dbg(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define dbg(fmt, args...)
#endif
#define REPS(i, s, n) for(int (i) = (s); (i) < (int)(n); ++(i))
#define REP(i, n) REPS(i, 0, n)
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define x first
#define y second
#define INFI 1234567890
#define INFL 1234567890123456789LL
typedef long long ll;

using namespace std;

int n;
int h_c = 0;
double pos[2], speed[2];

int solve (int h1) {
  int h2 = h1 ^ 1;
  double t = 0;
  double per = 0;
  if (speed[h1] > speed[h2]) {
    t = pos[h2] / (speed[h1] - speed[h2]);
    per = 1.0 / (speed[h1] - speed[h2]);
  } else {
    t = (1.0 - pos[h2]) / (speed[h2] - speed[h1]);
    per = 1.0 / (speed[h2] - speed[h1]);
  }
  int ans = 0;
  double ps = t * speed[h1];
  while (ps <= 1.0) {
    ans++;
    ps += per * speed[h1];
  }
  return ans;
}

int main() {
#ifdef DEBUG
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
#endif
    int _test_count;
    cin >> _test_count;
    REP(_test_i, _test_count) {
        dbg("Processing test %d\n", _test_i + 1);
        cin >> n;
        assert (n <= 2);
        h_c = 0;
        REP(i, n) {
          int p, c, s;
          cin >> p >> c >> s;
          pos[h_c] = p;
          speed[h_c] = s;
          h_c++;
          if (c > 1) {
            pos[h_c] = p;
            speed[h_c] = s + 1;
            h_c++;
          }
        }
        ll ans = 0;
        if (h_c > 1 && speed[0] != speed[1]) {
          REP(i, h_c) {
            speed[i] = 1.0 / speed[i];
            pos[i] = pos[i] / 360.0;
          }
          ans = min (solve (0), solve (1));
        }
        printf("Case #%d: ", _test_i + 1);
        printf("%lld\n", ans);
    }
    return 0;
}