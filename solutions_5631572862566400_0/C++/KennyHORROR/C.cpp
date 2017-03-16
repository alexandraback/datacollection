#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;

int arr[1005];
bool good[1005];
std::vector<std::vector<int> > r;

int ans = 0;

int DFS(int pos, int bad) {
  int ret = 1;
  for (int i = 0; i < r[pos].size(); ++i) {
    if (r[pos][i] == bad) {
      continue;
    }
    ret = max(ret, DFS(r[pos][i], bad) + 1);
  }
  return ret;
}

void DFS2(int pos, int start = -1, int depth = 1) {
  if (start == -1) {
    start = pos;
  }
  if (depth > 1005) {
    return;
  }
  if (arr[pos] == start) {
    ans = std::max(ans, depth);
  } else {
    DFS2(arr[pos], start, depth + 1);
  }
}

void Solve() {
  memset(arr, 0, sizeof arr);
  memset(good, 0, sizeof good);
  ans = 0;
  int n;
  cin >> n;
  r.clear();
  r.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    --arr[i];
    r[arr[i]].push_back(i);
  }
  int comps = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[arr[i]] == i) {
      comps += DFS(i, arr[i]);
    }
  }
  for (int i = 0; i < n; ++i) {
    DFS2(i);
  }
  ans = max(ans, comps);

  cout << ans << endl;
}

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
