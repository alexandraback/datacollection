#include <iostream>
#include <string>

using namespace std;

#define PROBLEM_ID "D"

string Solve(int x, int r, int c) {
  if (c * r % x) {
    return "RICHARD";
  }
  if (r < c) {
    swap(r, c);
  }
  if (x > r) {
    return "RICHARD";
  }
  if (x >= 2 * c + 1) {
    return "RICHARD";
  }
  if (x >= 7) {
    return "RICHARD";
  }
  if (x == 6 && c == 3) {
    return "RICHARD";
  }
  if (x == 4 && c == 2) {
    return "RICHARD";
  }
  return "GABRIEL";
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int x, r, c;
    cin >> x >> r >> c;
    string result = Solve(x, r, c);
    cout << "Case #" << (test_index + 1) << ": " << result << endl;
    cerr << "Case #" << (test_index + 1) << ": " << result << endl;
  }
  return 0;
}
