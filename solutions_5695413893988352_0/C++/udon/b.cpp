#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll INF = 5000000000;
#define PB push_back
#define sz(a) (a).size()
#define reps(i,n,m) for(int (i)=(n);(i)<(m);++(i))
#define rep(i,n) reps(i,0,n)
ll T;

bool match(string s, int x) {
  rep(i, sz(s)) {
    if (s[sz(s) - 1 - i] == '?') {x /= 10; continue;}
    int d = s[sz(s) - 1 - i] - '0';
    if(d != x % 10) return false;
    x /= 10;
  }
  return true;
}
string mk_str(int d, int l) {
  string ret = "";
  rep(i, l) {
    char c = ((d % 10) + '0');
    ret =  c + ret;
    d /= 10;
  }
  return ret;
}

void solve(int time) {
  int ans0 = 100000;
  int ans1 = 0;
  int ans_dif = abs(ans0 -  ans1);
  string s1, s2;
  cin >> s1 >> s2;
  int n = 10;
  if(sz(s1) == 2) {
    n = 100;
  } else if (sz(s1) == 3) {
    n = 1000;
  }
  rep(i, n) {
    if(!match(s1, i)) continue;
    rep(j, n) {
      if(!match(s2, j)) continue;
      int dif = abs(i -  j);
      if (dif < ans_dif) {
        ans0 = i;ans1 = j;
        ans_dif = abs(ans0 -  ans1);
      }
    }
  }
  string sans0 = mk_str(ans0, sz(s1));
  string sans1 = mk_str(ans1, sz(s1));
  printf("Case #%d: %s %s\n", time, sans0.c_str(), sans1.c_str());
}

int main(){
  cin >> T;
  reps(times, 1, T+1) {
    solve(times);
  }

}
