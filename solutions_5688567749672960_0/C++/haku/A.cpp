#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <list>
#include <iterator>
#include <functional>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pnt;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FILE ""

const int INF = 1000 * 1000 * 1000 + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const ld EPS = 1e-9;

const int N = 1000 * 1000 + 5;
int d[N];

int rev(int x) {
  int y = 0;
  while (x > 0) {
    y = 10 * y + x % 10;
    x /= 10;
  }
  return y;
}

int main() {
#ifdef HOME
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  //freopen(FILE ".in", "r", stdin);
  //freopen(FILE ".out", "w", stdout);
#endif
  ios_base::sync_with_stdio(false);
  int ts;
  cin >> ts;
  for (int ti = 0; ti < ts; ++ti) {
    int n;
    cin >> n;
    queue<int> q;
    q.push(1);
    memset(d, 255, sizeof d);
    d[1] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      int u = v + 1;
      if (u < N && d[u] == -1) {
        d[u] = d[v] + 1;
        q.push(u);
      }
      u = rev(v);
      if (u < N && d[u] == -1) {
        d[u] = d[v] + 1;
        q.push(u);
      }
    }
    cout << "Case #" << ti + 1 << ": " << d[n] + 1 << '\n';
  }
  return 0;
}
