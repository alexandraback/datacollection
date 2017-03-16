#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <assert.h>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
static const double EPS = 1e-9;
static const double PI = acos(-1.0);

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, n) for (int i = (s); i < (int)(n); i++)
#define FOREQ(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define FORIT(it, c) for (__typeof((c).begin())it = (c).begin(); it != (c).end(); it++)
#define MEMSET(v, h) memset((v), h, sizeof(v))

void solve();
int main() {
  int test;
  scanf("%d", &test);
  char str[1000];
  fgets(str, 999, stdin);
  int test_case = 0;
  while (test--) {
    test_case++;
    printf("Case #%d: ", test_case);
    // puts("");
    solve();
  }
}

string mapto[200][200];
string neg(string str) {
  string ret = "";
  if (str.size() == 2) { ret = str[1]; }
  else { ret = "-" + str; }
  return ret;
}

string mul(string lhs, string rhs) {
  char l = lhs.size() == 2 ? lhs[1] : lhs[0];
  char r = rhs.size() == 2 ? rhs[1] : rhs[0];
  string next = mapto[(int)l][(int)r];
  if (lhs.size() == 2) {
    next = neg(next);
  }
  if (rhs.size() == 2) {
    next = neg(next);
  }
  return next;
}

string pow(string base, ll power) {
  string ret = "1";
  while (power > 0) {
    if (power & 1) {
      ret = mul(ret, base);
    }
    base = mul(base, base);
    power >>= 1;
  }
  return ret;
}

char input[10100];
void solve() {
  mapto[(int)'1'][(int)'1'] = "1";
  mapto[(int)'1'][(int)'i'] = "i";
  mapto[(int)'1'][(int)'j'] = "j";
  mapto[(int)'1'][(int)'k'] = "k";
  mapto[(int)'i'][(int)'1'] = "i";
  mapto[(int)'i'][(int)'i'] = "-1";
  mapto[(int)'i'][(int)'j'] = "k";
  mapto[(int)'i'][(int)'k'] = "-j";
  mapto[(int)'j'][(int)'1'] = "j";
  mapto[(int)'j'][(int)'i'] = "-k";
  mapto[(int)'j'][(int)'j'] = "-1";
  mapto[(int)'j'][(int)'k'] = "i";
  mapto[(int)'k'][(int)'1'] = "k";
  mapto[(int)'k'][(int)'i'] = "j";
  mapto[(int)'k'][(int)'j'] = "-i";
  mapto[(int)'k'][(int)'k'] = "-1";
  ll n, m;
  scanf("%lld %lld", &n, &m);
  scanf("%s", input);
  string base = "1";
  REP(i, n) {
    string rhs;
    rhs = input[i];
    base = mul(base, rhs);
  }

  string istr = "1";
  string jstr = "1";
  ll cnt = min(10LL, m);
  m -= cnt;
  string str = "1";
  REP(iter, cnt) {
    REP(i, n) {
      string rhs;
      rhs = input[i];
      str = mul(str, rhs);
      if (istr == "1" && str == "i") { istr = "i"; str = "1"; }
      if (istr == "i" && jstr == "1" && str == "j") { jstr = "j"; str = "1"; }
    }
  }

  string rest = pow(base, m);
  string kstr = mul(str, rest);
  if (istr == "i" && jstr == "j" && kstr == "k") {
    puts("YES");
  } else {
    puts("NO");
  }
}
