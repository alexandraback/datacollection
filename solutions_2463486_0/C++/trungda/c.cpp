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

ifstream fi("C-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("in");
ofstream fo("out");

int test;
int f[20000001];
long long a, b;
long long res;

void input();
void init();
void solve();
void output();

int main() {
  int ntest;
  fi >> ntest;
  init();
  for (test = 1; test <= ntest; test ++) {
    input();
    solve();
    output();
  }
  fi.close();
  fo.close();
  return 0;
}

bool isPalin(long long x) {
  long long y = 0;
  long long xx = x;
  while (xx > 0) {
    y = y * 10 + (xx % 10);
    xx = xx / 10;
  }
  return (x == y);
}

void init() {
  f[0] = 0;
  for (long long i = 1; i <= 10000000; i ++) {
    f[i] = f[i - 1];
    if (isPalin(i) && isPalin(i * i)) {
      f[i] = f[i] + 1;
    }
  }
}

void input() {
  //start code here
  fi >> a >> b;
  long long lo = floor(sqrt(a));
  if (lo * lo < a) lo ++;
  long long hi = floor(sqrt(b));
  if (hi * hi > b) hi --;
  res = f[hi] - f[lo - 1];
}

void solve() {
}

void output() {
  fo << "Case #" << test << ": " << res << endl;
}
