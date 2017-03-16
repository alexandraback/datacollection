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

int to_int(string x) {
  int n = 0;
  REP(i, x.size()) n = 10 * n + x[i] - '0';
  return n;
}

pair<string, string> solve(string a, string b) {
  REP(i, a.size()) {
    if (a[i] == '?') {
      a[i] = '0';
      pair<string, string> ans = solve(a, b);
      int diff = abs(to_int(ans.first) - to_int(ans.second));
      FOR(j, 1, 9) {
        a[i] = '0' + j;
        pair<string, string> tmp = solve(a, b);
        int ndiff = abs(to_int(tmp.first) - to_int(tmp.second));
        if (diff > ndiff || (diff == ndiff && tmp < ans)) {
          ans = tmp;
          diff = ndiff;
        }
      }
      return ans;
    }
  }
  REP(i, b.size()) {
    if (b[i] == '?') {
      b[i] = '0';
      pair<string, string> ans = solve(a, b);
      int diff = abs(to_int(ans.first) - to_int(ans.second));
      FOR(j, 1, 9) {
        b[i] = '0' + j;
        pair<string, string> tmp = solve(a, b);
        int ndiff = abs(to_int(tmp.first) - to_int(tmp.second));
        if (diff > ndiff || (diff == ndiff && tmp < ans)) {
          ans = tmp;
          diff = ndiff;
        }
      }
      return ans;
    }
  }

  return make_pair(a, b);
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
