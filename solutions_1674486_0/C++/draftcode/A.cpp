#include <algorithm>
#include <functional>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <sstream>
#include <vector>
#include <map>
#include <set>

#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

bool dfs(vector<vector<int> > v, vector<int> &visited, int a) {
  if (visited[a]) {
    // cout << a << " is visited" << endl;
    return true;
  }
  // cout << "visit " << a << endl;
  visited[a] = true;

  for (int i = 0; i < v[a].size(); i++) {
    if (dfs(v, visited, v[a][i])) {
      return true;
    }
  }

  return false;
}

void calc(void) {
  int N; cin >> N;
  vector<vector<int> > v(N, vector<int>());
  for (int i = 0; i < N; i++) {
    int K; cin >> K;
    for (int k = 0; k < K; k++) {
      int a; cin >> a;
      v[i].push_back(a-1);
    }
  }

  for (int i = 0; i < N; i++) {
    vector<int> visited(N, 0);
    if (dfs(v, visited, i)) {
      cout << "Yes";
      return;
    } else {
      continue;
    }
  }
  cout << "No";
}

int main(void) {
  ios::sync_with_stdio(false);
  int T; cin >> T;
  for (int i = 1; i <= T; i++) {
    cout << "Case #" << i << ": ";
    calc();
    cout << endl;
  }
  return 0;
}
