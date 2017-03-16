#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int N = 16;
const int J = 50;

bool composite[100000001];
vector<long> small_primes;

void compute_small_primes() {
  small_primes.push_back(2);

  for (int i = 3; i < 100000001; i += 2) {
    if (!composite[i]) {
      small_primes.push_back(i);
      if (i < 10000) {
        for (int j = i*i; j < 100000001; j += i) {
          composite[j] = true;
        }
      }
    }
  }
}

long factor(long p) {
  for (size_t i = 0; i < small_primes.size(); i++) {
    if (p % small_primes[i] == 0) {
      return small_primes[i];
    }
    if (small_primes[i] * small_primes[i] > p) {
      return 1L;
    }
  }
  return 1L;
}

long to_base(char c[N+1], long base) {
  long f = 1;
  long ret = 0;
  for (int i = N-1; i >= 0; i--) {
    if (c[i] == '1') {
      ret += f;
    }
    f *= base;
  }
  return ret;
}

vector<long> jamcoin_factors(char c[N+1]) {
  if ((c[0] != '1') || (c[N-1] != '1')) {
    return vector<long>();
  }

  vector<long> factors;
  for (long base = 2; base <= 10; base++) {
    long f = factor(to_base(c, base));
    if (f == 1) {
      return vector<long>();
    }
    factors.push_back(f);
  }

  return factors;
}

int main(void) {
  printf("Case #1:\n");

  compute_small_primes();

  char c[N+1] = "1000000000000001";
  for (int count = 0; count < J; ) {
    // Check the current number.
    vector<long> jf = jamcoin_factors(c);
    if (jf.size() > 0) {
      count++;
      printf("%s", c);
      for (size_t i = 0; i < jf.size(); i++) {
        printf(" %ld", jf[i]);
      }
      printf("\n");
    }

    // Increment.
    for (int i = N-1; i >= 0; i--) {
      if (c[i] == '0') {
        c[i] = '1';
        break;
      } else {
        c[i] = '0';
      }
    }
  }
}
