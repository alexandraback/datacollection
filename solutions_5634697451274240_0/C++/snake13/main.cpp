#include <iostream>
#include <string>

using namespace std;

#define FILENAME "B-small-attempt0.in"

int fast_solution (string s) {
  int count = 0, n = s.size();
  string target(n, '+');
  while (s != target) {
    int pos = -1;
    for (int i = 0; i < n - 1; ++i) {
      if (s[i] != s[i + 1]) {
        pos = i;
        break;
      }
    }
    if (pos == -1) pos = n - 1;
    for (int i = 0; i <= pos; ++i) {
      s[i] = (s[i] == '+' ? '-' : '+');
    }
    ++count;
  }
  return count;
}

int main() {
  freopen(FILENAME, "r", stdin); freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    string s;
    cin >> s;
    cout << "Case #" << i << ": " << fast_solution(s) << endl;
  }
  return 0;
}