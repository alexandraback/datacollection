#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)n; ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cout<<*i<<" "; cout<<endl; }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;

int main(){
  int T; cin>>T;
  REP(testcase, T){
    int N;
    cin>>N;
    vector<int> v(N);
    REP(i,N) cin>>v[i];
    int sum = 0;
    REP(i,N) sum += v[i];
    vector<double> ans(N);
    REP(i, N){
      double left = 0;
      double right = 1;
      REP(test, 100){
        double mid = (left + right)/2;
        double point = v[i] + sum * mid;
        double need = 0;
        REP(j, N)if(i != j){
          double diff = max(0.0, point - v[j]);
          need += diff/sum;
        }
        bool judge = (need >= (1 - mid));
        if(judge){
          right = mid;
        }else{
          left = mid;
        }
      }
      ans[i] = right * 100.00;
    }
    printf("Case #%d: ", testcase + 1);
    REP(i,N){
      printf("%.6lf", ans[i]);
      putchar((i!=N-1)?' ':'\n');
    }
  }
  return 0;
}

