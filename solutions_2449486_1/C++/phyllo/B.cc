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

int N, M;
int field[105][105];

bool solve(){

  rep(i,N){
    rep(j,M){
      bool flg1 = true, flg2 = true;
      rep(a,M){
        if(field[i][a] > field[i][j]) flg1 = false;
      }
      rep(a,N){
        if(field[a][j] > field[i][j]) flg2 = false;
      }
      if(!flg1 && !flg2) return false;
    }
  }
  return true;
}


int main(){
  int T;
  cin >> T;
  
  rep(t,T){
    int tmp;
    cin >> N >> M;
    rep(i,N){
      rep(j,M){
        cin >> field[i][j];
      }
    }
    
    cout << "Case #" << t+1 << ": " << (solve()?"YES":"NO") << endl;
  }
  
  return 0;
}
