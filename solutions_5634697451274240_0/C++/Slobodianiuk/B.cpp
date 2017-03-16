#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

long long solve(const string &s) {
  int ret = 0;
  for (int i = 1; i < s.size(); ++i) {
    ret += (s[i] != s[i-1]);
  }
  return ret;
}

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  freopen("B-small-attempt1.in", "rt", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int line_num;
  cin >> line_num;
  for (int line = 0; line < line_num; ++line) {
    string s;
    cin >> s;
    s += "+";
    int ans = solve(s);
    printf("Case #%d: %d\n", line+1, ans);
  }

  return 0;
}
