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

void solve(int ca){
  ll r,t;
  cin >> r >> t;
  ll low=0,up=1LL<<60LL;
  while(low+1<up){
    ll mid=(low+up)/2;
    ll need=mid*(2*mid+2*r-1);
    //cout << mid << ' ' << need << ' ' << t << endl;
    if(need <= t && need/mid==(2*mid+2*r-1) &&
       need/(2*mid+2*r-1)==mid) low = mid;
    else up = mid;
  }
  printf("Case #%d: %lld\n",ca,low);
}

int main(){
  int t;
  cin >> t;
  rep(i,t) solve(i+1);
}
