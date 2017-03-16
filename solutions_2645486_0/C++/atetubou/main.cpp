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
  int e,r,n;
  cin >> e >> r >> n;
  vector<int> in(n);
  rep(i,n) cin >> in[i];
  int cost[n+1][e+1];
  memset(cost,-1,sizeof(cost));
  priority_queue<pair<PI,int> > q;
  q.push(mp(mp(0,-e),0));
  int ans = 0;
  while(!q.empty()){
    int cc=q.top().S;
    int ce=-q.top().F.S;
    int ne=-q.top().F.F;
    q.pop();
    if(cost[ne][ce]>=cc) continue;
    //cout << cc << ' ' << ce << ' ' << ne << endl;        
    if(ne==n){
      ans = max(ans,cc);
      continue;
    }
    cost[ne][ce] = cc;
    for(int i=0;i<=ce;++i)
      q.push(mp(mp(-ne-1,-min(ce-i+r,e)),
                cc+i*in[ne]));
  }
  printf("Case #%d: %d\n",ca,ans);
}

int main(){
  int t;
  cin >> t;
  rep(i,t) solve(i+1);
}
