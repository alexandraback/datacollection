#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

#define debug(x) cerr << #x << "=" << x << endl
#define sz(c) ((int)(c).size())
#define pb push_back
#define mp make_pair
#define endl '\n'

typedef long long int64;

using namespace std;

const double eps = 1e-7;
const double inf = 1e9;

int fcmp(double a, double b) {
  if (abs(a - b) < eps) return 0;
  if (a - b < eps) return -1;
  return +1;
}

double enough(double t, double C, double F, double X) {
  double R = 2;
  while (fcmp(t, 0) > 0) {
    if (fcmp(X, R*t) <= 0) return true;
    t -= C/R;
    R += F;
  }
  return false;
}

void solve(int testcase) {
  debug(testcase);
  printf("Case #%d: ", testcase);
  double C, F, X;
  scanf("%lf %lf %lf", &C, &F, &X);
  double l = 0, r = 1e9;
  for (int iter = 0; iter <= 100; ++iter) {
    double m = (l + r) / 2;
    //debug(l); debug(m); debug(r); cerr << endl;
    if (!enough(m, C, F, X)) l = m; else r = m;
  }
  printf("%.10lf\n", l);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t)
    solve(t);
  return 0;
}
