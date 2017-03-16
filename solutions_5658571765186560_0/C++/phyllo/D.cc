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

string solve(int X, int R, int C){
  if(R > C) swap(R, C);

  if(X==1){
    ;
  }
  if(X==2){
    if((R*C)%X!=0) return "RICHARD";
  }
  if(X==3){
    if((R==2 && C==3) ||
       (R==3 && C==3) ||
       (R==3 && C==4)){
      ;
    }else{
      return "RICHARD";
    }
  }
  if(X==4){
    if((R==3 && C==4) ||
       (R==4 && C==4)){
      ;
    }else{
      return "RICHARD";
    }
  }
  
  return "GABRIEL";
}

int main(){
  int T;

  cin >> T;
  rep(t,T){
    int X, R, C;
    cin >> X >> R >> C;
    cout << "Case #" << t+1 << ": " << solve(X, R, C) << endl;
  }
  
  return 0;
}
