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

map<char, char> gtoe;

void solve(li casenum){
  string ans;
  getline(cin, ans);

  foreach(it, ans){
    *it = gtoe[*it];
  }
  cout << "Case #" << casenum << ": " << ans << endl;
}

int main(){
gtoe['a'] = 'y';
gtoe['b'] = 'h';
gtoe['c'] = 'e';
gtoe['d'] = 's';
gtoe['e'] = 'o';
gtoe['f'] = 'c';
gtoe['g'] = 'v';
gtoe['h'] = 'x';
gtoe['i'] = 'd';
gtoe['j'] = 'u';
gtoe['k'] = 'i';
gtoe['l'] = 'g';
gtoe['m'] = 'l';
gtoe['n'] = 'b';
gtoe['o'] = 'k';
gtoe['p'] = 'r';
gtoe['q'] = 'z';
gtoe['r'] = 't';
gtoe['s'] = 'n';
gtoe['t'] = 'w';
gtoe['u'] = 'j';
gtoe['v'] = 'p';
gtoe['w'] = 'f';
gtoe['x'] = 'm';
gtoe['y'] = 'a';
gtoe['z'] = 'q';
gtoe[' '] = ' ';

  string t;
  getline(cin, t);
  istringstream iss(t);
  li tt;
  iss >> tt;
  rep(i, tt) solve(i+1);

  return 0;
}
