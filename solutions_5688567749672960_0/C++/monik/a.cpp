#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

#define INF 2000000
using namespace std;

int T, N;

int rev(int x) {
  int y = 0;
  while(x > 0) {
    y *= 10;
    y += x % 10;
    x /= 10;
  }
  return y;
}

int main(void) {
  cin >> T;
  vector<long long> V(1000100, INF);
  REP(t, T) {
    queue<int> Q;
    cin >> N;
    Q.push(1);
    V[1] = 1;
    while(!Q.empty()) {
      int top = Q.front();
      Q.pop();
      if (top > 1000000) continue;

      // REP(i, 20) cout << V[i]; cout << endl;

      if (V[top + 1] == INF) {
        V[top+1] = V[top]+1;
        Q.push(top+1);
      }
      int r = rev(top);
      if (V[r] == INF) {
        V[r] = V[top]+1;
        Q.push(r);
      }
    }
    cout << "Case #" << (t+1) << ": " << V[N] << endl;
  }
  return 0;
}
