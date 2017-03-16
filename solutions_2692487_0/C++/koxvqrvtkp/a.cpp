#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int A, n;
vector<int> x;
map<pair<int, int>, int> M;
int A_MAX = 1000000 + 1;

int solve(int A, int pos) {
  if (M.find(make_pair(A, pos)) != M.end()) {
    return M[make_pair(A, pos)];
  }
  if (pos == n) {
    return M[make_pair(A, pos)] = 0;
  }
  if (A > x[pos]) {
    return M[make_pair(A, pos)] = solve(min(A + x[pos], A_MAX), pos + 1);
  }
  if (A == 1) {
    return M[make_pair(A, pos)] = (n - 1) - pos + 1;
  }
  return M[make_pair(A, pos)] = min((n - 1) - pos + 1,
      1 + solve(min(2 * A - 1, A_MAX), pos));
}

int main() {
  int n_tests;
  scanf("%d", &n_tests);
  for (int test = 1; test <= n_tests; ++test) {
    scanf("%d %d", &A, &n);
    x = vector<int>(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &x[i]);
    }
    sort(x.begin(), x.end());
    M.clear();
    printf("Case #%d: %d\n", test, solve(A, 0));
  }
  return 0;
}
