#include <iostream>
#include <vector>
#include <set>

using namespace std;

#define FILENAME "A-small-attempt0.in"

int count (int n) {
  set<int> digits;
  for (int i = 1; i <= 100; ++i) {
    int value = i * n;
    while (value) {
      digits.insert(value % 10);
      value /= 10;
    }
    if (digits.size() == 10) return i;
  }
  return -1;
}

int main() {
  freopen(FILENAME, "r", stdin); freopen("output.txt", "w", stdout);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    int n;
    cin >> n;
    if (n) cout << n * count(n) << endl;
    else cout << "INSOMNIA" << endl;
  }
  return 0;
}