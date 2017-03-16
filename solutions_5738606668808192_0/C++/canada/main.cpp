#include <iostream>
#include <bitset>
#include <cstdint>

using namespace std;

int64_t expo(int64_t a, int64_t b){
  int64_t result = 1ll;

  while (b>0ll){
    result *= a;
    b--;
  }

  return result;
}

#define N 16

int main() {
  cout << "Case #1:\n";
  int64_t j = 50;
  for (int64_t i = 0; i < j; ++i) {
    int64_t u = (1ll << (N / 2ll)) + 1ll;
    u *= (1ll << (N / 2ll - 1ll)) + 1ll + (i << 1ll);

    bitset<N> t(u);
    cout << t;
    for (int base = 2; base <= 10; ++base) {
      cout << " " << (expo(base, N / 2) + 1LL);
    }
    cout << "\n";
  }
}
