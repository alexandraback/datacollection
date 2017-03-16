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
int grid[100][100];
static int row[100], col[100];

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  for (int t_ = 1; t_ <= T; ++t_) {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        cin >> grid[i][j];
    for (int i = 0; i < N; ++i) {
      row[i] = -1;
      for (int j = 0; j < M; ++j)
        row[i] = max(row[i], grid[i][j]);
    }
    for (int j = 0; j < M; ++j) {
      col[j] = -1;
      for (int i = 0; i < N; ++i)
        col[j] = max(col[j], grid[i][j]);
    }
    bool valid = 1;
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < M; ++j)
        if (col[j] > grid[i][j] && row[i] > grid[i][j])
          valid = 0;
    cout << "Case #" << t_ << ": ";
    cout << (valid?"YES":"NO") << endl;
  }
}
