
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
  int nCases, nCard, maxD, nProduct;
  cin >> nCases; // T = 1
  cout << "Case #1:" << endl;
  cin >> nCases >> nCard >> maxD >> nProduct; // 100 3 5 7
  REP(iCase, nCases){
    vector<int> vs;
    int ds[10] = {};
    REP(i, nProduct){
      int v;
      cin >> v;
      vs.push_back(v);
      for(int cnt = 0; v % 7 == 0; ){
	ds[7] = max(ds[7], ++cnt);
	v /= 7;
      }
      for(int cnt = 0; v % 5 == 0; ){
	ds[5] = max(ds[5], ++cnt);
	v /= 5;
      }
      for(int cnt = 0; v % 3 == 0; ){
	ds[3] = max(ds[3], ++cnt);
	v /= 3;
      }
      for(int cnt = 0; v % 2 == 0; ){
	ds[2] = max(ds[2], ++cnt);
	v /= 2;
      }
    }
    
    int rest = nCard;
    for(int d = maxD; d >= 3; --d){
      REP(i, ds[d]){
	cout << d;
	--rest;
      }
    }
    
    if(rest == 3){
      if(ds[2] == 6){
	cout << "444";
      }else if(ds[2] == 5){
	cout << "442";
      }else if(ds[2] == 4){
	cout << "422";
      }else{
	cout << "222";
      }
    }else if(rest == 2){
      if(ds[2] == 4){
	cout << "44";
      }else if(ds[2] == 3){
	cout << "42";
      }else{
	cout << "22";
      }
    }else if(rest == 1){
      if(ds[2] == 2){
	cout << "4";
      }else{
	cout << "2";
      }
    }
    cout << endl;
    
  }
  
  return 0;
}
