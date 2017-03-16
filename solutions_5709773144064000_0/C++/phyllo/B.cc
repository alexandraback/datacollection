#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;

double solve(double C, double F, double X){
  double cps = 2.0;
  double ret = X / cps;

  if(C > X) return ret;
  
  double now = 0.0;
  while(true){
    now += C / cps;
    cps += F;

    if(ret < now) break;
    ret = min(ret, now + X /cps);
  }
  return ret;
}

int main(){
  int T;
  cin >> T;

  for(int t=0; t<T; t++){
    double C, F, X;
    cin >> C >> F >> X;
    printf("Case #%d: %.8lf\n", t+1, solve(C, F, X));
  }
  return 0;
}
