#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

const int INF = 1000000;
vector<string> vs;

void dfs(string &s, int p) {
  if (p == s.length()) {
    vs.push_back(s);
  }
  else if (s[p] == '?') {
    REP (i, 10) {
      s[p] = '0' + i;
      dfs(s, p+1);
      s[p] = '?';
    }
  } else {
    dfs(s, p+1);
  }
}

vector<string> doit(string s) {
  vs.clear();
  dfs(s, 0);
  return vs;
}

void solve() {
  string x, y;
  cin >> x >> y;

  vector<string> xs = doit(x);
  vector<string> ys = doit(y);
  
  int diff = INF;
  string rx, ry;

  REP (i, xs.size()) REP (j, ys.size()) {
    if (diff == INF) {
      rx = xs[i];
      ry = ys[j];
      diff = abs(stoi(rx) - stoi(ry));
    } else {
      int d = abs(stoi(xs[i]) - stoi(ys[j]));
      if (d < diff) {
        rx = xs[i];
        ry = ys[j];
        diff = d;
      } else if (d == diff) {
        if (stoi(xs[i]) < stoi(rx)) {
          rx = xs[i];
          ry = ys[j];
          diff = d;
        }
        else if (stoi(xs[i]) == stoi(rx) && stoi(ys[j]) < stoi(ry)) {
          rx = xs[i];
          ry = ys[j];
          diff = d;
        }
      }
    }
  }
  cout << rx << " " << ry << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
