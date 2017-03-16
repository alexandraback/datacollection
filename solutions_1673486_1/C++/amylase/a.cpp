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
  double ans, p[100005];
  li a, b;

  cin >> a >> b;
  rep(i, a) cin >> p[i];
  p[a] = 0;

  double sp[100005];
  sp[0] = 1-p[0];
  rep(i, a+1){
    sp[i+1] = sp[i] + (1-sp[i]) * (1-p[i]);
  }

  ans = b + 2;

  for(li i=0; i<=a; i++){
    li stroke = (a - i) + (b - i) + 1;
    double tmp = stroke * (1-sp[i]);

    stroke += b + 1;
    tmp += stroke * sp[i];

    ans = min(ans, tmp);
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
