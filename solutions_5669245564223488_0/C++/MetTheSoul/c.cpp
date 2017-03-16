#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

const int N = 110;
const int MOD = (int)1e9+7;
typedef __int64 lld;
int n,dp[1<<10][13],state[N];
string str[N];

int get(string &s) {
  int ret = 0;
  for (int i = 0; i < (int)s.length(); i ++) {
    int c = s[i]-'a';
    if (i && s[i]!=s[i-1]) {
      if (ret>>c&1) return -1;
    }
    ret |= 1<<c;
  }
  return ret;
}

void add(int &a,int b) {
  a += b;
  if (a>=MOD) a -= MOD;
}

int work() {
  for (int i = 0; i < n; i ++) {
    int x = get(str[i]);
    if (x<0) return 0;
    state[i] = x;
  }
  memset(dp,0,sizeof(dp));
  for (int i = 0; i < n; i ++) {
    dp[1<<i][i] = 1;
  }
  for (int s = 0; s < 1<<n; s ++) {
    int val = 0;
    for (int j = 0; 1<<j <= s; j ++) if (s>>j&1) {
      val |= state[j];
    }
    for (int i = 0; 1<<i <= s; i ++) if (dp[s][i]) {
      for (int j = 0; j < n; j ++) if (!(s>>j&1)){
        int ed = str[i][str[i].length()-1] - 'a';
        int bg = str[j][0]-'a';
        if (bg!=ed) {
          if (val&state[j]) {
            continue;
          }
        } else {
          int nval = val^1<<ed;
          if (nval&state[j]) {
            continue;
          }
        }
        add(dp[s|1<<j][j],dp[s][i]);
      }
    }
  }
  int ret = 0;
  for (int i = 0; i < n; i ++) {
    add(ret,dp[(1<<n)-1][i]);
  }
  return ret;
}

int main() {
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int cas,ca = 0;
  cin >> cas;
  while (cas--) {
    cin >> n;
    for (int i = 0; i < n; i ++) {
      cin >> str[i];
    }
    cout << "Case #" << (++ca) << ": " << (work()) << endl;
  }
  return 0;
}
