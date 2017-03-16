
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <complex>
#include <numeric>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,s) for(__typeof((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define ALLOF(s) ((s).begin()), ((s).end())

typedef long long ll;

ll maxE;
ll cureE;
ll vs[10000+10];


ll solve(int i1, int i2, int before, int after) {
  if(i1 >= i2)
    return 0;
  ll maxi = -1;
  int idx = -1;
  for(int i = i1; i < i2; ++i){
    if(vs[i] > maxi){
      maxi = vs[i];
      idx = i;
    }
  }
  ll cur = min(before + (idx - i1) * cureE, maxE);
  ll use = cur + cureE * (i2 - idx) - after;
  if(use < 0) use = 0;
  if(use > cur) use = cur;
  ll res = use * vs[idx];
//   cerr << "solve(" << i1 << "," << i2 << "," << before << "," << after << ")" << endl;
//   cerr << idx << ":" << use << endl;
  res += solve(i1, idx, before, cur);
  res += solve(idx+1, i2, cur - use + cureE, after);
  return res;
}


int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    int n;
    cin >> maxE >> cureE >> n;
    REP(i, n){
      cin >> vs[i];
    }
    
    ll res = solve(0, n, maxE, cureE);
//      cerr << endl;
    cout << "Case #" << (iCase+1) << ": " << res << endl;
  }
  
  return 0;
}
