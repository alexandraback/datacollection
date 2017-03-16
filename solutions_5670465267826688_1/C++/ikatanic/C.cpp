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

const int MAX = 1000000;

enum {ONE, I, J, K};

struct Num {
  int x, sgn;
  
  friend Num operator * (const Num &a, const Num &b) {
    int s = a.sgn * b.sgn;
    if (a.x == ONE) return {b.x, s};
    if (b.x == ONE) return {a.x, s};
    if (a.x == b.x) return {ONE, -s};
    if (a.x == I) {
      if (b.x == J) return {K, s};
      if (b.x == K) return {J, -s};
    }
    if (a.x == J) {
      if (b.x == I) return {K, -s};
      if (b.x == K) return {I, s};
    }
    if (a.x == K) {
      if (b.x == I) return {J, s};
      if (b.x == J) return {I, -s};
    }
    assert(false);
  }
};

char s[MAX];
Num a[MAX];
int n;
llint x;

bool solve() {
  REP(i, n) {
    if (s[i] == 'i') a[i] = {I, 1};
    if (s[i] == 'j') a[i] = {J, 1};
    if (s[i] == 'k') a[i] = {K, 1};
  }

  Num period = {ONE, 1};
  REP(i, n) period = period * a[i];
  
  Num total = {ONE, 1};
  REP(i, x%4) total = total * period;

  if (total.x != ONE || total.sgn != -1) return false;

  int len = n; x--;
  while (len+n < MAX && x > 0) {
    REP(i, n) a[len++] = a[i];
    x--;
  }

  int first = len;
  Num pref = {ONE, 1};
  REP(i, len) {
    pref = pref * a[i];
    if (pref.x == I && pref.sgn == 1) { first = i; break; }
  }

  pref = {ONE, 1};
  for (int i = len-1; i > first; --i) {
    pref = a[i] * pref;
    if (pref.x == K && pref.sgn == 1) return true;
  }

  return false;
}

int main(void) {
  int TC;
  scanf("%d", &TC);
  for (int tp = 1; tp <= TC; ++tp) {
    scanf("%d %lld", &n, &x);
    scanf("%s", s);

    printf("Case #%d: ", tp);
    fprintf(stderr, "Case #%d: ", tp);
    
    string ans = solve() ? "YES" : "NO";
    printf("%s\n", ans.c_str());
    fprintf(stderr, "%s\n", ans.c_str());
    
  }
  return 0;
}
