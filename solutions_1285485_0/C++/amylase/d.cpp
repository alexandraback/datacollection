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

bool isok(li vx, li w, li mw){
  return (vx + (w - mw) * 2) % (2 * w) == 0 || vx % (2 * w) == 0;
}

void solve(li casenum){
  li h,w,d,mh,mw;
  cin >> h >> w >> d;

  rep(i,h){
    string str;
    cin >> str;
    rep(j,w){
      if(str[j]=='X'){
        mh = i;
        mw = j;
      }
    }
  }

  h = h*2-4;
  w = w*2-4;

  mw = mw*2-1;
  mh = mh*2-1;
  /*
  cerr << " h = " << h << endl;
  cerr << " w = " << w << endl;
  cerr << "mh = " << mh << endl;
  cerr << "mw = " << mw << endl;
  */
  set<pi> dir;

  const li rect = 1200;
  for(li x = -rect; x<=rect; x++){
    for(li y = -rect; y<=rect; y++){
      li vx = x-mw, vy = y-mh;
      if(vx*vx + vy*vy <= 4*d*d && isok(vx,w,mw) && isok(vy,h,mh)){
        pi tmp;
        if(vx==0 && vy==0) continue;
        if(vx==0){
          tmp = make_pair(0,abs(vy)/vy);
        } else if(vy==0){
          tmp = make_pair(abs(vx)/vx,0);
        } else {
          li gc = __gcd(abs(vx), abs(vy));
          tmp = make_pair(vx/gc, vy/gc);
        }
        dir.insert(tmp);
        /*
        cerr << x << " " << y << endl;
        cerr << vx << " " << vy << endl;
        cerr << tmp.first << " " << tmp.second << endl;
        */
      }
    }
  }

  cout << "Case #" << casenum << ": " << dir.size() << endl;

}

int main(){
  li t;
  cin >> t;
  rep(i, t) solve(i+1);

  return 0;
}
