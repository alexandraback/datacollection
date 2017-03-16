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

int E, R, N, T;
int v[10000];

int solve(int e, int i) {
  if (i == N) return 0;
  int best = -1;
  for (int x = 0; x <= e; ++x) {
    int rest = min(E, e - x + R);
    best = max(best, v[i] * x + solve(rest, i + 1));
  }
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ": ";
    cin >> E >> R >> N;
    for (int i = 0; i < N; ++i)
      cin >> v[i];
    cout << solve(E, 0) << endl;
  }
}
