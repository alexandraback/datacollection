#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
int d[N];

int rev(int n) {
  int r = 0;
  while(n > 0) {
    r = r * 10 + n % 10;
    n /= 10;
  }
  return r;
}

int main() {
  freopen("A.in", "rt", stdin);
  freopen("A.out", "wt", stdout);
  int t; scanf("%d", &t);
  for(int test = 1; test <= t; ++test) {
    int n; scanf("%d", &n);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
    memset(d, 63, sizeof d);
    d[1] = 1;
    Q.push(make_pair(1, 1));
    while(Q.size() > 0) {
      int c = Q.top().first;
      int u = Q.top().second;
      Q.pop();
      if(d[u] != c) continue;
      if(u == n) break;
      // ++
      if(d[u + 1] > c + 1) {
        d[u + 1] = c + 1;
        Q.push(make_pair(d[u + 1], u + 1));
      }
      // reverse
      u = rev(u);
      if(d[u] > c + 1) {
        d[u] = c + 1;
        Q.push(make_pair(d[u], u));
      }
    }
    printf("Case #%d: %d\n", test, d[n]);
  }
  return 0;
}
