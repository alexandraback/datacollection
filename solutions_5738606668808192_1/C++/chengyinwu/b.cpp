#include <iostream>
#include <cmath>

using namespace std;

uint64_t number(uint64_t n, uint64_t b) {
   uint64_t x = 0, ex = 1;
   while (n) {
      x += (ex * (n % 2));
      n = n >> 1; ex *= b;
   }
   return x;
}

uint64_t divide(uint64_t n) {
   uint64_t end = sqrt(n);
   for (uint64_t i = 2; i <= end; ++i) if (n % i == 0) return i;
   return 0;
}

bool check(uint64_t n) {
   uint64_t d[9];
   for (int i = 2; i <= 10; ++i) {
      uint64_t x = number(n, i);
      uint64_t v = divide(x);
      if (v) {
         //cout << number(n, 10) << " --> in base " << i << " = " << x << " will be divided by " << v
         //     << " : remainder = " << (x % v) << endl;
         d[i - 2] = v;
      }
      else {
         //cout << number(n, 10) << " --> in base " << i << " = " << x << " is a prime" << endl;
         return false;
      }
   }
   cout << number(n, 10) << number(n, 10);
   for (int i = 0; i < 9; ++i) cout << " " << d[i];
   cout << endl;
   return true;
}

void print(uint64_t N, uint64_t J) {
   uint64_t x, suffix = 1 << (N - 1), start = 0, end = 1 << (N - 2);
   //cout << "start = " << start << ", end = " << end << endl;
   while (start != end) {
      x = 1 + (start << 1) + suffix;
      //cout << "Consider " << number(x, 10) << endl;
      if (check(x)) { if (--J == 0) break; }
      ++start;
   }
   return;
}

int main() {
   uint64_t T; cin >> T;
   uint64_t N, J; cin >> N >> J;
   cout << "Case #1:" << endl;
   print(N >> 1, J);
   return 0;
}

