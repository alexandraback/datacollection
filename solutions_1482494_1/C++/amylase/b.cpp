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
  li ans = bit(60), n;
  vector<pair<li, pi> > s;
  vi dif;

  cin >> n;
  rep(i, n){
    li l1, l2;
    cin >> l1 >> l2;
    s.push_back(make_pair(l1, make_pair(i, 1)));
    s.push_back(make_pair(l2, make_pair(i, 2)));
    dif.push_back(l2-l1);
  }

  sort(all(s));

  li prog[1005] = {};
  vector<pair<li, pi> >::iterator itr = s.begin();
  priority_queue<pair<pi, li> > ok;
  li cnt = 0, star = 0;

  while(itr != s.end()){
    if(itr->first <= star){

      ok.push(make_pair(make_pair(itr->second.second, dif[itr->second.first]), itr->second.first));
      itr++;
    } else {
      break;
    }
  }

  while(!ok.empty()){

    pair<pi, li> i = ok.top(); ok.pop();
    pi it = make_pair(i.first.first, i.second);

    //cout<<it.second<<" "<<it.first<<" "<<star<<" " <<cnt<<endl;;

    if(prog[it.second] < it.first){
      star += it.first - prog[it.second];
      prog[it.second] = it.first;
      cnt++;
    }

    while(itr != s.end()){
      if(itr->first <= star){
        ok.push(make_pair(make_pair(itr->second.second, dif[itr->second.first]), itr->second.first));
        itr++;
      } else {
        break;
      }
    }
  }

  if(itr == s.end()){
    ans = cnt;
  }

  if(ans < bit(60))
    cout << "Case #" << casenum << ": " << ans << endl;
  else 
    cout << "Case #" << casenum << ": " << "Too Bad" << endl;

  return;
}

int main(){
  li t;
  cin >> t;
  rep(i, t) solve(i+1);

  return 0;
}
