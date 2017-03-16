#include <iostream>
#include <string>

using namespace std;

#define FILENAME "D-small-attempt0.in"

int main() {
  freopen(FILENAME, "r", stdin); freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    int k, c, s;
    cin >> k >> c >> s;
    cout << "Case #" << i << ": ";
    for (int j = 1; j <= k; ++j) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}