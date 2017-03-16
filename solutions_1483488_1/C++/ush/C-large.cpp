
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

bool memo[2000010];


int calc10(int v) {
  int res = 1;
  while(v /= 10)
    res *= 10;
  return res;
}

inline int rotate(int v, int d) {
  return v / 10 + v % 10 * d;
}

int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    int a, b;
    cin >> a >> b;

    ll res = 0;
    memset(memo, 0, sizeof memo);
    for(int i = a; i <= b; ++i){
      if(memo[i] == false){
	memo[i] = true;
	int cur = i;
	int d = calc10(cur);
	int cnt = 1;
	int next;
	while((next = rotate(cur, d)) != i){
	  if(a <= next && next <= b && calc10(next) == d){
	    ++cnt;
	    memo[next] = true;
	  }
	  cur = next;
	}
// 	cerr << ">" << i << " " << cnt << endl;
	res += cnt * (cnt-1) / 2;
      }
    }

    cout << "Case #" << (iCase+1) << ": " << res << endl;
  }
  
  return 0;
}
