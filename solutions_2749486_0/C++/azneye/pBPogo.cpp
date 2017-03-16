/*
 * Code Jam 2013 Round 1C B
 * File:   pBPogo.cpp
 * Author: Andy Y.F. Huang
 * Created on May 12, 2013, 6:33 AM
 */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <complex>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <valarray>
#include <vector>

#ifdef AZN
#include "Azn.cpp"
#endif

using namespace std;

namespace pBPogo {

struct Node {
  int x, y, s;

  Node(int x, int y, int s) : x(x), y(y), s(s) { }
} ;

#define pos(x) (x+100)
const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};
const char* DIR = "ENWS";
bool reach[201][201][211];
int prev[201][201][211];

void trace(int x, int y, int s) {
  if (s == 0) return;
  trace(x - s * DX[prev[x][y][s]], y - s * DY[prev[x][y][s]], s - 1);
  putchar(DIR[prev[x][y][s]]);
}

void solve(int test_num) {
  int x, y;
  scanf("%d %d", &x, &y);
  x += 100;
  y += 100;
  printf("Case #%d: ", test_num);
  for (int s = 0; ; s++) {
    if (reach[x][y][s]) {
      trace(x, y, s);
      putchar('\n');
      return;
    }
  }
  assert(false);
}

bool oob(int x, int y) {
  return abs(x) > 100 || abs(y) > 100;
}

void init() {
  memset(prev, -1, sizeof (prev));
  memset(reach, false, sizeof (reach));
  reach[pos(0)][pos(0)][0] = true;
  queue<Node> q;
  q.push(Node(0, 0, 0));
  for (; !q.empty(); q.pop()) {
    int x = q.front().x, y = q.front().y, s = q.front().s + 1;
    if (s >= 210) continue;
    //pln(x, y, s);
    for (int d = 0, nx, ny; d < 4; d++) {
      nx = x + DX[d] * s;
      ny = y + DY[d] * s;
      if (!oob(nx, ny) && !reach[pos(nx)][pos(ny)][s]) {
        reach[pos(nx)][pos(ny)][s] = true;
        prev[pos(nx)][pos(ny)][s] = d;
        q.push(Node(nx, ny, s));
      }
    }
  }
}

void solve() {
  #ifdef AZN
  freopen("inputB.in", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("azn.txt", "w", stderr);
  #endif
  init();
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++)
    solve(i);
}
}

int main() {
  pBPogo::solve();
  return 0;
}

