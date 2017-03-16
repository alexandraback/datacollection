#include <iostream>
#include <vector>
typedef std::vector<unsigned long long int> VU;
VU powers_of_two(1, 1);

int main () {
  while (powers_of_two.size() <= 40)
    powers_of_two.push_back(2 * (*(powers_of_two.rbegin())));
  unsigned long long int T; std::cin >> T;
  for (unsigned long long int test_case(1); test_case <= T; ++test_case) {
    unsigned long long int P, Q; {char c; std::cin >> P >> c >> Q;}
    unsigned long long int twos_in_Q(0);
    while (Q % 2 <= 0) {Q /= 2; ++twos_in_Q;}
    if (P % Q > 0)
      std::cout << "Case #" << test_case << ": impossible" << std::endl;
    else {
      P /= Q; Q = powers_of_two[twos_in_Q];
      unsigned long long int i1; for (i1 = 0; 2 * powers_of_two[i1] <= P; ++i1);
      
      std::cout << "Case #" << test_case << ": " << (twos_in_Q - i1) << std::endl;
    }
  }

  return 0;
}
