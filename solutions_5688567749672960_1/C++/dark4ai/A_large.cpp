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

ll s_to_ll (string s) {
  stringstream ss;
  ll n;
  ss << s;
  ss >> n;
  return n;
}

string ll_to_s (ll n) {
  stringstream ss;
  string s;
  ss << n;
  ss >> s;
  return s;
}

ll get_num (string s, int len) {
  ll n = s_to_ll (s);
  int d = len - ((int)s.size());
  assert (d > 0);
  REP(i, d) {
    n *= 10LL;
  }
  return n + 1LL;
}

int main() {
#ifdef DEBUG
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif
    int _test_count;
    cin >> _test_count;
    REP(_test_i, _test_count) {
        dbg("Processing test %d\n", _test_i + 1);
        ll n;
        cin >> n;
        ll ans = 1;
        while (n > 1) {
          // dbg("n = %lld\n", n);
          if (n % 10 != 0 && n >= 10) {
            string s = ll_to_s (n);
            int len = s.size();
            ll diff = -INFL;
            int diff_i = -1;
            for (int i = 1; i < len; ++i) {
              ll nn = get_num (s.substr(0, i), len);
              ll cost = nn - get_rev (nn);
              // dbg("(%lld,C%lld,%d) ", nn, cost,i);
              if (diff < cost) {
                diff = cost;
                diff_i = i;
              }
            }
            // dbg("\n");
            // dbg("diff_i = %d\n", diff_i);
            assert (diff_i != -1);
            ll nn = get_num (s.substr(0, diff_i), len);
            ll rev = get_rev (nn);
            if (rev == n) {
              ans += 1;
              n--;
            } else {
              ll dd = min (n - nn + 1LL, n - rev);
              assert (dd > 0);
              ans += dd;
              // dbg("ADD %lld\n", dd);
              n = rev;
            }
          } else {
            n--;
            ans += 1LL;
          }    
        }
        printf("Case #%d: ", _test_i + 1);
        printf("%lld\n", ans);
    }
    return 0;
}