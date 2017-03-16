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
int prods[6][6][6][125];
int inp[10];

void preprocess() {
  for (int a = 2; a <= 5; ++a)
    for (int b = 2; b <= 5; ++b)
      for (int c = 2; c <= 5; ++c)
        for (int m = 0; m < 8; ++m) {
          int p = 1;
          if (m&1) p *= a;
          if (m&2) p *= b;
          if (m&4) p *= c;
          prods[a][b][c][p]++;
        }
}

int solve() {
  int bestx = -1, besta, bestb, bestc;
  for (int a = 2; a <= 5; ++a)
    for (int b = 2; b <= 5; ++b)
      for (int c = 2; c <= 5; ++c) {
        int res = 1;
        for (int i = 0; i < K; ++i)
          res *= prods[a][b][c][inp[i]];
        if (res > bestx) {
          bestx = res;
          besta = a;
          bestb = b;
          bestc = c;
        }
      }
  return besta * 100 + bestb * 10 + bestc;
}

int main() {
  preprocess();
  ios_base::sync_with_stdio(false);
  cin >> T;
  cout << "Case #1:" << endl;
  cin >> R >> N >> M >> K;
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < K; ++j)
      cin >> inp[j];
    cout << solve() << endl;
  }
}
