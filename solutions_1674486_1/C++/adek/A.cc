#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define ASSERT_ for (;;) {}
#define PII pair<int, int>
using namespace std;

int main() {
  int ntestcase;
  scanf("%d\n", &ntestcase);
  for (int test_id = 1; test_id <= ntestcase; test_id++) {
    int n;
    scanf("%d\n", &n);
    vector<bool> visited(n);
    vector<vector<int> > graph(n);
    int m;
    for (int i = 0; i < n; i++) {
      int tmp;
      scanf("%d", &m);
      for (int j = 0; j < m; j++) {
        scanf("%d", &tmp);
        graph[i].push_back(tmp-1);
      }
    }
    bool res = false;
    for (int i = 0; i < n; i++) {
      visited.assign(n, false);
      stack<int> q;
      q.push(i);
      while (!(q.empty())) {
        int x;
        x = q.top(); q.pop();
        if (visited[x] == true) {
          res = res || true;
          break;
        }
        for (int j = 0; j < graph[x].size(); j++) {
          q.push(graph[x][j]);
        }
        visited[x] = true;
      }
    }
    printf("Case #%d: %s\n", test_id, (res) ? "Yes" : "No");
  }

  return 0;
}
