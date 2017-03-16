#include <bits/stdc++.h>

using namespace std;

const int N = 1010101;
const long long inf = (long long)1e15;

typedef long long ll;

int  n;

int rev(ll cur, ll a) {
  if (cur == 0)
    return a;
  return rev(cur / 10, a * 10 + cur % 10);
}

ll dp(ll x) {
  queue <int> q;
  unordered_map <int, int> dist;
  q.push(1);
  dist[1] = 1;
  while (q.size()) {
    int top = q.front();
    q.pop();
    if (top == n)
      return dist[n];
    int a = top + 1;
    int b = rev(top, 0);
    if (!dist.count(a) && a <= n && a >= 1) {
      dist[a] = dist[top] + 1;
      q.push(a);
    }
    if (!dist.count(b) && b <= n && b >= 1) {
      dist[b] = dist[top] + 1;
      q.push(b);
    }
  }
  return dist[n];
}

int main() {
  int tc;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    printf("Case #%d: ", t);
    cin >> n;
    cout << dp(1) << endl;
  }
  return 0;
}
