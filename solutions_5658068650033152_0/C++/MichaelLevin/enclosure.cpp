#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "C"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

int GetEnclosed(const vvi& field) {
  queue<pii> q;
  vvi done(field.size(), vi(field[0].size(), 0));
  for (int row = 0; row < field.size(); ++row) {
    q.push(MP(row, 0));
    done[row][0] = true;
    q.push(MP(row, field[0].size() - 1));
    done[row][field[0].size() - 1] = true;
  }
  for (int col = 0; col < field[0].size(); ++col) {
    q.push(MP(0, col));
    done[0][col] = true;
    q.push(MP(field.size() - 1, col));
    done[field.size() - 1][col] = true;
  }
  int result = (field.size() - 2) * (field[0].size() - 2);
  while (!q.empty()) {
    pii cur = q.front();
    q.pop();
    for (int dx = -1; dx <= 1; ++dx) {
      for (int dy = -1; dy <= 1; ++dy) {
        if (abs(dx) + abs(dy) == 1) {
          pii nxt(cur.first + dx, cur.second + dy);
          if (nxt.first >= 0 && nxt.first < field.size() && nxt.second >= 0 && nxt.second < field[0].size()) {
            if (!done[nxt.first][nxt.second] && field[nxt.first][nxt.second] == 0) {
              q.push(nxt);
              done[nxt.first][nxt.second] = true;
              --result;
            }
          }
        }
      }
    }
  }
  return result;
}

int GetMinBorderStupid(int n, int m, int k, map<pii, map<int, int> >& cache) {
  pii key = MP(n, m);
  if (cache.count(key)) {
    return cache[key][k];
  }
  int N = n * m;
  for (int mask = 0; mask < (1 << N); ++mask) {
    vvi field(n + 2, vi(m + 2));
    int index = 0;
    int border_points = 0;
    for (int row = 0; row < n; ++row) {
      for (int col = 0; col < m; ++col) {
        if ((mask >> index) & 1) {
          field[row + 1][col + 1] = 1;
          ++border_points;
        }
        ++index;
      }
    }
    if (mask % 1000 == 0) {
      cerr << n << ' ' << m << ' ' << mask << endl;
    }
    int enclosed = GetEnclosed(field);
    if (cache[key][enclosed] == 0 || cache[key][enclosed] > border_points) {
      cache[key][enclosed] = border_points;
    }
  }
  return cache[key][k];
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  map<pii, map<int, int> > cache;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n > m) {
      swap(n, m);
    }
    cout << "Case #" << (test_index + 1) << ": ";
    int result = GetMinBorderStupid(n, m, k, cache);
    cout << result << endl;
  }
  return 0;
}
