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

void solve(){
	// exact implementation appears here

  VI pos;
  VI vt;

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
  
  if(pos.size()>2){
    fprintf(stderr,"size is larger than 2: %lu\n", pos.size());
  }

  if(pos.size()==1){
    puts("0");
    return;
  }

  LL tmin,tmax, pmin,pmax;
  if(vt[0] < vt[1]){
    tmin = vt[0];
    pmin = pos[0];
    tmax = vt[1];
    pmax = pos[1];
  }
  else{
    tmin = vt[1];
    pmin = pos[1];
    tmax = vt[0];
    pmax = pos[0];
  }


  if(tmin == tmax){
    puts("0");
    return;
  }

  LL L = (720 - pmin) * tmin;
  LL R = (360 - pmax) * tmax;

  if(L>R){
    puts("0");
  }
  else{
    puts("1");
  }
    
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
