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

bool stars[2][2005];

struct ST {
  int a, b;
};

int solve(int N, vector<ST> st){
  int ret = 0;
  int now = 0;
  rep(i,2) rep(j,2005) stars[i][j] = false;
  
  while(true){
    bool check = false;
    int maxv = -1, idx = -1;
    rep(i,N) if(!stars[1][i]) if(now >= st[i].b && maxv < 2 + (stars[0][i]?1:0)){
      maxv = 2 + (stars[0][i]?1:0);
      idx = i;
    }
    if(idx>=0){
      now += maxv;
      stars[1][idx] = true;
      check = true;
    }else{
      maxv = -1;
      idx = -1;
      rep(i,N) if(!stars[0][i]) if(now >= st[i].a && (maxv < 1 ||(maxv==1 && !stars[1][i]))){
        maxv = 1;
        idx = i;
      }
      if(idx>=0){
        now += maxv;
        stars[0][idx] = true;
      }else{
        return -1;
      }
    }
    ret++;
    bool flg = true;
    rep(i,N) if(!stars[1][i]){
      flg = false;
      break;
    }
    if(flg) break;
  }
  
  return ret;
}

int main(){
  int T;
  int N;
  cin >> T;
  
  rep(t,T){
    vector<ST> st;
    cin >> N;
    rep(i,N){
      int a, b;
      cin >> a >> b;
      st.push_back((ST){a,b});
    }
    
    int ret = solve(N, st);
    if(ret < 0) cout << "Case #" << t+1 << ": " << "Too Bad" << endl;
    else cout << "Case #" << t+1 << ": " << ret << endl;
  }
  
  return 0;
}
