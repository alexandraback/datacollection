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

int R, N, M, K, T;
int inp[8001][13];

unordered_map<int, int> prods;
int bestval[8001];
int bestnums[8001][16];

int tests = 100000;
void solve() {
  int nums[16];
  for (int ii = 0; ii < tests; ++ii) {
    prods.clear();
    for (int i = 0; i < N; ++i)
      nums[i] = rand() % (M-1) + 2;
    for (int m = 0; m < (1<<N); ++m) {
      int p = 1;
      for (int j = 0; j < N; ++j)
        if (m & (1<<j)) p *= nums[j];
      prods[p]++;
    }
    for (int i = 0; i < R; ++i) {
      int res = 1;
      for (int j = 0; j < K; ++j)
        res *= prods[inp[i][j]];
      if (res > bestval[i]) {
        bestval[i] = res;
        memcpy(bestnums[i], nums, sizeof nums);
      }
    }
  }
}

int main() {
  srand(time(NULL));
  memset(bestval, 0xff, sizeof bestval);
  ios_base::sync_with_stdio(false);
  cin >> T;
  cout << "Case #1:" << endl;
  cin >> R >> N >> M >> K;
  for (int i = 0; i < R; ++i)
    for (int j = 0; j < K; ++j)
      cin >> inp[i][j];
  solve();
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < N; ++j)
      cout << bestnums[i][j];
    cout << endl;
  }
}
