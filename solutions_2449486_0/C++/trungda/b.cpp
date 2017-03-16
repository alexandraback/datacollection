//this is the default for Google code jam only
#include <string>
#include <vector>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

#define pii pair<int, int>

using namespace std;

ifstream fi("B-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("in");
ofstream fo("out");

int test;
int m, n;
int a[100][100];
int r[100], c[100];
int res;

void input();
void solve();
void output();

int main() {
  int ntest;
  fi >> ntest;
  for (test = 1; test <= ntest; test ++) {
    input();
    solve();
    output();
  }
  fi.close();
  fo.close();
  return 0;
}

void input() {
  //start code here
  fi >> m >> n;
  for (int i = 0; i < m; i ++) r[i] = -1;
  for (int j = 0; j < n; j ++) c[j] = -1;
  for (int i = 0; i < m; i ++)
    for (int j = 0; j < n; j ++) {
      fi >> a[i][j];
      r[i] = max(r[i], a[i][j]);
      c[j] = max(c[j], a[i][j]);
    }
}

void solve() {
  res = 0;
  for (int i = 0; i < m; i ++)
    for (int j = 0; j < n; j ++) {
      if (a[i][j] != min(r[i], c[j])) {
	return;
      }
    }
  res = 1;
}

void output() {
  fo << "Case #" << test << ": ";
  if (res == 1) fo << "YES" << endl;
  else fo << "NO" << endl;
}
