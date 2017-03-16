#include <cstdlib>
#include <iostream>
#include <tr1/memory>
#include <vector>
#include <map>
#include <algorithm>

bool check (unsigned long long number) {

  std::vector<char> buffer;
  while (number) {
    buffer.push_back(number % 10);
    number /= 10;
  }
  for (unsigned int i = 0, l = buffer.size(); i < (l >> 1); ++i) {
    if (buffer[i] != buffer[l - i - 1]) {
      return false;
    }
  }
  return true;
}

int main (int argc, char** argv) {

  int T;
  std::cin >> T;

  //unsigned long long limit = 34ull;
  unsigned long long limit = 33333334ull;
  //std::cout << limit * limit << std::endl;
  std::vector<unsigned long long> palindromes;
  for (unsigned long long i = 1; i < limit; ++i) {
    if (check(i)) {
      unsigned long long number = i * i;
      if (check(number)) {
        palindromes.push_back(number);
        //std::cout << i << ": " << number << std::endl;
      }
    }
  }

  std::sort(palindromes.begin(), palindromes.end());

  for (unsigned int t = 0; t < T; ++t) {
    unsigned long long A, B;
    std::cin >> A >> B;
    std::vector<unsigned long long>::const_iterator low, up;
    low = std::lower_bound(palindromes.begin(), palindromes.end(), A);
    up = std::upper_bound(palindromes.begin(), palindromes.end(), B);
    std::cout << "Case #" << t + 1 << ": ";
    std::cout << up - low << std::endl;
  }

  return EXIT_SUCCESS;
}

