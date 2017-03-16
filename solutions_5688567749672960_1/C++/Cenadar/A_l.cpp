#pragma comment (linker, "/STACK:1073741824")
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#include <string>
#include <bitset>
#include <complex>

using namespace std;

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second
#define GET_RUNTIME_ERROR *(int*)(NULL) = 1

typedef vector<int> vint;
typedef vector<long long> vLL;
typedef double dbl;
typedef long double ldbl;
typedef vector<pair<int, int> > vpii;
typedef long long LL;
typedef pair<int, int> pii;

string tostr(LL n) {
  string s;
  while(n) {
    s += '0' + (n % 10);
    n /= 10;
  }
  return string(s.rbegin(), s.rend());
}

int len(LL n) {
  return tostr(n).size();
}

LL toLL(string s) {
  LL n = 0;
  FE(i, s) {
    n *= 10;
    n += s.begin()[i] - '0';
  }
  return n;
}

LL rev(LL n) {
  LL r = 0;
  while(n) {
    r = r*10 + n%10;
    n /= 10;
  }
  return r;
}

LL poww(LL x, LL n) {
  LL a = 1;
  while(n--) a *= x;
  return a;
}

LL poww10(LL n) {
  return poww(10, n);
}

LL reach(LL cur, LL dest);

LL reach0(LL cur, LL dest) {
  return dest - cur;
}

LL reach1(LL cur, LL dest) {
  if (cur == 1) return LLINF;

  if (dest % 10 == 0) {
    return 1 + reach(cur, dest - 1);
  }

  int l = len(cur);
  int mid = l/2;
  int mid_up = l - mid;

  LL vr = dest % poww10(mid_up);
  LL vl = rev(dest) % poww10(mid);
  return 1 + vl + vr - 1;
}

LL reach2(LL cur, LL dest) {
  return LLINF;
  if (cur == 1) return LLINF;

  if (dest % 10 == 0) {
    return 1 + reach(cur, dest - 1);
  }

  int l = len(cur);
  int mid = l/2;
  int mid_up = l - mid;

  LL vr = dest % poww10(mid_up);
  LL vl = rev(dest) % poww10(mid);
  return 2 + vl + vr - 1;

  return INF;
}

LL reach(LL cur, LL dest) {
  LL v0 = reach0(cur, dest);
  LL v1 = reach1(cur, dest);
  LL v2 = reach2(cur, dest);
  return min(v0, min(v1, v2));
}

LL solve(LL n) {
  LL cur = 1;
  LL ans = 0;
  while (len(cur) < len(n)) {
    LL next = poww10(len(cur));
    LL add = reach(cur, next - 1) + 1;
    ans += add;
    cur = next;
  }

  LL add_final = reach(cur, n);
  ans += add_final;
  return ans + 1;
}

namespace small {

const int nmax = 10000100;

int mn[nmax];
queue<int> q, to;

void precalc() {
  if (mn[1] != 0) return;

  mn[1] = 1;
  q.push(1);
  while(!q.empty()) {
    while(!q.empty()) {
      int v = q.front();
      q.pop();

      int t = rev(v);
      if (t < nmax && mn[t] == 0) to.push(t), mn[t] = mn[v] + 1;
      t = v + 1;
      if (t < nmax && mn[t] == 0) to.push(t), mn[t] = mn[v] + 1;
    }
    swap(q, to);
  }
}

LL solve(LL n) {
  precalc();
  return mn[n];
}

}

int main() {
#ifdef    CENADAR_DEBUG
  freopen("input.txt", "r", stdin);
  freopen("/home/maksym/Downloads/A-large.in", "r", stdin);
  freopen("output.txt", "w", stdout);
//  freopen("errput.txt", "w", stderr);
#else  // CENADAR_DEBUG
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
#endif // CENADAR_DEBUG

  int T;
  cin >> T;
  //T = 1000000;
  REP(test, T) {
    LL n;
    cin >> n;

    LL ans = solve(n);
    LL sm = n <= 1000000 ? small::solve(n) : ans;
    if (ans != sm) {
      cerr << n << ": ";
      cerr << ans << " " << small::solve(n) << endl;
      return 0;
    }
    assert(ans == sm);

    printf("Case #%d: %lld\n", test + 1, ans);
  }

  return 0;
}
