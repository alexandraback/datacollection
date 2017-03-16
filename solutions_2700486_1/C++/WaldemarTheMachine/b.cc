#include <string> 
#include <cmath>  
#include <cstdlib>  
#include <algorithm>  
#include <vector>  
#include <string.h>  
#include <utility>  
#include <queue>
#include <stack>
#include <iostream>  
#include <iomanip>  
#include <ctype.h>  
#include <sstream>  
#include <map> 
#include <set> 
#include <stdio.h>  
#include <ctype.h>  

using namespace std;

#define INF = 2000000000
#define FOR(i,n) for(int i = 0;i < n;i++)
#define CLEAR(x) memset((x),0,sizeof(x))
#define REP(i,a,b) for(int i = (a);i<(b);++i)
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define PII pair<int,int>
#define sz(a) (int)(a).size()

typedef long long LL;

inline double sim(int y, int l, int r, int mx,int n, int depth){
  if (l >= y)
    return 0;
  if (n == 0)
    return 1;

  if (depth > 30)
    return 0;

  double rr = 0;
  if (l < mx && r < mx)
  rr += sim(y,l+1,r,mx,n-1,depth+1)/2;
  else if (l < mx)
  return sim(y,l+1,r,mx,n-1,depth+1);
  
  if (r < mx && r < mx)
  rr += sim(y,l,r+1,mx,n-1,depth+1)/2;
  else if (r < mx) 
  return sim(y,l,r+1,mx,n-1,depth+1);

  return rr;
}

double pr(int y, int mx, int n){
  if (n >= mx+y)
    return 0;

 //cerr << n << ' ' << mx << ' ' << y << ' ' << l << ' ' << r << endl;
 
  return sim(y,0,0,mx,n, 0);
}

void solve (int t){
  cout << "Case #" << t << ": ";
  int n,x,y;
  cin >> n >> x >> y;

  int ns = 1;
  int lev = 0;
  int my = abs(x) + y;

  while (n >= ns){
    n -= ns;
    ns += 4;
    lev += 2;
  }

  if (my < lev){
    cout << 1.0 << endl;
    return;
  }
  if (my > lev || n == 0){
    cout << 0.0 << endl;
    return;
  }

  int mx = (ns-1)/2;

  if (y == mx || n <= y){
    cout << 0.0 << endl;
    return;
  }

  y++; // now >= 1

  cout << 1 - pr(y,mx,n) << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  FOR(i,t)
  solve(i+1);

  return 0;
}
