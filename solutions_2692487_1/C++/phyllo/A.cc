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

struct ST {
  int i;
  ll now;
  int cnt;
};


int solve(ll A, vector<ll> v){
  sort(ALLOF(v));

  queue<ST> que;
  ST st;
  st.i = -1;
  st.now = A;
  st.cnt = 0;
  que.push(st);

  int ret = 1000000;
  while(!que.empty()){
    st = que.front(); que.pop();
    if(st.i+1 == v.size()){
      ret = min(ret, st.cnt);
      continue;
    }

    if(st.now > v[st.i+1]){
      que.push((ST){st.i+1, st.now+v[st.i+1], st.cnt});
    }else{
      //del
      que.push((ST){st.i+1, st.now, st.cnt+1});
      
      //add
      ll now = st.now;
      if(now == 1) continue;
      int add = 0;
      while(now <= v[st.i+1]){
        add++;
        now += now-1;
      }
      que.push((ST){st.i+1, now+v[st.i+1], st.cnt+add});
    }
  }

  return ret;
}


int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    ll A, N;
    cin >> A >> N;
    ll tmp;
    vector<ll> v;
    rep(i,N){
      cin >> tmp;
      v.push_back(tmp);
    }
    
    cout << "Case #" << t+1 << ": " << solve(A, v) << endl;
  }
  
  return 0;
}
