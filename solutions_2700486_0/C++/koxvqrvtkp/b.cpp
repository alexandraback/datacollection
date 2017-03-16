#include <iostream>
#include <map>
#include <cmath>
#include <set>

using namespace std;

const int max_n = 20;
map<pair<int, int>, int> cnt[max_n + 1];

int main() {
  //int n_simulations = 10;
  int n_simulations = 60 * 30 * 145000;//;00000000000;
  int pct = 1;
  for (int simulation = 1; simulation <= n_simulations; ++simulation) {
    if ((100 / pct) * simulation >= (n_simulations)) {
      cerr << pct << " pct" << endl;
      ++pct;
    }
    set<pair<int, int> > S;
    int y_max = 0;
    for (int i = 1; i <= max_n; ++i) {
      int x = 0;
      int y = y_max;
      while (y > 0) {
        bool left, right;
        left = S.find(make_pair(x - 1, y - 1)) == S.end();
        right = S.find(make_pair(x + 1, y - 1)) == S.end();
        if (!left && !right) {
          break;
        } else if (left && !right) {
          --x, --y;
        } else if (right && !left) {
          ++x, --y;
        } else {
          if (rand() % 2 == 0) {
            --x, --y;
          } else {
            ++x, --y;
          }
        }
      }
      S.insert(make_pair(x, y));
      if (x == 0) {
        y_max = y + 2;
      }
      for (int j = i; j <= max_n; ++j) {
        ++cnt[j][make_pair(x, y)];
      }
    }
  }
  cerr << "done" << endl;
  int n_tests;
  scanf("%d", &n_tests);
  for (int test = 1; test <= n_tests; ++test) {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    double ans = (1.0 * cnt[n][make_pair(x, y)]) / n_simulations;
    printf("Case #%d: %.8lf\n", test, ans);
  }
  return 0;
}
