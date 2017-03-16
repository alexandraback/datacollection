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
  li ans = 0;
  li n, s, p;
  cin >> n >> s >> p;
  li moto = 0, dame = 0, ganba = 0;
  rep(i, n){
    li t, k, a;
    cin >> t;
    k = t / 3;
    a = t % 3;
    if(a==0){
      if(k>=p){
        moto++;
      } else if(k>0 && k+1==p){
        ganba++;
      } else {
        dame++;
      }
    } else if (a==1){
      if(k+1>=p){
        moto++;
      } else {
        dame++;
      }
    } else {
      if(k+1>=p){
        moto++;
      } else if(k+2==p){
        ganba++;
      } else {
        dame++;
      }
    }
  }
  ans = moto + min(ganba, s);
  cout << "Case #" << casenum << ": " << ans << endl;

}

int main(){
  li t;
  cin >> t;
  rep(i, t) solve(i+1);

  return 0;
}
