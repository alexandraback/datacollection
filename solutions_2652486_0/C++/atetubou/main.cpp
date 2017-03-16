#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
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
#include <cstring>
#include <sstream>
#include <cassert>
#include <ctime>
#include <list>
#include <numeric>
#include <fstream>

using namespace std;
static const double EPS = 1e-8;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PI;
#ifndef M_PI
const double M_PI=acos(-1.0);
#endif
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define FORR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int((a).size()))
#define F first
#define S second
int dx[]={0,-1,0,1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};

int r,n,m,k;
int in[100];

int sel[100];
int ans[100];
int ansmul;

void dfs(int ne){
  if(ne==n){
    map<int,int> app;
    rep(i,1<<n){
      int mul=1;
      rep(j,n)
        if((i>>j)&1) mul*=sel[j];
      ++app[mul];
    }
    ll prsum = 1;
    rep(j,k) prsum *= app[in[j]];
    if(prsum>ansmul){
      ansmul=prsum;
      rep(i,n) ans[i]=sel[i];
    }
    return;
  }
  for(int i=2;i<=m;++i){
    sel[ne]=i;
    dfs(ne+1);
  }
}

void test(){
  rep(i,k) cin >> in[i];
  rep(i,n) ans[i] = 2;
  ansmul = 0;
  dfs(0);
  rep(i,n) cout << ans[i];
  cout << endl;
}

void solve(int ca){
  printf("Case #%d:\n",ca);
  cin >> r >> n >> m >> k;
  rep(i,r) test();
}

int main(){
  int t;
  cin >> t;
  rep(i,t) solve(i+1);
}
