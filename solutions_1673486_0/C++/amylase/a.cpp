#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long li;
typedef pair<li, li> pi;
typedef vector<li> vi;
typedef vector<string> vs;

inline li bit(li n){ return 1LL<<n; }

#define rep(i,to)       for(li i=0;i<((li)to);i++)
#define foreach(it,set) for(__typeof((set).begin()) it=(set).begin();it!=(set).end();it++)
#define all(v)          v.begin(), v.end()

li vx[4] = {1, 0, -1, 0};
li vy[4] = {0, 1, 0, -1};

void solve(li casenum){
  double ans, p[100000];
  li a, b;

  cin >> a >> b;
  rep(i, a) cin >> p[i];
  p[a] = 0;

  ans = b + 2;

  double oprob = 1.0, e[100000] = {};

  for(li i=0; i<=a; i++){
    double prob = oprob * (1.0 - p[i]);
    for(li j=0; j<=a; j++){
      li stroke = (a - j) + (b - j) + 1;
      if(i < j) stroke += b + 1;
      e[j] += prob * stroke;
    }
    oprob = oprob - prob;
  }

  for(li i=0; i<=a; i++){
    // cout << i << " " << e[i] << endl;
    ans = min(ans, e[i]);
  }

  cout << "Case #" << casenum << ": " << ans << endl;
}

int main(){
  li t;
  cin >> t;
  cout.precision(9);
  rep(i, t) solve(i+1);

  return 0;
}
