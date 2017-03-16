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
#define MAXN 35

int ds[MAXN];
int B = 16, need = 500;
ll conv(ll b) {
  ll ans = 0, a = 1;
  for (int i = B - 1; i >= 0; i--) {
    if (ds[i]) ans += a;
    a *= b;
  }
  return ans;
}
int main() {
  //freopen("input", "r", stdin);
  freopen("output", "w", stdout);

  ds[0] = ds[B - 1] = ds[B] = ds[2 * B - 1] = 1;
  int count = 0;
  puts("Case #1:");
  REP(m, 0, 1 << (B - 2)) {
    REP(i, 0, B - 2) {
      ds[1 + i] = ds[1 + i + B] = (m >> i) & 1;
    }
    REP(i, 0, 2 * B) printf("%d", ds[i]);
    REP(b, 2, 11) printf(" %lld", conv(b));
    puts("");
    if (++count == need) break;
  }
  return 0;
}
