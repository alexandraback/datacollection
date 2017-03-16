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

inline string itos(li i){
  ostringstream oss;
  oss<<i;
  return oss.str();
}

void solve(li casenum){
  li a, b, dig, ans = 0;
  cin >> a >> b;

  dig = itos(a).size();

  for(li i=a; i<=b; i++){
    string is = itos(i);
    set<li> s;
    for(li p=1; p<dig; p++){
      li ri;
      istringstream iss(is.substr(p) + is.substr(0,p));
      iss >> ri;
      if(i < ri && ri <= b){
        s.insert(ri);
      }
    }
    ans += s.size();
  }
  cout << "Case #" << casenum << ": " << ans << endl;
  cerr << "solve case #" << casenum << endl;
}

int main(){
  li t;
  cin >> t;
  rep(i, t) solve(i+1);

  return 0;
}
