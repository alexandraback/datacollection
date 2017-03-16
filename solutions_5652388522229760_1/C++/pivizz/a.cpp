#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void addDigits(uint64_t n, int& digits) {
  while (n != 0) {
    digits |= (1 << (n % 10));
    n = n / 10;
  }
}

string solve(uint64_t n) {
  if (n == 0) return "INSOMNIA"; 
  int digits = 0;
  auto x = n;
  while(1) {
    addDigits(n, digits);
    if (digits == (1 << 10) - 1) {
      stringstream ss;
      ss << n;
      return ss.str();
    }
    n += x;
  }
}

int main(int argc, char* argv[]) {
  uint64_t T;
  fstream f(argv[1]);
  f >> T;
  for (int i = 0; i < T; i++) {
    uint64_t n;
    f >> n;
    cout << "Case #" << (i+1) << ": " << solve(n) << endl;
  } 
  return 0;
}
