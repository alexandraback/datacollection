#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int test_case_number_ = 0;
#define gout printf("Case #%d: ", ++test_case_number_),cout

const int MAXV = 2000;

int w[MAXV], pairV[MAXV];
vector<int> ed[MAXV];

int findPair(int u, const int color) {
  if (w[u] == color) {
    return 0;
  }
  w[u] = color;

  for (int v : ed[u]) {
    if (pairV[v] == -1 || findPair(pairV[v], color)) {
      pairV[v] = u;
      pairV[u] = v;
      return 1;
    }
  }

  return 0;
}

void Solution() {
  int numEdges;
  cin >> numEdges;
  // Initialize edges, etc.
  memset(w, 0, sizeof(w));
  memset(pairV, -1, sizeof(pairV));
  for (int i = 0; i < 2000; ++i) {
    ed[i].clear();
  }
  // Prepare name mapping variables.
  map<string, int> firstHalf;
  map<string, int> secondHalf;
  int n = 0, m = 0;
  // Read edges.
  for (int i = 0; i < numEdges; ++i) {
    string a, b;
    cin >> a >> b;
    if (!firstHalf.count(a)) {
      firstHalf[a] = n++;
    }
    if (!secondHalf.count(b)) {
      secondHalf[b] = m++;
    }
    int u = firstHalf[a], v = secondHalf[b] + 1000;
    ed[u].push_back(v);
    ed[v].push_back(u);
  }

  int cnt = 0, match = 0;
  for (int i = 0; i < 1000; ++i) {
    ++cnt;
    match += findPair(i, cnt);
  }

  int ans = numEdges - match;
  for (int i = 0; i < 2000; ++i) {
    if (ed[i].size() > 0 && pairV[i] == -1) {
      --ans;
    }
  }
  gout << ans << endl;
}

int main() {
  int test_cases;
  cin >> test_cases;
  for (int t_case = 0; t_case < test_cases; ++t_case) {
    Solution();
  }

  return 0;
}
