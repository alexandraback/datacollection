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
typedef vector<LL> VI;

priority_queue<int> maxQ; // largest on the top
priority_queue<int, VI, greater<int> > minQ; // smallest on the top

auto cmp1 = [](int& a, int& b) -> bool {return a>b;};
auto dbg = ostream_iterator<int>(cerr, ",");

VI pos;
VI vt;
set<LL> ans;


LL test(LL x){
  LL res = 0;
  for(int i=0;i<pos.size();++i){
    res += ( (x / vt[i]) - 360 + pos[i] ) / 360;
    if( (x + pos[i] * vt[i]) < 360 * vt[i]){
      ++res;
    }
  }

  return res;
}

void solve(){
	// exact implementation appears here

  pos.clear();
  vt.clear();
  ans.clear();

  int n;
  cin>>n;
  FOR(i,n){
    LL d,h,m;
    cin>>d>>h>>m;
    for(int j=0;j<h;++j){
      pos.PB(d);
      vt.PB(m+j);
    }
  }
  
  for(int i=0;i<pos.size();++i){
    for(LL j=1;j<=2;++j){
      LL x = (j*360 - pos[i]) * vt[i];
      ans.insert(x);
      ans.insert(x-1);
      ans.insert(x+1);
    }
  }

  LL res = 1LL<<62;
  for(auto x : ans){
    LL tmp = test(x);
    res = min(res,tmp);
  }

  cout<<res<<endl;
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
