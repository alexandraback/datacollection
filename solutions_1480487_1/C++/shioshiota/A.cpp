#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cerr << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;


bool ok(double data[], int n, double p, int now, double sum){
  double border = p * sum + data[now];
  double remain = 0;
  rep(i, n){
    if(i == now)continue;
    if(border < data[i])continue;
    remain += border - data[i];
  }
  return remain >= sum * (1.0-p);
}

double solve(int now, int sum, double data[], int n){
  double l = 0, r = 1;
  while(abs(r - l) > 0.0000000001){
    
    double mid = (r + l)/2.0;
    if(ok(data, n, mid, now, sum)){
      r = mid;
    }
    else l = mid;
  }
  return (l+r)/2.0;
}

int main(){
  int T;
  cin >> T;
  rep(tc, T){
    printf("Case #%d:",tc+1);
    int n;
    cin >> n;
    double data[n];
    double sum = 0;
    rep(i, n){
      cin >> data[i];
      sum += data[i];
    }
    rep(i, n){
      printf(" %.9lf", 100 * solve(i, sum, data, n));
    }
    puts("");
  }
  return 0;
}
