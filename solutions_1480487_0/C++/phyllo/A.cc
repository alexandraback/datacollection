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


vector<double> solve(int N, vector<int> v){
  vector<double> ret;
  int sum = 0, maxv = -1;
  rep(i,v.size()){
    sum += v[i];
    maxv = max(maxv, v[i]);
  }

  if(2*sum >= N*maxv){
    double res = (2*sum - N*maxv)/(double)N;
    rep(i,v.size()){
      ret.push_back( (res+(maxv-v[i]))/(double)sum*100.0);
    }
  }else{
    double res = 0;
    int summ = 0;
    while(true){
      int M = 0;
      summ = 0;
      int maxvv = -1;
      rep(i,v.size()){
        if(v[i] < maxv){
          maxvv = max(maxvv, v[i]);
          summ += v[i];
          M++;
        }
      }
      if(sum+summ >= M*maxvv){
        maxv = maxvv;
        res = (sum+summ - M*maxvv)/(double)M;
        break;
      }else{
        maxv = maxvv;
      }
    }
    rep(i,v.size()){
      if(v[i] > maxv) ret.push_back(0);
      else ret.push_back( (res+(maxv-v[i]))/(double)sum*100.0);
    }
  }
  return ret;
}


int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    vector<int> v;
    int N, tmp;
    cin >> N;
    rep(i,N){
      cin >> tmp;
      v.push_back(tmp);
    }
    printf("Case #%d: ", t+1);
    vector<double> ret = solve(N, v);
    rep(i,ret.size()){
      printf("%.6lf", ret[i]);
      if(i!=ret.size()-1) printf(" ");
    }
    printf("\n");
  }
  
  return 0;
}
