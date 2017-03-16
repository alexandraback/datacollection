
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

ll getPos(int len0, int idx, int power) {
  if(power == 1)
    return idx;
  return mypow(len0, power-1) * idx + getPos(len0, idx, power-1);
}

int main(void) {
  int nCase;
  scanf("%d", &nCase);
  REP(iCase, nCase){
    ll len0, power, limit;
    scanf("%lld%lld%lld", &len0, &power, &limit);

    printf("Case #%d:", iCase+1);
    REP(i, len0){
      printf(" %lld", getPos(len0, i, power) + 1);
    }
    puts("");
  }
  return 0;
}
