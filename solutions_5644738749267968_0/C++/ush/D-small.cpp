
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

double as[1010];
double bs[1010];

int calcWar(int n) {
  int res = 0;
  vector<bool> used(n, false);
  REP(i, n){
    int mini = -1;
    REP(j, n){
      if(!used[j]){
	mini = j;
	break;
      }
    }
    assert(mini >= 0);
    int opti = -1;
    REP(j, n){
      if(!used[j] && as[i] < bs[j]){
	opti = j;
	break;
      }
    }
    if(opti < 0){
      used[mini] = true;
      ++res;
    }else{
      used[opti] = true;
    }
  }
  return res;
}

int calcDWar(int n) {
  int left = 0;
  int right = n-1;
  REP(i, n){
    if(as[i] < bs[left]){
      // Told = bs[right]-EPS => as[i] VS bs[right] => lose
      right--;
    }else{
      // Told = bs[right]+EPS => as[i] VS bs[left] => win
      left++;
    }
  }
  return left;
}

int main(void) {
  int nCases;
  cin >> nCases;
  REP(iCase, nCases) {
    int n;
    cin >> n;
    REP(i, n)
      cin >> as[i];
    REP(i, n)
      cin >> bs[i];
    sort(as, as + n);
    sort(bs, bs + n);
    
    printf("Case #%d: %d %d\n", iCase+1, calcDWar(n), calcWar(n));
  }
  
  return 0;
}
