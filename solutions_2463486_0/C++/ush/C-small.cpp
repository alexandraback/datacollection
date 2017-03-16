
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

bool isParin(ll v) {
  vector<int> ds;
  while(v){
    ds.push_back(v % 10);
    v /= 10;
  }
  int n = ds.size();
  REP(i, n){
    if(ds[i] != ds[n-i-1])
      return false;
  }
  return true;
}

ll calc(ll ed) {
  ll res = 0;
  for(ll i = 1; i*i < ed; ++i){
    if(isParin(i) && isParin(i*i)){
      ++res;
    }
  }
  return res;
}

int main(void) {
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
