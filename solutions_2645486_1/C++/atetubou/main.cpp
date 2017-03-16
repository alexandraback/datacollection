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

ll E,R,N;
ll v[100000];
ll lest[100000];

void solve(int ca){

  cin >> E >> R >> N;
  rep(i, N) cin >> v[i];
  set<pair<ll,ll> > hei;
  rep(i, N){
    lest[i]=0;
    while(!hei.empty() && hei.begin()->F<=v[i]){
      pair<ll,ll> el=*hei.begin();
      hei.erase(el);
      lest[el.S]=max(0LL,E-(i-el.S)*R);
    }
    hei.insert(mp(v[i],i));
  }
  ll ans = 0;
  ll ce=E;
  rep(i,N){
    ll use=max(0LL,ce-lest[i]);
    ans += use * v[i];
    ce=min(ce-use+R,E);
  }
  printf("Case #%d: ",ca);
  cout << ans << endl;
}

int main(){
  int t;
  cin >> t;
  rep(i,t) solve(i+1);
}
