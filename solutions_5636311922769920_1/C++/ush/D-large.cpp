
#include <cassert>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
using namespace std;
typedef long long ll;

inline ll mypow(ll x, ll r) {
  ll res = 1;
  REP(i, r)
    res *= x;
  return res;
}

ll getPos(int len0, const vector<int> vs, int power) {
  ll res = 0;
  REP(i, vs.size()) {
    res += mypow(len0, power-i-1) * vs[i];
  }
  return res;
}

int main(void) {
  REP(i, 3) REP(j, 3) REP(k, 3) {
    vector<int> vs;
    vs.push_back(i);
    vs.push_back(j);
    vs.push_back(k);
    cerr << getPos(3, vs, 3) << endl;
  }
  
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    ll len0, power, limit;
    scanf("%lld%lld%lld", &len0, &power, &limit);
    printf("Case #%d:", iCase+1);
    vector<ll> res;
    if(power * limit >= len0) { // POSSIBLE
      REP(i, limit) {
        vector<int> vs;
        REP(j, power) {
          vs.push_back(min(i*power + j, len0-1));
        }
        res.push_back(getPos(len0, vs, power) + 1);
      }
      sort(res.begin(), res.end());
      res.erase(unique(res.begin(), res.end()), res.end());
    }
    if(res.size() == 0u) {
      puts(" IMPOSSIBLE");
    } else {
      REP(i, res.size()) {
        printf(" %lld", res[i]);
      }
      puts("");
    }
  }
  return 0;
}
