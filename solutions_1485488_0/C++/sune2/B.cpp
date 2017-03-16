#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

struct P {
  int i,j;
  double t;
  P(int i, int j, double t):i(i),j(j),t(t) {}
};
bool operator<(const P &a, const P&b) {
  return a.t!=b.t?a.t>b.t:a.i!=b.i?a.i<b.i:a.j<b.j;
}

int f[100][100];
int c[100][100];
double dis[100][100];

bool ok(int i1, int j1, int i2, int j2) {
  if (c[i2][j2]-f[i2][j2] < 50) return 0;
  if (f[i1][j1]>c[i2][j2]-50) return 0;
  if (c[i1][j1]-50<f[i2][j2]) return 0;
  return 1;
}
int h,n,m;
double func(int i, int j, double t) {
  if (t==0) return 0;
  double hh = h-t*10;
  if (hh>=f[i][j]+20) return t+1;
  else return t+10;
}
double func2(int i, int j) {
  // cout << h << " " << c[i][j] << endl;
  // cout << double(h-c[i][j]+50)/10 << " " << max(0.0,double(h-c[i][j]+50)/10) << endl;
  return max(0.0,double(h-c[i][j]+50)/10);
}

int main() {
  int T;cin>>T;
  REP(t,T) {
    cin>>h>>n>>m;
    REP(i,n) REP(j,m) cin >> c[i][j];
    REP(i,n)REP(j,m)cin>>f[i][j];
    const int dx[] = {-1,0,1,0};
    const int dy[] = {0,1,0,-1};
    priority_queue<P> Q;
    Q.push(P(0,0,0));
    double ans = -1;
    REP(i,n)REP(j,m)dis[i][j] = INF;
    while(!Q.empty()) {
      P p = Q.top(); Q.pop();
      //cout << p.i << " " << p.j << " " << p.t << endl;
      if (dis[p.i][p.j]+EPS < p.t) continue;
      if (p.i==n-1&&p.j==m-1) {
        ans = p.t;
        break;
      }
      REP(d,4) {
        int ii=p.i+dy[d];
        int jj=p.j+dx[d];
        if (ii<0||ii>=n||jj<0||jj>=m) continue;
        if (!ok(p.i,p.j,ii,jj)) continue;
        double t = max(func(p.i,p.j,p.t), func(p.i,p.j,func2(ii,jj)));
        if (dis[ii][jj] > t) {
          dis[ii][jj] = t;
          Q.push(P(ii,jj,t));
        }
      }
    }
    printf("Case #%d: %.10f\n", t+1, ans);    
  }
}
