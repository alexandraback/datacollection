// Copyright 2016 Aleksandr Mikhailov

#include <bits/stdc++.h>

std::vector<int> MergeOddWithEven(
    const std::vector<int> & odd,
    const std::vector<int> & even) {
  std::vector<int> result;
  for (int i = 0; i < 32; ++i) {
    if (i % 2) {
      result.push_back(odd[i / 2]);
    } else {
      result.push_back(even[i / 2]);
    }
  }
  return result;
}

void PrintBinary(const std::vector<int> & binary) {
  for (int elem : binary) {
    std::cout << elem;
  }
  std::cout << " ";
}

void PrintIntVector(const std::vector<int> & vector) {
  for (int elem : vector) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

std::vector<int> GenNextNumber(
    std::vector<int> & odd,
    std::vector<int> & even) {
  if (!std::next_permutation(odd.begin(), odd.end() - 1)) {
    std::next_permutation(even.begin(), even.end());
  }
  return MergeOddWithEven(odd, even);
}

void SolveC() {
  std::vector<int> odd(16);
  std::vector<int> even(16);
  even[0] = 1;
  for (int i = 11; i < 16; ++i) {
    even[i] = 1;
  }
  for (int i = 10; i < 16; ++i) {
    odd[i] = 1;
  }
  std::vector<int> divs(9);
  std::iota(divs.begin(), divs.end(), 3);
  std::cout << "Case #1:" << std::endl;
  for (int i = 0; i < 500; ++i) {
    const std::vector<int> number = GenNextNumber(odd, even);
    PrintBinary(number);
    PrintIntVector(divs);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  SolveC();
  return 0;
}

