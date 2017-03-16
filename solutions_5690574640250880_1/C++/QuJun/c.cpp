#include <iostream>
#include <vector>
#include <memory>
#include <utility>

using namespace std;

const int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

inline int perimeter(int x, int y) {
  if (x == 1) return y;
  if (y == 1) return x;
  return 2 * (x + y) - 4;
}
inline int area(int x, int y) {return x * y;}

vector<pair<int, int>> gen_chain(int r, int c)
{
  vector<pair<int, int>> ret;
  for (int i = 0; i < c; i++) {
    ret.push_back(make_pair(0, i));
  }
  for (int i = 1; i < r; i++) {
    ret.push_back(make_pair(i, c - 1));
  }
  if (r > 1 && c > 1) {
    for (int i = c - 2; i >= 0; i--) {
      ret.push_back(make_pair(r - 1, i));
    }
    for (int i = r - 2; i > 0; i--) {
      ret.push_back(make_pair(i, 0));
    }
  }
  return ret;
}

pair<int, int> find_click(vector<vector<char>> grid)
{
  int r = grid.size(), c = grid[0].size();
  int cnt = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] == '.') {
        cnt++;
        grid[i][j] = '0';
        for (int k = 0; k < 8; k++) {
          int ni = i + dr[k], nj = j + dc[k];
          if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == '*') {
            grid[i][j]++;
          } 
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (grid[i][j] != '*' && grid[i][j] != '0') {
        bool has0 = false;
        for (int k = 0; k < 8; k++) {
          int ni = i + dr[k], nj = j + dc[k];
          if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == '0') {
            has0 = true;
            break;
          }
        }
        if (cnt > 1 && !has0) {
          return make_pair(-1, -1);
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c ; j++) {
      if (grid[i][j] == '0' || (cnt == 1 && grid[i][j] != '*')) {
        return make_pair(i, j);
      }
    }
  }
  return make_pair(-1, -1);
}

unique_ptr<vector<vector<char>>> gen_res(int orig_r, int orig_c, int r, int c, int m)
{
  unique_ptr<vector<vector<char>>> ret(new vector<vector<char>>(orig_r));
  for (int i = 0; i < orig_r; i++) {
    for (int j = 0; j < orig_c; j++) {
      (*ret)[i].push_back('.');
      if (i >= r || j >= c) {
        (*ret)[i][j] = '*';
      }
    }
  }
  auto chain = gen_chain(r, c);
  for (int i = 0; i < m; i++) {
    (*ret)[chain[i].first][chain[i].second] = '*';
  }
  for (int i = 0; i < chain.size(); i++) {
    auto click = find_click(vector<vector<char>>(*ret));
    if (click.first >= 0) {
      (*ret)[click.first][click.second] = 'c';
      return ret;
    }
    if (m == 0) {
      return nullptr;
    }
    (*ret)[chain[i].first][chain[i].second] = '.';
    int nxt = (i + m) % chain.size();
    (*ret)[chain[nxt].first][chain[nxt].second] = '*';
  }

  return nullptr;
}

bool solve(int r, int c, int m)
{
  if (r * c <= m) {
    return false;
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      int periphery = area(r, c) - area(i, j);
      if (periphery <= m && periphery + perimeter(i, j) >= m) {
        auto res = gen_res(r, c, i, j, m - periphery);
        if (res) {
          for (int res_i = 0; res_i < r; res_i++) {
            for (int res_j = 0; res_j < c; res_j++) {
              cout << (*res)[res_i][res_j];
            }
            cout << endl;
          }
          return true;
        }
      }
    }
  }
  return false;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
  int test;
  cin >> test;
  for (int t = 1; t <= test; t++) {
    int r, c, m;
    cin >> r >> c >> m;
    cout << "Case #" << t << ":" << endl;
    if (!solve(r, c, m)) {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}
