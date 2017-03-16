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

ll gcd(ll a, ll b){return (b==0?a:gcd(b,a%b));}

vector<ll> factorize(ll x){
  vector<ll> ret;
  int d, q;
  while(x>=4 && x%2==0){ret.push_back(2); x/=2;}
  d = 3; q = x/d;
  while(q>=d){
    if(x%d==0){ ret.push_back(d); x=q; }else{ d+=2; }
    q=x/d;
  }
  ret.push_back(x);
  return ret;
}

int solve(ll P, ll Q){
  if(P==1 && Q==2) return 1;
  int ret = 0;
  vector<ll> res = factorize(Q);
  rep(i,res.size()){
    //cout << res[i] << endl;
    if(res[i] != 2) return -1;
  }
  
  ll prod = Q;
  rep(i,res.size()){
    ret++;
    if(P==1 && prod==2) break;
    if(P/(double)prod > 0.5) break;
    prod /= 2LL;
  }
  return ret;
}

int main(){
  int T;
  cin >> T;

  for(int t=0; t<T; t++){
    ll P, Q;
    char c;
    cin >> P >> c >> Q;
    ll g = gcd(P, Q);
    P/=g;
    Q/=g;
    int ret = solve(P, Q);
    if(ret > 0){
      cout << "Case #" << t+1 << ": " << ret << endl;
    }else{
      cout << "Case #" << t+1 << ": impossible" << endl;
    }
  }
  
  return 0;
}
