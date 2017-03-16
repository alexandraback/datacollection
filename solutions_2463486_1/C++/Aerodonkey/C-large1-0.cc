#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <math.h>

bool IsPalindrome(long long n) {
  std::ostringstream oss;
  oss << n;
  std::string str = oss.str();
  std::string::size_type len = str.length();
  for (std::string::size_type i = 0; i < len / 2; i++) {
    if (str[i] != str[len - 1 - i]) {
      return false;
    }
  }
  return true;
}

std::vector<long long> ComputeFairAndSquareNumbers(long long right) {
  std::vector<long long> fsns;
  for (long long n = 1; n * n <= right; n++) {
    if (IsPalindrome(n) && IsPalindrome(n * n)) {
      fsns.push_back(n * n);
    }
  }
  return fsns;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int numCases;
  std::cin >> numCases;
  std::vector<long long> fsns = ComputeFairAndSquareNumbers(100000000000000LL);
  for (int caseNum = 1; caseNum <= numCases; caseNum++) {
    long long left, right;
    std::cin >> left >> right;
    std::vector<long long>::size_type leftIndex = std::lower_bound(fsns.begin(), fsns.end(), left) - fsns.begin();
    std::vector<long long>::size_type rightIndex = std::upper_bound(fsns.begin(), fsns.end(), right) - fsns.begin();
    long long number = static_cast<long long>(rightIndex - leftIndex);
    std::cout << "Case #" << caseNum << ": " << number << std::endl;
  }
}
