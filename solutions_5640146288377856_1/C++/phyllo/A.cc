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


int solve(int R, int C, int W){
  deque<int> v;
  v.push_back(C);
  int ret = 0, ret2 = 0;
  while(true){
    deque<int> tmp;
    rep(i,v.size()){
      if(v[i] >= W){
        tmp.push_back(v[i]);
        //cout << v[i] << " ";
      }
    }
    //cout << endl;
    v = tmp;
    
    if(v.size()==1){
      if(v[0] <= 2*W-1){
        ret2 = ret+1;
        if(v[0] == W){
          ret += W;
        }else{
          ret += W+1;
        }
        break;
      }
      else{
        int w = v[0];
        v.pop_front();
        v.push_back(w-W);
        ret++;
      }
    }else{
      int w = v[0];
      if(w == 1){
        v.pop_front();
      }else{
        v.pop_front();
        v.push_back(w-W);
      }
      ret++;
    }
  }

  return ret2*(R-1) + ret;
}



int main(){
  int T;

  cin >> T;
  rep(t,T){
    int R, C, W;
    cin >> R >> C >> W;
    cout << "Case #" << t+1 << ": " << solve(R,C,W) << endl;
  }
  
  return 0;
}
