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

int row[100],col[100];

void solve(int ca){
  printf("Case #%d: ",ca);
  int n,m;
  cin >> n >> m;
  vector<pair<int,PI> > in;
  rep(i,n) rep(j,m){
    int v;
    cin >> v;
    in.pb(mp(-v,mp(i,j)));
    row[i]=0;
    col[j]=0;
  }

  sort(ALL(in));
  FOR(it,in){
    int v=-it->F;
    int r=it->S.F;
    int c=it->S.S;
    if(row[r]>v && col[c]>v){
      cout << "NO" << endl;
      return;
    }
    row[r]=max(row[r],v);
    col[c]=max(col[c],v);
  }
  
  cout << "YES" << endl;
}

main(){
  int t;
  cin >> t;
  rep(i,t) solve(i+1);
}
