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

double solve(int A, int B, vector<double> p){
  double ret = 1+B+1; //Enter + retype + Enter

  for(int i=A; i>=0; i--){
    double all_correct = 1.0;
    rep(j,i) all_correct *= p[j];
    
    double prob = all_correct * (B-A+2*(A-i)+1) + (1.0-all_correct) * (B-A+2*(A-i)+1+B+1);
    ret = min(ret, prob);
  }
  
  return ret;
}

int main(){
  int T;
  int A, B;
  cin >> T;
  
  rep(t,T){
    vector<double> p;
    double tmp;
    cin >> A >> B;
    rep(i,A){
      cin >> tmp;
      p.push_back(tmp);
    }
    printf("Case #%d: %.6lf\n", t+1, solve(A, B, p));
  }
  
  return 0;
}
