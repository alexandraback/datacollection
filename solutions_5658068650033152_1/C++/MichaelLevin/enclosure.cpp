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

int GetMinBorderFast(int n, int m, int k) {
  if (k <= 4 || n <= 2) {
    return k;
  }
  int a, b;
  for (a = 1; a <= n; ++a) {
    if (2 * a + 1 > n) {
      --a;
      break;
    }
    b = a;
    if (2 * a * a + 2 * a + 1 >= k) {
      return 4 * a;
    }
    if (2 * a * a + 3 * a + 1 >= k) {
      return 4 * a + 1;
    }
    if (2 * a + 2 > n) {
      break;
    }
    b = a + 1;
    if (2 * a * a + 4 * a + 2 >= k) {
      return 4 * a + 2;
    }
    if (2 * a * a + 5 * a + 3 >= k) {
      return 4 * a + 3;
    }
  }
  int result = 2 * (a + b);
  int points = 2 * a * b + a + b + 1;
  for (int mid = 1; a + b + 1 + mid <= m; ++mid) {
    if (points + b >= k) {
      return result + 1;
    }
    result += 2;
    points += n;
    if (points >= k) {
      return result;
    }
  }
  multiset<int, greater<int> > borders;
  borders.insert(a);
  borders.insert(a);
  borders.insert(b);
  borders.insert(b);
  cerr << "start" << endl;
  while (!borders.empty()) {
    int largest = *borders.begin();
    cerr << largest << endl;
    borders.erase(borders.begin());
    result += 1;
    points += largest;
    if (points >= k) {
      return result;
    }
    if (largest - 1 > 0) {
      borders.insert(largest - 1);
    }
  }
  return -1;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  //map<pii, map<int, int> > cache;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int n, m, k;
    cin >> n >> m >> k;
    if (n > m) {
      swap(n, m);
    }
    cout << "Case #" << (test_index + 1) << ": ";
    int result = GetMinBorderFast(n, m, k);//GetMinBorderStupid(n, m, k, cache);
    cout << result << endl;
  }
  /*freopen(PROBLEM_ID".err", "w", stderr);
  for (map<pii, map<int, int> >::const_iterator it = cache.begin(); it != cache.end(); ++it) {
    cerr << "Results for n = " << it->first.first << ", m = " << it->first.second << ":" << endl;
    for (map<int, int>::const_iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
      cerr << it2->first << ' ' << it2->second << endl;
    }
  }*/
  return 0;
}
