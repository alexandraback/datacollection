
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

int ds[200];
bool isParin(ll v) {
  int n = 0;
  while(v){
    ds[n++] = v % 10;
    v /= 10;
  }
  
  REP(i, n){
    if(ds[i] != ds[n-i-1])
      return false;
  }
  return true;
}

vector<ll> ps;

ll calc(ll ed) {
  REP(i, ps.size()){
    if(ps[i] >= ed)
      return i;
  }
  assert(false);
  return -1;
}


int main(void) {
  for(ll i = 1; i <= 20000000; ++i){
    if(isParin(i) && isParin(i*i)){
      ps.push_back(i*i);
    }
  }
  
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    ll a, b;
    cin >> a >> b;
    ll res = 0;
    res = calc(b+1) - calc(a);
    cout << "Case #" << (iCase+1) << ": " << res << endl;
  }
  return 0;
}
