#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <unordered_set>
using namespace std;

typedef long long ll;

ll reverse(ll x) {
  string s = to_string(x);
  reverse(s.begin(), s.end());
  stringstream ss(s);
  ll y;
  ss >> y;
  return y;
}

ll solve_case() {
  ll n;
  cin >> n;
  if (n == 1) return 1;
  queue<ll> Q, Q2;
  unordered_set<ll> seen;

  Q.push(1);
  seen.insert(1);
  ll res = 1;

  while (true) {
    while (not Q.empty()) {
      ll u = Q.front();
      Q.pop();
      if (not seen.count(u + 1)) {
        seen.insert(u + 1);
        Q2.push(u + 1);
        if (u + 1 == n) return res + 1;
      }
      ll v = reverse(u);
      if (not seen.count(v)) {
        seen.insert(v);
        Q2.push(v);
        if (v == n) return res + 1;
      }
    }
    ++res;
    swap(Q2, Q);
  }

  return -1;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve_case() << endl;
  }
}
