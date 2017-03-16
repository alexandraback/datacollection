#include<bitset>
#include<iostream>

//constexpr size_t N = 6;
//constexpr size_t J = 3;
constexpr size_t N = 16;
constexpr size_t J = 50;
//constexpr size_t N = 32;
//constexpr size_t J = 500;

size_t baseConvert(std::bitset<N / 2> x, size_t base) {
  size_t total = 0;
  size_t factor = 1;
  for (size_t i = 0; i < N / 2; i++) {
    total += factor * x[i];
    factor *= base;
  }
  return total;
}

int main(void) {
  std::cout << "Case #1:" << std::endl;
  for (size_t j = 1; j <= J; j++) {
    std::bitset<N / 2> a(2*j + 1);
    std::bitset<N / 2> b = a;
    while (b.to_ulong() < (1 << (N / 2 - 1)) && b != 0) {
      b <<= 1; 
    }
    std::cout << b << a;
    for (size_t i = 2; i <= 10; ++i) {
      std::cout << " " << baseConvert(a,i);
    }
    std::cout << std::endl;
  }
  return 0;
}
