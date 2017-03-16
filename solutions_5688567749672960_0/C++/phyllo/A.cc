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


ll rev(ll N){
  ll ret = 0;
  while(N>0){
    ret = ret*10 + N%10;
    N/=10;
  }
  return ret;
}

ll solve(ll N){
  ll ret = 0;
  while(N>0){
    ll tmp = rev(N);
    if(N%10 != 0 && N > tmp){
      N = tmp;
      ret++;
    }else{
      N--;
      ret++;
    }
  }
  return ret;
}

ll memo[1000005];

void init(){
  queue<pair<ll,ll> > que;
  que.push(make_pair(1,1));
  while(!que.empty()){
    pair<ll,ll> p = que.front(); que.pop();

    if(memo[p.second] == 0 || (memo[p.second] > 0 && memo[p.second] > p.first)){
      memo[p.second] = p.first;
    }else{
      continue;
    }

    ll tmp = rev(p.second);
    if(tmp < 1000005){
      que.push(make_pair(p.first+1, tmp));
    }
    if(p.second < 1000005){
      que.push(make_pair(p.first+1, p.second+1));
    }
  }
}

int main(){
  int T;
  init();
  
  cin >> T;
  rep(t,T){
    ll N;
    cin >> N;

    cout << "Case #" << t+1 << ": " << memo[N] << endl;
  }
  
  return 0;
}
