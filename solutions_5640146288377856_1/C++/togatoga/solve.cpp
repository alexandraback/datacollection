#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <bitset>

#include <tuple>
#include <unordered_map>

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int INF = 1 << 29;
const double EPS = 1e-9;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int T;
int R, C, W;
int main() {
  int Test = 1;
  cin >> T;
  while (T--) {
    cin >> R >> C >> W;
    int res = 0;
    for (int i = 1; i <= R; i++) {
      res += C / W;
    }
    res += C % W == 0 ? W - 1 : W;
    printf("Case #%d: %d\n", Test++, res);
  }

  return 0;
}