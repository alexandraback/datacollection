#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include<cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include<bitset>

#define REP(i,b,n) for(int i=b;i<(int)n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define FOR(it,o)  for(__typeof((o).begin()) it=(o).begin(); it!=(o).end(); ++it)
#define dbg(x) cerr << #x << " = " << (x) << endl


typedef long long ll;

using namespace std;


const int M = 100000*22;
set<int> S[M];
   

int main(){
  int T;
  cin >> T;
  rep(tc, T){
    rep(i, M)S[i].clear();
    cout <<"Case #" << tc+1<<": "<<endl;
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i, n){
      cin >> v[i];
    }
    S[0].insert(0);
    rep(i, M){
      FOR(it, S[i]){
	rep(j, n){
	  if(((*it) & (1<<j))!=0 )continue;
	  S[i+v[j]].insert((*it) | (1<<j));
	}
      }
    }
    bool flag = true;
    REP(i, 1, M){
      if(S[i].size() > 2){
	int cnt = 0;
	flag = false;
	FOR(it, S[i]){
	  bool first = true;
	  rep(j, n){
	    if(((1<<j) & (*it))!= 0){
	      if(!first)cout<<' ';
	      first = false;
	      cout << v[j];
	    }
	  }
	  cout << endl;
	  cnt++;
	  if(cnt == 2)break;
	}
	break;
      }
    }
    if(flag)cout << "Impossible" << endl;
  }
  
  
  return 0;
}
