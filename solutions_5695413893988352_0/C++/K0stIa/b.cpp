#include <assert.h>
#include <memory.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i, a, b) for (int _n(b), i(a); i < _n; i++)
#define rep(i, n) FOR(i, 0, n)
#define CL(a, v) memset((a), (v), sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;

/*** TEMPLATE CODE ENDS HERE */

void go(int d, const string &a, const string &b, string &A, string &B,
        int &best, string &besta, string &bestb) {
  if (d == a.size()) {
    int x = std::atoi(A.c_str());
    int y = std::atoi(B.c_str());
    if (abs(x - y) < best) {
      best = abs(x - y);
      besta = A;
      bestb = B;
    } else if (abs(x - y) == best) {
      if (A < besta) {
        besta = A;
        bestb = B;
      }
      if (A == besta) {
        bestb = min(bestb, B);
      }
    }
    return;
  }
  for (char c1 = '0'; c1 <= '9'; ++c1) {
    for (char c2 = '0'; c2 <= '9'; ++c2) {
      if (a[d] != '?' && a[d] != c1) continue;
      if (b[d] != '?' && b[d] != c2) continue;
      A[d] = c1;
      B[d] = c2;
      go(d + 1, a, b, A, B, best, besta, bestb);
    }
  }
}

pair<string, string> solve_stupid(const string &a, const string &b) {
  int n = (int)a.size();
  string A(n, '?');
  string B(n, '?');
  int best = INF;
  string besta, bestb;
  go(0, a, b, A, B, best, besta, bestb);
  return mp(besta, bestb);
}

void solve() {
  string a, b;
  cin >> a >> b;

  auto res = solve_stupid(a, b);
  cout << res.X << " " << res.Y;
  return;

  int n = (int)a.size();
  bool eq = true;
  bool exchanged = false;
  rep(i, n) {
    if (a[i] != '?' && b[i] != '?') {
      if (eq) {
        if (a[i] > b[i]) {
          swap(a, b);
          exchanged = true;
        }
      }
      eq &= a[i] == b[i];
    } else if (a[i] == '?' && b[i] == '?') {
      if (eq) {
        a[i] = b[i] = '0';
      } else {
        a[i] = '9';
        b[i] = '0';
      }
    } else if (a[i] == '?') {
      if (eq) {
        a[i] = b[i];
      } else {
        a[i] = '9';
      }
    } else {
      assert(b[i] == '?');
      if (eq) {
        b[i] = a[i];
      } else {
        b[i] = '0';
      }
    }
  }
  if (exchanged) {
    swap(a, b);
  }
  cout << a << " " << b;
  if (a != res.X || b != res.Y) {
    cout << "\nerror!!!\n";
    cout << a << " " << b << endl;
    cout << res.X << " " << res.Y << endl;
  }
}

int main() {
#ifdef LOCAL_HOST
  //  freopen("input.txt", "r", stdin);
  freopen("B-small-attempt1.in", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  FOR(tt, 1, T + 1) {
    cout << "Case #" << tt << ": ";
    solve();
    cout << endl;
  }

  return 0;
}
