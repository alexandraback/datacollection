#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int n, sum;
vector<int> point;
const double EPS = 1e-11;

int test(double prob, int k)
{
  double res = point[k] + prob * sum;
  double remains = 1 - prob;
  for (int i = 0; i < n; ++i) {
    if (i == k) continue;
    if (point[i] >= res) {
      continue;
    }
    remains -= (res - point[i]) / sum;
  }
  if (remains < 0) return -1;
  else return 1;
}

void solve()
{
  cin >> n;
  point.resize(n);
  sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> point[i];
    sum += point[i];
  }
  for (int i = 0; i < n; ++i) {
    double L = 0, R = 1, mid;
    while (R - L > EPS) {
      mid = (L + R) / 2;
      int succ = test(mid, i);
      if (succ < 0)
        R = mid;
      else
        L = mid;
    }
    printf("%.8lf ", mid * 100);
  }
  printf("\n");
}

int main()
{
  int T;
  cin >> T;
  for (int test = 0; test < T; ++test) {
    printf("Case #%d: ", test + 1);
    solve();
  }
  return 0;
}
