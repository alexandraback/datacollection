#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <iterator>
#include <utility>
#include <cmath>
#include <complex>

using namespace std;

typedef long long int LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VP;

const double EPS = 1E-8;

bool elim(int a, int n, const VI &scores, int total, double m) {
  double target = scores[a] + m*total;
  double used = 0;
  for (int i = 0; i < n; ++i)
    if ((i != a) && (target > scores[i]))
      used += (target - scores[i]) / total;
  return (used + m) < 1;
  }

double minPercent(int a, int n, const VI &scores, int total) {
  if (!elim(a, n, scores, total, 0))
    return 0;

  double lo = 0, hi = 1;
  while (hi - lo > EPS) {
    double m = (hi + lo) / 2;
    if (elim(a, n, scores, total, m))
      lo = m;
    else
      hi = m;
    }
  return 100*hi;
  }

int main() {
  cout << fixed << setprecision(7);
  int nc; cin >> nc;
  for (int cur = 1; cur <= nc; ++cur) {
    int n; cin >> n;

    VI scores(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
      cin >> scores[i];
      total += scores[i];
      }

    cout << "Case #" << cur << ':';
    for (int i = 0; i < n; ++i)
      cout << ' ' << minPercent(i, n, scores, total);
    cout << '\n';
    }
  }

