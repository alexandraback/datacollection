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

string number[] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
int p[10] = { 0, 2, 6, 8, 4, 5, 7, 1, 9, 3};

map< pair<map<char, int>, int>, string> dp;
string solve(map<char, int> have, int num) {

  if (num == 10) {
    REP(i, 26) if (have[i + 'A']) return "NO";
    return "";
  }

  pair< map<char,int>, int > state = make_pair(have, num);
  if (dp.count(state)) return dp[state];

  REP(i, 26) if (have[i + 'A']) {
    bool ok = false;
    FOR(j, num, 9) REP(k, number[p[j]].size()) if (number[p[j]][k] == i + 'A') {
      ok = true;
      break;
    }
    if (!ok) return "NO";
  }

  string ans = "";
  for (int i = 0;; ++i) {
    string tmp = solve(have, num + 1);
    if (tmp != "NO") return dp[state] = ans + tmp;
    ans.push_back('0' + p[num]);
    REP(i, number[p[num]].size()) {
      if (!have[number[p[num]][i]]) return dp[state] = "NO";
      --have[number[p[num]][i]];
    }
  }

  return dp[state] = "NO";
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  FOR(t, 1, T) {
    string s;
    cin >> s;
    /*
    s = "";
    while (s.size() < 2000) {
      int x = rand() % 10;
      REP(i, number[x].size()) s.push_back(number[x][i]);
    }
    */
    map<char,int> m;
    REP(i, s.size()) m[s[i]]++;
    string ans = solve(m, 0);
    sort(ans.begin(), ans.end());
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
