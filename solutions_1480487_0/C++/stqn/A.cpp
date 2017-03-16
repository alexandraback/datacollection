#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

double solve(vector<int> &s, int k, int X) {

  double l = 0.0;
  double r = 1.0;
  for (int _ = 0; _ < 79; ++_) {
    double m = (l + r) / 2.0;
    double foo = s[k] + X * m;
    double bar = 0.0;
    for (int i = 0; i < s.size(); ++i) {
      if (i == k) continue;
      bar += max(0.0, foo - s[i]);
    }
    if (bar < X * (1.0 - m)) l = m;
    else r = m;
  }
  return r;

}

int main() {

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<int> s(N);
    for (int i = 0; i < N; ++i) {
      cin >> s[i];
    }
    int X = accumulate(s.begin(), s.end(), 0);
    cout << "Case #" << t << ':';
    for (int i = 0; i < N; ++i) {
      printf(" %.6lf", 100.0 * solve(s, i, X));
    }
    cout << endl;
  }

  return 0;

}
