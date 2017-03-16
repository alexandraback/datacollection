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

int solve(int N, int S, int p, vector<int> ti){
  int ret = 0;
  sort(ALLOF(ti));
  reverse(ALLOF(ti));

  rep(i,N){
    if(ti[i] >= p+(p-1)+(p-1)) ret++;
    else if(S > 0 && ti[i] >= p+max(0,(p-2))+max(0,(p-2))){
      ret++;
      S--;
    }
  }
  return ret;
}

int main(){
  int T;
  int N, S, p;
  vector<int> ti;
  cin >> T;  
  rep(t,T){
    ti.clear();
    cin >> N >> S >> p;
    rep(i,N){
      int tmp;
      cin >> tmp;
      ti.push_back(tmp);
    }
    cout << "Case #" << t+1 << ": " << solve(N, S, p, ti) << endl;
  }
  
  return 0;
}
