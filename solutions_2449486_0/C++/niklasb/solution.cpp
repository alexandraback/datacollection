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

int N, M;
int grid[10][10];
static bool row[10], col[10];

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int t_ = 1; t_ <= T; ++t_) {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        cin >> grid[i][j];
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    for (int i = 0; i < N; ++i) {
      bool r = 1;
      for (int j = 0; j < M; ++j) {
        if (grid[i][j] != 1) r = 0;
      }
      row[i] = r;
    }
    for (int j = 0; j < M; ++j) {
      bool c = 1;
      for (int i = 0; i < N; ++i) {
        if (grid[i][j] != 1) c = 0;
      }
      col[j] = c;
    }
    bool valid =1;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        if (grid[i][j] == 1 && !col[j] && !row[i]) valid = 0;
    cout << "Case #" << t_ << ": ";
    cout << (valid?"YES":"NO") << endl;
  }
}
