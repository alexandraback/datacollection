#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

int N;
string topics[1000][2];
int dp[16][1<<16];

int calc(int n, int st) {
  int &ret = dp[n][st];
  if(ret == -1) {
    ret = 0;

    st |= 1 << n;
    for(int j = 0; j < N; ++j) {
      if((st&(1<<j)) == 0)
        ret = max(ret, calc(j, st));
    }

    bool a = false, b = false;
    for(int j = 0; j < N; ++j) {
      if(n != j) {
        if(st&(1<<j)) {
          a |= topics[n][0] == topics[j][0];
          b |= topics[n][1] == topics[j][1];
        }
      }
    }

    ret += a&&b;
  }
  return ret;
}

int main(void){
  int T;
  cin >> T;
  for(int tt = 0; tt < T; ++tt) {
    cin >> N;
    for(int i = 0; i < N; ++i) {
      cin >> topics[i][0] >> topics[i][1];
      fill_n(dp[i], 1<<N, -1);
    }

    int res = 0;
    for(int i = 0; i < N; ++i)
      res = max(res, calc(i, 0));

    cout << "Case #" << tt+1 << ": " << res << endl;
  }

  return 0;
}
