// Author: Xujie Si
// Email: six@gatech.edu
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i,X) for(int i=0;i<(X);++i)
#define PB(X) push_back( (X) )

typedef long long LL;
typedef vector<int> VI;

priority_queue<int> maxQ; // largest on the top
priority_queue<int, VI, greater<int> > minQ; // smallest on the top

const int N = 20;
int d[N];
int f[N];


bool ok(VI & v){
  int sz = v.size();

  for(int i=0; i< v.size(); ++i){
    int prev = (i + sz -1) % sz;
    int nxt = (i+1) % sz;

    int j = v[i];
    if(f[j] != v[prev] && f[j] != v[nxt]) {
      return false;
    }
  }

  return true;
}

bool test(VI& v){
  int m = 1;
  for(int i=1; i<=v.size();++i) m*=i;

  while(m--){

    if(ok(v)){
      return true;
    }
    std::next_permutation(v.begin(), v.end());    
  }

  return false;
}

void solve(){
	// exact implementation appears here
  int n;
  cin >> n;
  for(int i = 0; i < n ;++i){
    cin >> f[i];
    --f[i];
  }

  int m = 1 << n;
  int ans = -1;

  for(int i= 0; i < m; ++i){
    VI v;

    for(int j=0;j < n;++j){
      if( (i>>j) & 1){
	v.PB(j);
      }
    }

    if(test(v)){
      if((int)v.size() > ans){
	ans = v.size();
      }
    }
  }


  cout << ans << endl;
}


int main()
{
  int cs = 0, T;
  scanf("%d",&T);
  while(++cs <= T){
    printf("Case #%d: ", cs);
    solve();
  }
  return 0;
}
