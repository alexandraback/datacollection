/* Written by Filip Hlasek 2016 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

long long to_int(string x) {
  long long n = 0;
  REP(i, x.size()) n = 10 * n + x[i] - '0';
  return n;
}

pair<string, string> better(pair<string, string> a1, pair<string, string> a2) {
  long long d1 = abs(to_int(a1.first) - to_int(a1.second));
  long long d2 = abs(to_int(a2.first) - to_int(a2.second));
  return d1 < d2 || (d1 == d2 && a1 < a2) ? a1 : a2;
}

pair<string, string> solve(string a, string b) {
  string aa = a, bb = b;
  REP(i, aa.size()) if (aa[i] == '?') aa[i] = '0';
  REP(i, bb.size()) if (bb[i] == '?') bb[i] = '0';
  pair<string, string> ans(aa, bb);
  REP(i, a.size()) {
    int smallest_equal = 11;
    REP(a1, 10) REP(b1, 10) {
      if (a[i] != '?' && a[i] - '0' != a1) continue;
      if (b[i] != '?' && b[i] - '0' != b1) continue;
      if (a1 == b1 && smallest_equal > a1) { smallest_equal = a1; continue; }
      string aa = a, bb = b;
      aa[i] = a1 + '0'; bb[i] = b1 + '0';
      FOR(j, i + 1, a.size()) {
        if (aa[j] == '?') aa[j] = (a1 > b1 ? '0' : '9');
        if (bb[j] == '?') bb[j] = (b1 > a1 ? '0' : '9');
      }
      ans = better(ans, make_pair(aa, bb));
    }
    if (smallest_equal == 11) return ans;
    a[i] = b[i] = smallest_equal + '0';
  }
  return better(ans, make_pair(a, b));
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    string a, b;
    cin >> a >> b;
    pair<string, string> ans = solve(a, b);
    printf("Case #%d: %s %s\n", t, ans.first.c_str(), ans.second.c_str());
  }
  return 0;
}
