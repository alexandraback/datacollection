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

bool check(const string &s) {
  for (auto &c : s)
    if (c == '-')
      return false;
  return true;
}

void doit(string &s) {
  int j;
  if (s[0] == '+') {
    for (j = 0; s[j] == '+'; ++j) ;
  }
  else {
    for (j = s.length()-1; s[j] == '+'; j--) ;
    ++j;
  }
  reverse(s.begin(), s.begin()+j);
  for (int i = 0; i < j; i++)
    s[i] = s[i] == '+' ? '-' : '+';
}

void solve() {
  string s;
  cin >> s;

  int ret = 0;
  while (true) {
    if (check(s))
      break;
    doit(s);
    ++ret;
  }
  cout << ret << endl;
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
