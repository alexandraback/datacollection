#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int rev(ll* i) {
  ll o = 0;
  while (*i) {
    o *= 10;
    o += *i % 10;
    *i /= 10;
  }
  *i = o;
  return 1;
}

int dec(ll* i) {
  *i -= 1;
  return 1;
}

bool isBase(ll i) {
  if (i % 10 != 1) return false;
  i /= 10;
  while (i >= 10) {
    if (i % 10 != 0) return false;
    i /= 10;
  }
  return i % 10 == 1;
}

bool isPowerOf10(ll i) {
  while (i >= 10) {
    if (i % 10 != 0) return false;
    i /= 10;
  }
  return i % 10 == 1;
}

int takeDown(ll* i) {
  ll n = *i;
  int digits = 0;
  while (n) {
    n /= 10; ++digits;
  }
  digits = (digits + 1) / 2;
  ll p = 1;
  bool ok = false;
  REP(k,digits) {
    int m = (*i / p) % 10;
    if (m) {
      ok = true;
      break;
    }
    p *= 10;
  }
  int ans = 0;
  if (!ok) {
    ans += dec(i);
    ans += takeDown(i);
    return ans;
  }
  p = 1;
  REP(k,digits) {
    int m = (*i / p) % 10;
    if (k == 0) --m;
    ans += p * m;
    *i -= p * m;
    p *= 10;
  }
  return ans;
}

int solve(ll N) {
  int ans = 0;
  while (N > 1) {
    //DEBUG(N);
    //DEBUG(ans);
    if (isBase(N)) {
      ans += dec(&N);
      continue;
    }
    if (isPowerOf10(N)) {
      ans += dec(&N);
      continue;
    }
    ans += takeDown(&N);
    //DEBUG(N);
    //DEBUG(ans);
    if (N > 1) {
      ll oN = N;
      int r = rev(&N);
      if (oN != N) {
        ans += r;
      }
    }
  }
  return ans + 1;
}

int main() {
  int T;
  scanf("%d", &T);
  REP(t,T) {
    ll N;
    scanf("%lld", &N);
    printf("Case #%d: %d\n", t+1, solve(N));
  }
  return 0;
}
