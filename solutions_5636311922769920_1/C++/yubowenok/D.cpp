#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int main() {
  freopen("input", "r", stdin);
  //freopen("output", "w", stdout);
  int cs;
  cin >> cs;
  REP(csn, 1, cs + 1) {
    printf("Case #%d:", csn);
    int K, C, S;
    cin >> K >> C >> S;
    if (S < (K + C - 1) / C) {
      puts(" IMPOSSIBLE");
      continue;
    }
    int batch = (K + C - 1) / C;
    int i = 0;
    vector<ll> ans;
    REP(bi, 0, batch) {
      ll pos = i;
      REP(j, 1, C) {
        int k = min(i + j, K - 1);
        pos = pos * K + k;
      }
      ans.push_back(pos + 1);
      i += C;
    }
    REP(i,0,batch) printf(" %lld", ans[i]);
    puts("");
  }
  return 0;
}
