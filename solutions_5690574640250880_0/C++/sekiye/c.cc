#include <iostream>
#include <algorithm>
#include <array>
#include <climits>
#include <cmath>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

typedef long long          ll;
typedef unsigned int       uint;
typedef unsigned long long ull;

using namespace std;

ostream& operator<<(ostream &s, vector<string> v)
{
  int cnt = v.size();
  s << "[ ";
  for (int i=0; i<cnt; i++) {
	if (i > 0) s << ", ";
	s << '"' << v[i] << '"';
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, vector<T> v)
{
  int cnt = v.size();
  s << "[ ";
  for (int i=0; i<cnt; i++) {
	if (i > 0) s << ", ";
	s << v[i];
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, list<T> ls)
{
  int cnt = 0;
  s << "( ";
  for (auto it=ls.begin(); it!=ls.end(); it++) {
	if (it != it.begin()) s << ", ";
	s << *it;
	cnt++;
  }
  return s << " )  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, deque<T> st)
{
  int cnt = st.size();
  s << "[ ";
  for (auto it=st.begin(); it!=st.end(); it++) {
	if (it != st.begin()) s << ", ";
	s << *it;
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T1, typename T2> ostream& operator<<(ostream &s, map<T1,T2> m)
{
  int cnt = m.size();
  s << "{ ";
  for (auto it=m.begin(); it!=m.end(); it++) {
	if (it != m.begin()) s << ", ";
	s << it->first << " => " << it->second;
  }
  return s << " }  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T> ostream& operator<<(ostream &s, set<T> st)
{
  int cnt = st.size();
  s << "[ ";
  for (auto it=st.begin(); it!=st.end(); it++) {
	if (it != st.begin()) s << ", ";
	s << *it;
  }
  return s << " ]  // " << cnt << " item" << (cnt >= 2 ? "s" : "");
}

template <typename T1, typename T2> ostream& operator<<(ostream &s, pair<T1,T2> p)
{
  return s << "(" << p.first << "," << p.second << ")";
}

int R;
int C;
int M;
char grid[51][51];
char grid2[51][51];

void PrintGrid() {
  grid[0][0] = 'c';
  for (int y = 0; y < R; y++) {
    string a = "";
    for (int x = 0; x < C; x++) {
      a += grid[y][x];
    }
    std::cout << a << std::endl;
  }
}

void PrintGrid2() {
  for (int y = 0; y < R; y++) {
    string a = "";
    for (int x = 0; x < C; x++) {
      a += grid2[y][x];
    }
    std::cout << a << std::endl;
  }
}

void Solve1() {
  if (M == 0 || R * C >= M + 2) {
    for (int n = 0; n < R * C - M; n++) {
      grid[n / C][n % C] = '.';
    }
    PrintGrid();
  } else {
    printf("Impossible\n");
  }
}

void MakeSqure(int x, int y) {
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      grid[i][j] = '.';
    }
  }
}

void SolveN() {
  const int n = R * C - M;
  for (int i = 2; i <= R; i++) {
    for (int j = 2; j <= C; j++) {
      if (i * j == n) {
        MakeSqure(i, j);
        PrintGrid();
        return;
      }
    }
  }
  for (int i = 3; i <= R; i++) {
    for (int j = 3; j <= C; j++) {
      if ((i - 1) * j + 2 <= n && n <= i * j) {
        MakeSqure(i - 1, j);
        int m = n - (i - 1) * j;
        for (int k = 0; k < m; k++) {
          grid[i - 1][k] = '.';
        }
        PrintGrid();
        return;
      }
      if (i * (j - 1) + 2 <= n && n <= i * j) {
        MakeSqure(i, j - 1);
        int m = n - i * (j - 1);
        for (int k = 0; k < m; k++) {
          grid[k][j - 1] = '.';
        }
        PrintGrid();
        return;
      }
      if (j >= 4 && (i - 1) * j + 1 == n) {
        MakeSqure(i - 1, j);
        int m = n - (i - 1) * j + 1;
        for (int k = 0; k < m; k++) {
          grid[i - 1][k] = '.';
        }
        grid[i - 2][j - 1] = '*';
        PrintGrid();
        return;
      }
      if (i >= 4 && i * (j - 1) + 1 == n) {
        MakeSqure(i, j - 1);
        int m = n - i * (j - 1) + 1;
        for (int k = 0; k < m; k++) {
          grid[k][j - 1] = '.';
        }
        grid[i - 1][j - 2] = '*';
        PrintGrid();
        return;
      }
    }
  }
  printf("Impossible\n");
}

void Solve() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      grid[i][j] = '*';
    }
  }
  if (R * C == M + 1) {
    grid[0][0] = 'c';
    PrintGrid();
  } else if (R == 1 || C == 1) {
    Solve1();
  } else {
    SolveN();
  }
}

void Solve2() {
  for (int i = 0; i < 1 << (R * C); i++) {
    int count = 0;
    for (int j = 0; j < R * C; j++) {
      if (i & 1 << j) {
        count++;
      }
    }
    if (count != M) {
      continue;
    }
    for (int j = 0; j < R * C; j++) {
      if (i & 1 << j) {
        grid[j / C][j % C] = '*';
        grid2[j / C][j % C] = '*';
      } else {
        grid[j / C][j % C] = '.';
        grid2[j / C][j % C] = '.';
      }
    }
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (grid[y][x] == '*') continue;
        int count = 0;
        for (int vy = -1; vy <= 1; vy++) {
          for (int vx = -1; vx <= 1; vx++) {
            if (vx == 0 && vy == 0)
              continue;
            if (0 <= x + vx && x + vx < C &&
                0 <= y + vy && y + vy < R) {
              if (grid[y + vy][x + vx] == '*')
                count++;
            }
          }
        }
        grid[y][x] = '0' + count;
      }
    }
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (grid[y][x] == '*' || grid[y][x] == '0') continue;
        for (int vy = -1; vy <= 1; vy++) {
          for (int vx = -1; vx <= 1; vx++) {
            if (vx == 0 && vy == 0)
              continue;
            if (0 <= x + vx && x + vx < C &&
                0 <= y + vy && y + vy < R) {
              if (grid[y + vy][x + vx] == '0') {
                grid[y][x] = '!';
                break;
              }
            }
          }
        }
      }
    }
    int x0 = -1;
    int y0 = -1;
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (grid[y][x] == '0') {
          x0 = x;
          y0 = y;
          break;
        }
      }
    }
    queue<pair<int, int>> q;
    q.push(make_pair(x0, y0));
    while (!q.empty()) {
      auto p = q.front();
      q.pop();
      int x = p.first;
      int y = p.second;
      grid[y][x] = '#';
      for (int vy = -1; vy <= 1; vy++) {
        for (int vx = -1; vx <= 1; vx++) {
          if (0 <= x + vx && x + vx < C &&
              0 <= y + vy && y + vy < R) {
            if (grid[y + vy][x + vx] == '0') {
              q.push(make_pair(x + vx, y + vy));
            }
          }
        }
      }
    }
    bool good = false;
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (grid[y][x] == '#') {
          grid2[y][x] = 'c';
          good = true;
          goto end;
        }
      }
    }
 end:
    for (int y = 0; y < R; y++) {
      for (int x = 0; x < C; x++) {
        if (grid[y][x] == '*' || grid[y][x] == '!' || grid[y][x] == '#') continue;
        good = false;
      }
    }
    if (good) {
      PrintGrid2();
      return;
    }
  }
  printf("Impossible\n");
}

