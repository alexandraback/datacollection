#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <stdio.h>
#include <queue>
#include <set>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define rep(i,n) for (int i=0; i < (n); i++)


ll solveNaive() {
  int e, r, n;
  cin >> e >> r >> n;
  VI v(n);
  rep(i,n) cin >> v[i];

  vector<int> perm(n, 0);
  for (int i = 0; i < n; i++) perm[i] = i;
  do {
    cout << "[";
    for (int i = 0; i < n; i++) cout << " " << perm[i];
    cout << " ]" << endl;
  } while(next_permutation(perm.begin(), perm.end()));
return 30;
}

ll solve() {
  ll e, r;
  int n;
  cin >> e >> r >> n;
  VI v(n);
  vector<PII> vp(n);
  rep(i,n) {
    cin >> v[i];
    vp[i] = PII(v[i], i);
  }
  sort(vp.begin(), vp.end(), greater<PII>());

  set<int> energyUsed;
  energyUsed.insert(-1000000000);  // dummy
  energyUsed.insert( 1000000000);  // dummy

  ll ans = 0;
  rep(i,n) {
    int ind = vp[i].second;
    set<int>::iterator intId = energyUsed.lower_bound(ind);
    ll ceilInd = *intId;
    intId--;
    ll floorInd = *intId;
    ll curEnergy = min(e, (ind - floorInd) * r);
    ll regainToNext = min(e, (ceilInd - ind) * r);
    // cout << ind << " " << floorInd << " " << ceilInd << " " << curEnergy << " " << regainToNext << endl;
    ll energyOkToUse = 0;
    if (curEnergy + regainToNext >= e) energyOkToUse = curEnergy + regainToNext - e;
    // energyOkToUse -= e - regainToNext;
    // energyOkToUse = max(0LL, energyOkToUse);
    // cout << energyOkToUse << endl;
    ans += vp[i].first * energyOkToUse;
    energyUsed.insert(ind);
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << "Case #" << i+1 << ": " << solve() << endl;
  return 0;
}