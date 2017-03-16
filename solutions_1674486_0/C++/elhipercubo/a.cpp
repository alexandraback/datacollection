#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>
#include <stdexcept>
using namespace std;

vector<int> edges[1024];
bool visited[1024];
int num[1024][1024];
vector<int> order;

void dfs(int v) {
  visited[v] = true;
  for (int i = 0; i < edges[v].size(); ++i) {
    int w = edges[v][i];
    if (!visited[w])
      dfs(w);
  }
  order.push_back(v);
}

int main() {
  int cases;
  scanf("%i", &cases);
  for (int numcase = 1; numcase <= cases; ++numcase) {
    printf("Case #%i: ", numcase);
    int n;
    scanf("%i", &n);
    for (int i = 0; i < n; ++i) edges[i].clear();
    fill(&num[0][0], &num[n][0], 0);
    for (int i = 0; i < n; ++i) {
      int m, j;
      scanf("%i", &m);
      while (m--) {
        scanf("%i", &j);
        --j;
        edges[i].push_back(j);
        ++num[i][j];
      }
    }

    fill(&visited[0], &visited[n], false);
    order.clear();
    for (int i = 0; i < n; ++i)
      if (!visited[i])
        dfs(i);
    reverse(order.begin(), order.end());

    bool diamond = false;
    for (int ii = 0; ii < n; ++ii)
      for (int jj = ii + 1; jj < n; ++jj) {
        int i = order[ii], j = order[jj];
        for (int kk = ii + 1; num[ii][jj] <= 1 && kk < jj; ++kk) {
          int k = order[kk];
          num[i][j] += num[i][k] * num[k][j];
        }
        if (num[i][j] > 1) {
          diamond = true;
          num[i][j] = 2;
        }
      }
    puts(diamond ? "Yes" : "No");
  }
  return 0;
}
