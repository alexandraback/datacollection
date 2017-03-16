#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

const int PRIME_LIMIT = 1e+6;
vector<unsigned long long> primes;

void getPrimes(unsigned long long limit) {
  vector<bool> mark(limit + 1, false);
  for (unsigned long long i = 2; i < limit; i++) {
    if (!mark[i]) {
      primes.push_back(i);
      for (int j = i + i; j < limit; j += i) {
        mark[j] = true;
      }
    }
  }
}

bool greater_than(long long num, long long base, long long cmp_num) {
  long long p = 1, cur = 0;
  while (num > 0) {
    if (p > cmp_num) return true;
    if (num % 2) {
      cur += p;
    }
    num /= 2;
    p *= base;
  }
  return cur > cmp_num;
}

int main() {
  getPrimes(PRIME_LIMIT);

  int L, NUM;
  cin >> L >> NUM;

  for (long long i = (1LL << (L-1)); i < (1LL << L) && NUM > 0; i++) {
    if ((i & 1) == 0) continue;

    bool good_number = true;
    vector<int> divsors(11, 0);
    for (long long k = 2; k <= 10; k++) {
      bool bj = false;
      for (long long prime : primes) {
        if (greater_than(i, k, prime)) {
          long long s = 0, t = 1;
          for (int l = 0; l < L; l++) {
            s = (s + ((i >> l) & 1) * t) % prime;
            t = (t * k) % prime;
          }
          if (s == 0) {
            divsors[k] = prime;
            break;
          }
        }
      }
      if (divsors[k] == 0) {
        good_number = false;
        break;
      }
    }
    if (good_number) {
      for (int j = L - 1; j >= 0; j --) cout << ((i >> j) & 1);
      for (int j = 2; j <= 10; j++) cout << ' ' << divsors[j];
      cout << endl;
      NUM--;
    }
  }
  return 0;
}