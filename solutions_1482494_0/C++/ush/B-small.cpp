
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

struct K{
  int a;
  int b;
  int st;
};

bool operator<(const struct K& a, const struct K& b) {
  if(a.b != b.b)
    return a.b < b.b;
  return a.a > b.a;
}

int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    int n;
    cin >> n;
    vector<K> vs;
    REP(i, n){
      K v;
      cin >> v.a >> v.b;
      v.st = 3;
      vs.push_back(v);
    }
    sort(vs.begin(), vs.end());
    
    int res = 0;
    int curStar = 0;
    while(curStar < 2*n){
      int diff = 0;
      REP(i, n){ // all level2
	if(vs[i].st && vs[i].b <= curStar){
	  ++res;
	  if(vs[i].st & 2){
	    diff += 1;
	    curStar += 1;
	  }
	  if(vs[i].st & 1){
	    diff += 1;
	    curStar += 1;
	  }
	  vs[i].st = 0;
	}
      }
      
      if(diff == 0){
	for(int i = n-1; i >= 0; --i){
	  if((vs[i].st & 1) && vs[i].a <= curStar){
	    ++res;
	    diff += 1;
	    curStar += 1;
	    vs[i].st = 2;
	    break;
	  }
	}
      }
      
      if(diff == 0)
	break;
    }
    
    if(curStar < 2*n){
      cout << "Case #" << iCase+1 << ": Too Bad" << endl;
    }else{
      cout << "Case #" << iCase+1 << ": " << res << endl;
    }
  }
  
  return 0;
}
