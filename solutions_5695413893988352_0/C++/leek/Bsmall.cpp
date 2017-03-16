#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
string G,J;

string conv(int x, string s) {
  string tt = "";
  int xx = x;
  while(xx > 0) {
    tt = ((char) ('0' + (xx%10))) + tt;
    xx /= 10;
  }
  while(tt.size() < s.size()) {
    tt = ('0' + tt);
  }
  return tt;
}

bool fit(string tt, string s) {
  if(tt.size() > s.size()) return false;
  for(int i=0; i<tt.size(); i++) {
    if(s[i] == '?') continue;
    if(s[i] != tt[i]) return false;
  }

  return true;
}


int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    cin >> G >> J;
    int cur = 1999;
    int gs=0, js = 0;
    for(int i=0;i <=999; i++) {
      for(int j=0;j<=999; j++) {
        string gg = conv(i,G);
        string jj = conv(j,J);
        if(fit(gg,G) && fit(jj,J) && abs(i-j) < cur) {
          cur = abs(i-j);
          gs = i; js = j;
        }
      }
    }
    cout <<"Case #" << tc <<": " << conv(gs,G) << ' ' << conv(js,J) << endl;

  }

  return 0;
}