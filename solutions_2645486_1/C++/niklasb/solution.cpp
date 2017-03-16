#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;
using namespace std::tr1;

typedef long long llong;
typedef pair<int, int> int2;
typedef pair<llong, llong> llong2;
#define foreach(v,c) for (typeof((c).begin()) v = (c).begin(); v != (c).end(); ++v)
#define rep(i,n) for (int i = 0; i < (n); ++i)

llong E, R, N, T;
llong v[10010];
pair<llong, llong> vs[10010];
llong l[10010];
llong r[10010];

llong solve() {
  memset(l, 0, sizeof l);
  for (int i = 0; i < N; ++i)
    r[i] = E;
  sort(vs, vs + N);
  llong res = 0;
  for (int i = 0; i < N; ++i) {
    llong val = -vs[i].first;
    llong x = vs[i].second;
    res += (r[x] - l[x]) * val;
    for (int j = 0; j < N; ++j) {
      if (j < x) {
        l[j] = max(l[j], r[x] - R*(x-j));
      } else if (j > x) {
        r[j] = min(r[j], l[x] + R*(j-x));
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ": ";
    cin >> E >> R >> N;
    for (int i = 0; i < N; ++i) {
      cin >> v[i];
      vs[i] = make_pair(-v[i], i);
    }
    cout << solve() << endl;
  }
}
