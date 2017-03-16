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

int n;
string a[20], b[20];

void solve() {
  cin >> n;
  REP (i, n) cin >> a[i] >> b[i];
  
  int ret = 0;
  REP (mask, 1<<n) {
    set<string> head, tail, all;
    REP (i, n) if (!(mask & 1<<i)) {
      head.insert(a[i]);
      tail.insert(b[i]);
      all.insert(a[i]+ " " + b[i]);
    }

    bool ck = true;
    REP (i, n) if (mask & 1<<i) {
      if (!head.count(a[i])) ck = false;
      if (!tail.count(b[i])) ck = false;
      if (all.count(a[i] + " " + b[i])) ck = false;
      all.insert(a[i]+ " " + b[i]);
    }
    if (ck)
      ret = max(ret, __builtin_popcountll(mask));
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
