#include <iostream>
#include <set>

int main() {
  int T;
  std::cin >> T;
  for (int x = 1; x <= T; x++) {
    int A, B;
    std::cin >> A >> B;
    int p = 1;
    int l = 0;
    for (; p * 10 <= A; p *= 10, l++);
    int y = 0;
    for (int n = A; n < B; n++) {
      std::set<int> S;
      int m = n;
      for (int i = 0; i < l; i++) {
        m = m / 10 + m % 10 * p;
        if (n < m && m <= B) {
          S.insert(m);
        }
      }
      y += S.size();
    }
    std::cout << "Case #" << x << ": " << y << std::endl;
  }
}
