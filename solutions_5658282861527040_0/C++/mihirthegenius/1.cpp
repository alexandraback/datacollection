#include <iostream>
#include <vector>
typedef std::vector<bool> VB;

VB get_vector(unsigned int x) {
  VB result;
  for (; x > 0; x = x / 2) result.push_back((x % 2) > 0);
  for (; result.size() < 32; result.push_back(false));
  return result;
}

int main() {
  unsigned int T; std::cin >> T;
  for (unsigned int test_case(1); test_case <= T; ++test_case) {
    unsigned int A, B, K, result(0); std::cin >> A >> B >> K;
    for (unsigned int i1(0); i1 < A; ++i1) {
      VB A_vector = get_vector(i1);
      for (unsigned int i2(0); i2 < B; ++i2) {
        VB B_vector = get_vector(i2);
        unsigned int winning(0);
        for (unsigned int i3(32); i3 >= 1; --i3)
          winning += winning + (A_vector[i3 - 1] && B_vector[i3 - 1] ? 1 : 0);
        result += (winning < K) ? 1 : 0;
      }

    }

    std::cout << "Case #" << test_case << ": " << result << std::endl;
  }

  return 0;
}
