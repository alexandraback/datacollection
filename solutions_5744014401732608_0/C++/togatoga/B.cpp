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
ll B, M;
vector<vector<int>> ans;
vector<bool> visited;
int test_case;
void dump(vector<vector<int>> &ans) {
  for (int i = 0; i < B; i++) {
    for (int j = 0; j < B; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
void check_dfs(int pos, int &cnt) {
  if (cnt > M) {
    return;
  }
  if (pos == B - 1) {
    cnt++;
    return;
  }

  visited[pos] = true;
  for (int i = 0; i < B; i++) {
    if (not visited[i]) {
      // if (test_case % 4 == 0) {
      //   cout << i << " " << visited.size() << endl;
      //   cout << ans[pos].size() << endl;
      // }
      if (ans[pos][i] == 1) {
        check_dfs(i, cnt);
      }
    }
  }
  visited[pos] = false;
  return;
}
bool ok;
bool create_bit_dfs(int depth) {
  if (ok) {
    return true;
  }
  if (depth >= B - 1) {
    visited.resize(B + 1, false);
    int cnt = 0;
    check_dfs(0, cnt);
    // dump(ans);
    // cout << "cnt = " << cnt << endl;
    if (cnt == M) {
      ok = true;
      return true;
    }
    return false;
  }

  for (int bit = 0; bit < (1 << B); bit++) {
    if (((bit >> depth) & 1))
      continue;
    for (int i = 0; i < B; i++) {
      if (((bit >> i) & 1)) {
        ans[depth][i] = 1;
      } else {
        ans[depth][i] = 0;
      }
    }
    if (create_bit_dfs(depth + 1)) {
      ok = true;
      break;
    }
  }
  return ok;
}
void solve(const int case_id) {
  cin >> B >> M;
  test_case = case_id;
  ans.clear();
  for (int i = 0; i < B; i++){
  	vector<int> tmp;
  	for (int j = 0; j < B; j++){
  		tmp.push_back(0);
  	}
  	ans.push_back(tmp);
  }
  // cerr << "B = " << B << " M = " << M << endl;
  ok = false;
  if (create_bit_dfs(0)) {
    printf("Case #%d: POSSIBLE\n", case_id);
    for (int i = 0; i < ans.size(); i++) {
      for (int j = 0; j < ans.size(); j++) {
        cout << ans[i][j];
      }
      cout << endl;
    }
  } else {
    printf("Case #%d: IMPOSSIBLE\n", case_id);
    // for (int i = 0; i < B; i++) {
    //   for (int j = 0; j < B; j++) {
    //     cout << ans[i][j];
    //   }
    //   cout << endl;
    // }
  }
}
int main() {
  cin >> T;
  for (int i = 0; i < T; i++) {
    solve(i + 1);
  }
  return 0;
}