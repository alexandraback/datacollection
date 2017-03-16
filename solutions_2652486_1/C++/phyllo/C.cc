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

#define ITER 100
unsigned long xor128(){
  static unsigned long x=123456789, y=362436069, z=521288629, w=88675123;
  unsigned long t;
  t=(x^(x<<11));
  x=y; y=z; z=w;
  return w=(w^(w>>19))^(t^(t>>8));
}

vector<ll> divisor(ll n){
  vector<ll> ret;
  for(ll i=1; i*i<=n; i++){
    if(n%i==0){
      ret.push_back(i);
      if(i!=n/i) ret.push_back(n/i);
    }
  }
  //sort(ret.begin(), ret.end());
  return ret;
}

map<ll,int> memo;

bool canMakeIt(ll val, const vector<ll>& card){
  if(memo.count(val)>0) return true;
  return false;
}

bool check(const vector<ll>& card, const vector<ll>& v){

  rep(i,v.size()){
    if(v[i] == 1) continue;
    if(!canMakeIt(v[i], card)) return false;
  }
  return true;
}

void solve(int N, int M, int K, const vector<ll>& v){
  rep(i,ITER){
    vector<ll> rnd;
    rep(j,N){
      int r = xor128()%(M-1)+2;
      rnd.push_back(r);
    }

    memo.clear();
    rep(i,100){
      ll prod = 1LL;
      rep(j,rnd.size()){
        if(xor128()%100000 < 50000){
          prod *= rnd[j];
          memo[prod] = 1;
        }
      }
    }
    
    if(check(rnd, v)){
      rep(j,rnd.size()){
        cout << rnd[j];
      }
      cout << endl;
      return;
    }
  }

  rep(i,N){
    int r = xor128()%(M-1)+2;
    cout << r;
  }
  cout << endl;
}

int main(){
  int T;
  cin >> T;
  
  cout << "Case #1:" << endl;
  int R, N, M, K;
  cin >> R >> N >> M >> K;
  rep(i,R){
    vector<ll> v;
    rep(j,K){
      ll tmp;
      cin >> tmp;
      v.push_back(tmp);
    }
    solve(N, M, K, v);
  }
  
  return 0;
}