int NumberOfSetBits(int i) {
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

void MakeMap(int bit) {
  for (int k = 0; k < R * C; k++) {
    int x = k % C;
    int y = k / C;
    if (bit & 1 << k) {
      grid[y][x] = grid2[y][x] = '*';
    } else {
      grid[y][x] = grid2[y][x] = '.';
    }
  }
}

void SetNumber() {
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (grid2[y][x] == '.') {
        int count = 0;
        for (int vy = -1; vy <= 1; vy++) {
          for (int vx = -1; vx <= 1; vx++) {
            if (grid[y + vy][x + vx] == '*') {
              count++;
            }
          }
        }
        grid2[y][x] = '0' + count;
      }
    }
  }
}

void SetBoader() {
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (grid2[y][x] == '0') {
        for (int vy = -1; vy <= 1; vy++) {
          for (int vx = -1; vx <= 1; vx++) {
            if (grid2[y + vy][x + vx] != '0') {
              grid2[y + vy][x + vx] = '#';
            }
          }
        }
      }
    }
  }
}

void wfs() {
  int x0 = -1;
  int y0 = -1;
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (grid2[y][x] == '0') {
        x0 = x;
        y0 = y;
      }
    }
  }
  if (x0 == -1)
    return;
  queue<pair<int, int>> q;
  q.push(make_pair(x0, y0));
  while (!q.empty()) {
    auto p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    grid2[y][x] = 'o';
    for (int vy = -1; vy <= 1; vy++) {
      for (int vx = -1; vx <= 1; vx++) {
        if (0 <= x + vx && x + vx < C &&
            0 <= y + vy && y + vy < R) {
          if (grid2[y + vy][x + vx] == '0') {
            q.push(make_pair(x + vx, y + vy));
          }
        }
      }
    }
  }
}

bool hasZero() {
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (grid2[y][x] == 'o') {
        return true;
      }
    }
  }
  return false;
}

bool hasNumber() {
  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if ('0' <= grid2[y][x] && grid2[y][x] <= '8') {
        return true;
      }
    }
  }
  return false;
}

void Solve3() {
  for (int bit = (1 << (R * C)) - 1; bit >= 0 ; bit--) {
    if (NumberOfSetBits(bit) != M) continue;
    MakeMap(bit);
    SetNumber();
    SetBoader();
    wfs();
    if (hasZero() && !hasNumber()) {
      PrintGrid();
      return;
    }
  }
  printf("Impossible\n");
}

int main() {
  int T;
  cin >> T;
  for (int x = 0; x < T; x++) {
    printf("Case #%d:\n", x + 1);
    cin >> R >> C >> M;
    // Solve2();
    Solve();
    // Solve3();
  }
}
