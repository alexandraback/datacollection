#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef long long Int;

Int reverse(Int x) {
  Int y = 0;
  while (x) {
    y *= 10;
    y += x % 10;
    x /= 10;
  }
  return y;
}

void solve(int idx) {
  queue<Int> q;
  unordered_map<Int, Int> dist;
  dist[1] = 1;
  q.push(1);

  Int goal; cin >> goal;
  while (dist.find(goal) == dist.end()) {
    Int cur = q.front(); q.pop();
    Int d = dist[cur];

    if (dist.find(cur + 1) == dist.end()) {
      dist[cur+1] = d+1;
      q.push(cur+1);
    }

    Int r = reverse(cur);
    if (dist.find(r) == dist.end()) {
      dist[r] = d+1;
      q.push(r);
    }
  }
  cout << "Case #" << idx << ": " << dist[goal] << endl;
}

int main() {
  int t; cin >> t;
  for (int idx = 1; idx <= t; ++idx) {
    solve(idx);
  }
}
