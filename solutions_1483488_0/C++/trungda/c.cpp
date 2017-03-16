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
//ifstream fi("C-large.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;
int res;

bool recycle(int, int);
void smallsolve();
void solve();

int main() {
  int ntest;
  fi >> ntest;
  for (test = 1; test <= ntest; test ++) {
    smallsolve();
    fo << "Case #" << test << ": " << res << endl;
  }
  fi.close();
  fo.close();
  return 0;
}

bool recycle(int n, int m) {
  string xn = "";
  string xm = "";
  while (n > 0) {
    xn = char(n % 10 + '0') + xn;
    n = n / 10;
  }
  for (int i = 0; i < xn.length() - 1; i ++) {
    xm = "";
    for (int j = i + 1; j < xn.length(); j ++)
      xm = xm + xn[j];
    for (int j = 0; j <= i; j ++)
      xm = xm + xn[j];
    int mm = 0;
    for (int j = 0; j < xm.length(); j ++) {
      mm = mm * 10 + int(xm[j] - '0');
    }
    if (mm == m) return true;
  }
  return false;
}

void smallsolve() {
  long long a, b;
  res = 0;
  fi >> a >> b;
  for (int n = a; n <= b; n ++)
    for (int m = n + 1; m <= b; m ++)
      if (recycle(n, m)) res ++;
}

void solve() {
  //start code here
  
}
