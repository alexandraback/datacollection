
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



int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    ll r, t;
    cin >> r >> t;
    ll res = 0;
    for(;;){
      ll use = 2*r+1;
      if(t >= use){
	r += 2;
	t -= use;
	res++;
      }else{
	break;
      }
    }
    
    cout << "Case #" << (iCase+1) << ": " << res << endl;
  }
  
  return 0;
}
