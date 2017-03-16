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

ll solve(const string& v){
  ll ret = 0;

  ll sum = v[0]-'0';
  REP(Si,1,v.size()){
    ll num = v[Si] - '0';
    
    if(num == 0) continue;

    if(sum >= Si){
      sum += num;
    }else{
      ret += (ll)Si-sum;
      sum = Si + num;
    }
  }
  
  return ret;
}

int main(){
  int T;
  int S;
  string aud;

  cin >> T;
  rep(t,T){
    cin >> S >> aud;
    cout << "Case #" << t+1 << ": " << solve(aud) << endl;
  }
  
  return 0;
}
