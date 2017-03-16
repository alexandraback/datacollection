
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

typedef long long integer;

int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    REP(i, n){
      int v;
      cin >> v;
      if((v+2)/3 >= k){
	++res;
      }else if(v && m > 0 && (v+2)/3 >= k-1){
	++res;
	--m;
      }
    }
    
    cout << "Case #" << (iCase+1) << ": " << res << endl;
  }
  
  return 0;
}
