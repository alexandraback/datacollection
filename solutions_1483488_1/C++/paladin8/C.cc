#include <iostream>
using namespace std;

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int A, B; cin >> A >> B;
    int r = 0, p10 = 1;
    while (p10 <= B) p10 *= 10;
    for (int i = A; i <= B; i++) {
      int cur = ((i % 10) * p10 + i) / 10;
      while (cur != i) {
        if (cur > i && cur <= B) r++;
        cur = ((cur % 10) * p10 + cur) / 10;
      }
    }
    cout << "Case #" << c << ": " << r << endl;
  }
  return 0;
}
