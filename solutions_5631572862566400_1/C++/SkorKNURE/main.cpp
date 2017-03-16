#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n;
vector<int> v;
vector<int> depth;
vector<vector<int>> inv;

int dfs(int a, int len) {
  if (depth[a] != - 1) return 0;
  depth[a] = len;
  int b = v[a];
  int answer;
  if (depth[b] == -1) {
    answer = dfs(b, len + 1);
  } else {
    answer = len - depth[b] + 1;
  }
  return answer;
}

int maxCycle() {
  int answer = 0;
  for (int i = 0; i < n; i++) {
    depth.assign(n, -1);
    int len = dfs(i, 0);
    answer = max(answer, len);
  }
  return answer;
}

int maxLen(int i) {
  int answer = 0;
  for (int prev : inv[i]) {
    answer = max(answer, maxLen(prev));
  }
  return answer + 1;
}

void solveCase() {
  cin >> n;
  v.clear();
  v.resize(n);
  inv.clear();
  inv.assign(n, vector<int>());
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    v[i]--;
    inv[v[i]].push_back(i);
  }
  int answer1 = maxCycle();

  int answer2 = 0;
  for (int i = 0; i < n; i++) {
    int i2 = v[i];
    if (v[i2] != i || i2 < i) {
      continue;
    }
    int A = 0;
    for (int prev : inv[i]) {
      if (prev != i2) {
        A = max(A, maxLen(prev));
      }
    }
    int B = 0;
    for (int prev : inv[i2]) {
      if (prev != i) {
        B = max(B, maxLen(prev));
      }
    }
    answer2 += A + B + 2;
  }

  int answer = max(answer1, answer2);
  cout << answer;
  cerr << answer;
}

#define NAME "C-large"
//#define NAME "C-small-attempt0"
//#define NAME "test"

int main() {
  freopen(NAME ".in", "rt", stdin);
  freopen(NAME ".out", "wt", stdout);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    cerr << "Case #" << i << ": ";
    solveCase();
    cout << endl;
    cerr << endl;
  }
  return 0;
}
