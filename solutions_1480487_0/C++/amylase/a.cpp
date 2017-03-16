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
  li n, sum=0;
  cin >> n;

  vector<double> s(n), ans(n);
  rep(i,n){
    cin >> s[i];
    sum += s[i];
  }

  rep(i,n){
    double lo = 0, hi = 1;
    while(hi - lo > 1e-8){
      double med = (hi + lo) / 2.0;
      vector<double> ts = s;
      ts[i] += med * sum;
      double score = ts[i];

      sort(all(ts));

      double needp = 0;
      for(li j=0; ts[j] < score; j++){
        needp += (score - ts[j]) / sum;
      }

      if(needp + med > 1){
        hi = med;
      } else {
        lo = med;
      }

    }
    ans[i] = (lo + hi) * 50.0;
  }

  cout << "Case #" << casenum << ":";
  foreach(it,ans){
    printf(" %.09f", *it);
  }
  cout << endl;
  return;
}

int main(){
  li t;
  cin >> t;
  rep(i, t) solve(i+1);

  return 0;
}
