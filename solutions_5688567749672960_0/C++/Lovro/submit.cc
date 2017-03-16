#define NDEBUG
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int reverse(int x) {
  int ans = 0;
  while (x > 0) {
    ans = 10 * ans + x % 10;
    x /= 10;
  }
  return ans;
}

int solve(int n) {
  vector<int> dist(10*n, -1);
  queue<int> q;
  q.push(1);
  dist[1] = 1;

  while (!q.empty()) {
    int a = q.front(); q.pop();
    if (a == n) {
      return dist[a];
    }

    for (int b : {a+1, reverse(a)}) {
      if (dist[b] == -1) {
        dist[b] = dist[a] + 1;
        q.push(b);
      }
    }
  }
  abort();
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    int n;
    cin >> n;
    printf("Case #%d: %d\n", tt, solve(n));
  }
}
