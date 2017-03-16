#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;
#define pb         push_back
#define all(a)     (a).begin(),(a).end()
#define rall(a)    (a).rbegin(),(a).rend()
#define sz(a)      (int)((a).size())
#define rep(i,n)   for(int i=0; i<n; ++i)
#define REP(i,j,k) for(int i=j; i<k; ++i)
#define each(a,b)  for (__typeof((a).begin()) b=(a).begin(); b!=(a).end(); b++)

typedef long long ll;
int    INF = 100000000;
double EPS = 1e-8;
typedef vector<double> A;
int n;

int normal(A a, A b) {
  sort(all(a));
  sort(all(b));
  int s = 0;
  rep (i, sz(a)) {
    bool f = 0;
    each(b, it) {
      if (*it > a[i]) {
        f = 1;
        b.erase(it);
        break;
      }
    }
    if (!f) {
      b.erase(b.begin());
      s++;
    }
  }
  return s;
}

int deceitful(A a, A b) {
  int result = 0;
  sort(all(a));
  sort(rall(b));
  rep (d, n)  {
    A ta, tb;
    int s = 0;
    rep (i, d) {
      if (a[i] > b[i]) s++;
    }
    REP (i, d, n) {
      ta.pb(a[i]);
      tb.pb(b[i]);
    }
    sort(all(ta));
    sort(all(tb));
    rep (i, sz(ta)) s += (ta[i] > tb[i]);
    result = max(result, s);
  }
  return result;
}



int main () {
  int T; cin >> T;
  rep (t, T) {
    cin >> n;
    A a(n), b(n);
    rep (i, n) cin >> a[i];
    rep (i, n) cin >> b[i];

    cout << "Case #" << t+1 << ": ";
    cout << deceitful(a, b) << " ";
    cout << normal(a, b) << " " << endl;;


  }
  return 0;
}
