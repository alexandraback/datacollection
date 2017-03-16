#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

struct grid {
  std::vector<std::vector<char>> arr;
  int R, C;

  grid() {}
  grid(int R, int C) : R(R), C(C) { arr = std::vector<std::vector<char>>(R,std::vector<char>(C,'*')); }

  void rot90() {
    std::vector<std::vector<char>> rot(C,std::vector<char>(R));
    for (int r = 0; r < R; ++r)
      for (int c = 0; c < C; ++c)
        rot[c][R - r - 1] = arr[r][c];
    arr = rot;
    std::swap(R,C);
  }

  friend std::ostream & operator<<(std::ostream &, const grid &);
};

std::ostream & operator<<(std::ostream &os, const grid &g)
{
  for (int r = 0; r < g.R; ++r) {
    for (int c = 0; c < g.C; ++c) {
      os << g.arr[r][c];
    }
    os << std::endl;
  }
  return os;
}

std::pair<bool,grid> solve_one(int R, int C, int empty)
{
  grid g(R,C);
  g.arr[0][0] = 'c';

  for (int c = 1; c < empty; ++c)
    g.arr[0][c] = '.';
  return std::make_pair(true,g);
}

std::pair<bool,grid> solve_two(int R, int C, int empty)
{
  grid g(R,C);
  if (empty == 1) {
    g.arr[0][0] = 'c';
    return std::make_pair(true,g);
  }

  if (empty < 4 || empty % 2 == 1)
    return std::make_pair(false,g);

  g.arr[0][0] = 'c';
  for (int c = 1; c < empty / 2; ++c)
    g.arr[0][c] = '.';
  for (int c = 0; c < empty / 2; ++c)
    g.arr[1][c] = '.';

  return std::make_pair(true,g);
}

std::pair<bool,grid> solve_three(int R, int C, int empty)
{
  grid g(R,C);
  if (empty == 1) {
    g.arr[0][0] = 'c';
    return std::make_pair(true,g);
  }

  if (empty < 4 || empty == 5 || empty == 7)
    return std::make_pair(false,g);

  if (empty == 4) {
    g.arr[0][0] = 'c';
    g.arr[0][1] = '.';
    g.arr[1][0] = '.';
    g.arr[1][1] = '.';
    return std::make_pair(true,g);
  }

  for (int r : {0,1,2}) {
    int bound = empty / 3;
    if (empty % 3 != 0) bound++;
    for (int c = 0; c < bound; ++c)
      g.arr[r][c] = '.';
  }

  g.arr[0][0] = 'c';

  if (empty % 3 == 1) {
    g.arr[2][empty / 3] = '*';
    g.arr[2][empty / 3 - 1] = '*';
  }

  else if (empty % 3 == 2) {
    g.arr[2][empty / 3] = '*';
  }

  return std::make_pair(true,g);
}

std::pair<bool,grid> solve_rest(int R, int C, int empty)
{
  grid g(R,C);
  if (empty == 1) {
    g.arr[0][0] = 'c';
    return std::make_pair(true,g);
  }

  for (int r = 4; ; ++r) {
    int c = 4;
    while (r*c < empty) c++;

    if (c > C) continue;

    for (int ri = 0; ri < r; ++ri)
      for (int ci = 0; ci < c; ++ci)
        g.arr[ri][ci] = '.';
    g.arr[0][0] = 'c';

    if (empty == r * (c - 1) + 1) {
      g.arr[r-1][c-2] = '*';
      for (int ri = 2; ri < r; ++ri)
        g.arr[ri][c-1] = '*';
    }
    else {
      for (int ri = r - (r*c - empty); ri < r; ++ri)
        g.arr[ri][c-1] = '*';
    }

    return std::make_pair(true,g);
  }
}

int main(int argc, char **argv)
{
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; ++t) {
    int R,C,M,empty;
    std::cin >> R >> C >> M;
    empty = R * C - M;

    std::cout << "Case #" << t << ":" << std::endl;

    std::pair<bool,grid> res;
    if (R == 1 || C == 1)
      res = solve_one(std::min(R,C),std::max(R,C),empty);
    else if (R == 2 || C == 2)
      res = solve_two(std::min(R,C),std::max(R,C),empty);
    else if (R == 3 || C == 3 || empty <= 12)
      res = solve_three(std::min(R,C),std::max(R,C),empty);
    else
      res = solve_rest(std::min(R,C),std::max(R,C),empty);

    if (res.first == false)
      std::cout << "Impossible" << std::endl;
    else {
      if (R > C)
        res.second.rot90();
      std::cout << res.second;
    }

  }
  return 0;
}
