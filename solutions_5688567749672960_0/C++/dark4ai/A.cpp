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

#define MAXN 2000000
ll d[MAXN];

ll get_rev (ll n) {
  stringstream ss;
  string s;
  ss << n;
  ss >> s;
  reverse(s.begin(), s.end());
  stringstream ss2;
  ss2 << s;
  ss2 >> n;
  return n;
}

int main() {
#ifdef DEBUG
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int _test_count;
    cin >> _test_count;
    REP(_test_i, _test_count) {
        dbg("Processing test %d\n", _test_i + 1);
        memset (d, -1, sizeof (d));
        ll n;
        cin >> n;
        d[n] = 1;
        for (int i = n - 1; i > 0; --i) {
          d[i] = INFL;
          ll rev = get_rev (i);
          if (i < rev && rev <= n) {
            d[i] = min (d[i], d[rev] + 1);
          }
          d[i] = min (d[i], d[i + 1] + 1);
        }
        printf("Case #%d: ", _test_i + 1);
        printf("%lld\n", d[1]);
    }
    return 0;
}