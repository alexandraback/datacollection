#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cassert>
using namespace std;
typedef long long ll;

#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define FOREQ(i,k,n) for (int i=(k); i<=(int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))


void solve() {
  int A, B; cin >> A >> B;

  int res = 0;
  FOREQ(n, A, B) {
    set<int> st;
    stringstream ss; ss << n;
    string s = ss.str();
    // rotrot
    REP(i, SZ(s)) {
      string t = s.substr(i) + s.substr(0, i);
      if (t[0] == '0') continue; // invalid
      int m = atoi(t.c_str());
      if (A <= m && m <= B && n < m) {
        st.insert(m);
      }
    }

    res += SZ(st);
  }

  cout<<res<<endl;
}

int main() {
  int test_case; cin >> test_case;
  REP(t, test_case) {
    printf("Case #%d: ", t+1);
    solve();
  }
}
