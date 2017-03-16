
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


int ds[10];
int ms[10];

int main(void) {
  int nCases, nCard, maxD, nProduct;
  scanf("%d", &nCases); // T = 1
  cout << "Case #1:" << endl;
  scanf("%d%d%d%d", &nCases, &nCard, &maxD, &nProduct);
  REP(iCase, nCases){
    memset(ds, 0, sizeof ds);
    memset(ms, 0, sizeof ms);
    REP(i, nProduct){
      int v;
      scanf("%d", &v);
      for(int cnt = 0; v % 7 == 0; ){
	ms[7] = max(ms[7], ++cnt);
	ds[7]++;
	v /= 7;
      }
      for(int cnt = 0; v % 5 == 0; ){
	ms[5] = max(ms[5], ++cnt);
	ds[5]++;
	v /= 5;
      }
      for(int cnt = 0; v % 3 == 0; ){
	ms[3] = max(ms[3], ++cnt);
	ds[3]++;
	v /= 3;
      }
      for(int cnt = 0; v % 2 == 0; ){
	ms[2] = max(ms[2], ++cnt);
	ds[2]++;
	v /= 2;
      }
//       cerr << iCase << ":" << ds[7] << " " << ds[5] << " " << ds[3] << " " << ds[2] << endl;
    }
    
    int rest = nCard;
    ds[2] = max(ms[2], (ds[2] * 2 + (nProduct-1)) / nProduct);
    ds[3] = max(ms[3], (ds[3] * 2 + (nProduct-1)) / nProduct);
    ds[5] = max(ms[5], (ds[5] * 2 + (nProduct-1)) / nProduct);
    ds[7] = max(ms[7], (ds[7] * 2 + (nProduct-1)) / nProduct);
    while(rest > 0){
      if(maxD >= 7 && ds[7] > 0){
	cout << 7;
	ds[7]--;
	rest--;
      }else if(maxD >= 5 && ds[5] > 0){
	cout << 5;
	ds[5]--;
	rest--;
      }else{
	if(ds[2] + ds[3] < rest){ // spread
	  REP(i, ds[3]){
	    cout << 3;
	    --rest;
	  }
	  REP(i, rest)
	    cout << 2;
	  break;
	}else if(maxD >= 8 && ds[2] >= 3 && ds[2] / 2 > rest){
	  cout << 8;
	  ds[2] -= 3;
	  rest--;
	}else if(maxD >= 6 && ds[2] > 0 && ds[3] > 0){
	  cout << 6;
	  ds[2]--;
	  ds[3]--;
	  rest--;
	}else if(ds[2] > rest){
	  cout << 4;
	  ds[2] -= 2;
	  rest--;
	}else if(ds[3] > 0){
	  cout << 3;
	  rest--;
	  ds[3]--;
	}else{
	  cout << 2;
	  rest--;
	  ds[2]--;
	}
      }
    }
    cout << endl;
    
  }
  
  return 0;
}
