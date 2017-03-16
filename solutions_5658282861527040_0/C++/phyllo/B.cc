#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <stack>
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

ll solve(ll A, ll B, ll K){
  ll ret = 0;
  for(ll a=0; a<A; a++){
    for(ll b=0; b<B; b++){
      if((a&b)<K) ret++;
    }
  }
  return ret;
}


int main(){
  int T;
  
  cin >> T;

  for(int t=0; t<T; t++){
    ll A, B, K;
    cin >> A >> B >> K;
    cout << "Case #" << t+1 << ": " << solve(A, B, K) << endl;
  }
  return 0;
}
