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

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,k,n) for(int i = (k); i < (int)(n); ++i)
#define FOREQ(i,k,n) for(int i = (k); i <= (int)(n); ++i)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); ++i)
#define SZ(v) (int)((v).size())
#define MEMSET(v,h) memset((v),(h),sizeof(v))

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; ++t) {
    ll r, v; cin >> r >> v;

    __int128 hi = 1LL<<31, lo = 0;
    while((hi - lo) > 1) {
      __int128 y = (hi + lo) / 2;
      __int128 g = 2 * y * y + (2 * r - 1) * y;
      if(g > v) hi = y; else lo = y;
    }

    cout << "Case #" << t << ": ";
    cout << static_cast<ll>(lo) << endl;
  }
}
