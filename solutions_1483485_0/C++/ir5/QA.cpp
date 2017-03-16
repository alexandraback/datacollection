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
  const string A = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jvzq";
  const string B = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give upqz";
  map<char, char> mp;
  REP(i, SZ(A)) mp[A[i]] = B[i];

  string line;
  getline(cin, line);
  REP(i, SZ(line)) cout << mp[line[i]];
  cout<<endl;
}

int main() {
  int test_case; cin >> test_case;
  string nop;
  getline(cin, nop);
  REP(t, test_case) {
    printf("Case #%d: ", t+1);
    solve();
  }
}

