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

string dig[] = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE"
};

int cnt[256];

int numof(const string &s, char c) {
  int r = 0;
  REP (i, s.length())
    if (s[i] == c)
      ++r;
  return r;
}

void solve() {
  string s;
  cin >> s;

  memset(cnt, 0, sizeof(cnt));
  REP (i, s.length())
    cnt[s[i]]++;

  vector<int> ret;
  int xs[] = {0,6,8,2,3,4,1,7,5,9};
  REP (i, 10) {
    int t = 1000000;
    int x = xs[i];
    REP (j, dig[x].size()) {
      t = min(t, cnt[dig[x][j]] / numof(dig[x], dig[x][j]));
    }
    REP (j, dig[x].size())
      cnt[dig[x][j]] -= t;
    REP (j, t)
      ret.push_back(x);
  }

  REP (i, 256) {
    if (cnt[i]) {
      cerr << s << endl;
      exit(1);
    }
  }

  sort(ret.begin(), ret.end());
  REP (i, ret.size())
    cout << ret[i];
  cout << endl;
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
