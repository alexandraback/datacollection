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
    int e, r, n; cin >> e >> r >> n;
    vector<int> vv(n);
    for(auto &v: vv) cin >> v;

    priority_queue<pair<int, int>> q;
    REP(i, n) q.emplace(vv[i], i);

    map<int, int> gg;

    ll gain = 0;
    while(!q.empty()) {
      int v = q.top().first;
      int i = q.top().second;
      q.pop();

      if(gg.empty()) {
        // first
        gg[i] = e;
        gain += v * e;
      } else {
        auto next = gg.upper_bound(i);

        auto nexti = next->first;
        auto nexte = next->second;

        int mymax = e;
        if(next != gg.begin()) {
          auto prev = next; --prev;
          mymax = min(mymax, ((i - prev->first) * r));
        }
        assert(mymax <= e);
        if(next != gg.end()) {
          mymax -= max(0, nexte - (nexti - i) * r);
        }
        assert(mymax <= e);

        gg[i] = mymax;
        gain += v * mymax;
      }
    }

    cout << "Case #" << t << ": ";
    cout << gain << endl;
  }
}
