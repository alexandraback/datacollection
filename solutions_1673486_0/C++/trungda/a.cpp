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

ifstream fi("A-small-attempt0.in");
//ifstream fi("A-large.in");
//ifstream fi("A-small-practice.in");
//ifstream fi("sample.in");
ofstream fo("sample.out");

int test;
int a, b;
double correct[100001];
double p[100001];

void solve();

int main() {
  int ntest;
  fi >> ntest;
  //  cout << ntest << endl;
  for (test = 1; test <= ntest; test ++) {
    solve();
  }
  fi.close();
  fo.close();
  return 0;
}

void solve() {
  //start code here
  fi >> a >> b;
  correct[0] = 1;
  for (int i = 1; i <= a; i ++) {
    fi >> p[i];
    correct[i] = correct[i - 1] * p[i];
  }
  double keeptyping = (correct[a] * (b - a + 1)) + (1 - correct[a]) * (b - a + b + 2);
  double enter = 1 + b + 1;
  double res = min(enter, keeptyping);
  for (int i = 1; i <= a; i ++) {
    double t = correct[a - i] * (b - a + i + i + 1) + (1 - correct[a - i]) * (2 * b - a + i + 2 + i);
    //    cout << i << " " << t << endl;
    res = min(res, t);
  }
  printf("Case #%d: %.7lf\n", test, res);
}
