/**
 * Jerry Ma
 * C.cpp
 */

#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <complex>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<int, lli> pil;
typedef pair<lli, int> pli;
typedef pair<lli, lli> pll;

int gInt () {
  int i;
  scanf("%d", &i);
  return i;
}

lli gLong () {
  lli i;
  scanf("%lld", &i);
  return i;
}

double gDouble () {
  double i;
  scanf("%lf", &i);
  return i;
}

void quit () {
  fflush(stdout);
  exit(0);
}

int n;
std::unordered_map<std::string, int> m1, m2;
char buf1[25], buf2[25];
pii edges[1005];

int getId(std::unordered_map<std::string, int>& m, const std::string& s) {
  if (m.count(s)) {
    return m[s];
  }
  return m[s] = m.size();
}

unordered_map<int, int> flows[2005];

bool visited[2005];
int bt[2005];

int fs(int node, int capacity, int depth=0) {
  if (visited[node]) {
    return 0;
  }
  bt[depth] = node;
  if (node == 2001) {
    return capacity;
  }
  visited[node] = true;
  for (const auto& edge : flows[node]) {
    int nc = min(capacity, edge.second);
    if (nc < 1) {
      continue;
    }
    int nf = fs(edge.first, nc, depth + 1);
    if (nf > 0) {
      return nf;
    }
  }
  return 0;
}

int mf () {
  int total = 0;
  while (true) {
    memset(visited, 0, sizeof(visited));
    memset(bt, 0, sizeof(bt));
    int f = fs(2000, 10000);
    if (f < 1) {
      break;
    }
    int prev = bt[0], cur = bt[1];
    int i = 2;
    while (prev != 2001) {
      flows[prev][cur] -= f;
      flows[cur][prev] += f;
      prev = cur;
      cur = bt[i ++];
    }
    total += f;
  }
  return total;
}

int solve () {
  m1.clear();
  m2.clear();
  n = gInt();
  for (int i = 0; i < n; ++i) {
    scanf("%s %s", buf1, buf2);
    std::string s1(buf1), s2(buf2);
    int id1 = getId(m1, s1);
    int id2 = getId(m2, s2);
    edges[i].first = id1;
    edges[i].second = id2;
    fprintf(stderr, "%d %d\n", id1, id2);
  }
  for (int i = 0; i < 2005; ++i) {
    flows[i].clear();
  }
  for (int i = 0; i < m1.size(); ++i) {
    flows[2000][i] = 1;
    flows[i][2000] = 0;
  }
  for (int i = 0; i < m2.size(); ++i) {
    flows[2001][i + 1000] = 0;
    flows[i + 1000][2001] = 1;
  }
  for (int i = 0; i < n; ++i) {
    int a = edges[i].first, b = edges[i].second + 1000;
    flows[a][b] = 1;
    flows[b][a] = 0;
  }
  int flow = mf();
  int minCover = m1.size() + m2.size() - flow;
  return n - minCover;
}

int main (int argc, char ** argv) {
  int nC = gInt();
  for (int i = 0; i < nC; ++i)
    printf("Case #%d: %d\n", i + 1, solve());
  quit();
}
