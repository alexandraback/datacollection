#include <iostream>

using namespace std;

#define FILL(a, val) memset(&a, val, sizeof(a))
bool mp[100][100];

bool oneWay(int& n, int& m, int& count, bool swapped) {
  if (m < 3) {
    return false;
  }
  while (n > 3 && count >= m) {
    count -= m;
    for (int i = 0; i < m; ++i) {
      if (swapped) {
        mp[i][n - 1] = true;
      } else {
        mp[n - 1][i] = true;
      }
    }
    --n;
  }
  if (n > 3) {
    for (int i = m - 1; i > 1 && count > 0; --i) {
      if (swapped) {
        mp[i][n - 1] = true;
      } else {
        mp[n - 1][i] = true;
      }
      --count;
    }
    if (count > 0) {
      if (swapped) {
        mp[m - 1][n - 2] = true;
      } else {
        mp[n - 2][m - 1] = true;
      }
    }
    return true;
  }
  return false;
}

bool solve(int n, int m, int count) {
  FILL(mp, 0);
  if (n * m - count == 2 && count > 0 && n > 1 && m > 1) {
    return false;
  }
  if (oneWay(n, m, count, false)) {
    return true;
  }
  if (oneWay(m, n, count, true)) {
    return true;
  }
  while (count > 0) {
    if (min(n, m) - count == 1) {
      return false;
    }
    if (n >= m) {
      for (int i = m - 1; i >= 0 && count > 0; --i) {
        mp[n - 1][i] = true;
        --count;
      }
      --n;
    } else {
      for (int i = n - 1; i >= 0 && count > 0; --i) {
        mp[i][m - 1] = true;
        --count;
      }
      --m;
    }
  }
  return true;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tc;
  cin >> tc;
  for (int i = 0; i < tc; ++i) {
    cout << "Case #" << i + 1 << ":" << endl;
    int n, m, count;
    cin >> n >> m >> count;
    //cout << n << " " << m << " " << count << endl;
    for (int it = 0; it < 1; ++it) {
    if (solve(n, m, count)) {
      for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
          if (x == 0 && y == 0) {
            cout << 'c';
          } else if (mp[x][y]) {
            cout << '*';
          } else {
            cout << '.';
          }
        }
        cout << endl;
      }
    } else {
      cout << "Impossible" << endl;
    }
    //cout << endl;
    swap(n, m);
    }
  }
  return 0;
}
