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

vector<ll> bef;
ll gyaku1(ll a){
  ll cnt=1;
  ll b=0,c=a;
  while(c){
    b=b*10+c%10;
    c/=10;
    cnt*=10;
  }
  return a*cnt+b;
}

ll gyaku2(ll a){
  ll cnt=1;
  ll b=0,c=a;
  while(c){
    b=b*10+c%10;
    c/=10;
    cnt*=10;
  }
  return a/10*cnt+b;
}

bool ispar(ll a){
  ll b=a;
  ll c=0;
  while(b){
    c=c*10+b%10;
    b/=10;
  }
  return a==c;
}

void solve(int ca){
  ll a,b;
  cin >> a >> b;
  printf("Case #%d: %d\n",ca,upper_bound(ALL(bef),b)-lower_bound(ALL(bef),a));
}

main(){
  for(ll i=1;i<=100000;++i){
    ll g1=gyaku1(i);
    ll g2=gyaku2(i);
    if(g2>10000000) break;
    if(ispar(g2*g2)){
      //cout << g2 << ' ' << g2*g2 << endl;
      bef.pb(g2*g2);
    }
    if(ispar(g1*g1)){
      //cout << g1 << ' ' << g1*g1 << endl;
      bef.pb(g1*g1);
    }
  }
  sort(ALL(bef));

  int t;
  cin >> t;
  rep(i,t) solve(i+1);
}
