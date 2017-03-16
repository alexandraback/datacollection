#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <list>
#include <queue>

using namespace std;

map<int, list<int> > M;

bool dfs(int s) {
  queue<int> q;
  q.push(s);
  int cnt[1000];
  fill(cnt, cnt + 1000, 0);

  while (!q.empty()) {
    int c = q.front();
    q.pop();

    if (++cnt[c] == 2)
      return true;

    for (list<int>::iterator it = M[c].begin(); it != M[c].end(); ++it) {
      q.push(*it);
    }
  }

  return false;
}

int main() {
  int ncases, m, n, c;

  cin >> ncases;
  for (int caseno = 1; caseno <= ncases; caseno++) {
    cin >> n;
    M.clear();
    for (int i = 0; i < n; i++) {
      M[i] = list<int>();
      cin >> m;
      for (int j = 0; j < m; j++) {
        cin >> c;
        M[i].push_back(c - 1);
      }
    }

    bool good = false;
    for (int i = 0; i < n; i++)
      good = good || dfs(i);

    printf("Case #%i: %s\n", caseno, good ? "Yes" : "No");
  }
}
