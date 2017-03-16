#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
string s;
string dp[1001];

string solve(int idx) {
  string & ret = dp[idx];
  if(ret != "") return ret;
  ret = "";
  if(idx == 0) {
    ret += s[0];
    return ret;
  }

  string sm = solve(idx-1);
  string c1 = sm + s[idx];
  string c2 = s[idx] + sm;
  if(c1 >= c2) ret = c1;
  else ret = c2;
  return ret;

}


int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    for(int i=0;i < 1001; i++) dp[i] = "";
    cin >> s;
    printf("Case #%d: ",tc);
    cout << solve(s.size()-1) << endl;

  }

  return 0;
}