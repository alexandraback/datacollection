#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void GeneratePrimes(int N, vector<int64_t>* primes) {
  vector<bool> sieve(N, true);
  sieve[0] = false;
  sieve[1] = false;
  for (int64_t i = 2; i * i <= N; i++) {
    if (not sieve[i]) continue;
    primes->push_back(i);
    for (int64_t j = i * i; j <= N; j += i) {
      sieve[j] = false;
    }
  }
}

int64_t Num(int64_t n, int b) {
  int64_t v = 0;
  int64_t m = 1;
  while(n > 0) {
    int r = n % 10;
    n /= 10;
    v += r * m;
    m *= b;
  }
  return v;
}

void Next(std::string* jam) {
  // cout << "in=" << *jam << endl;
  int idx = -1;
  for (int i = jam->size() - 1; i >= 0; --i) {
    if (jam->at(i) == '1') {
      idx = i;
      jam->at(idx) = '0';
      break;
    }
  }
  if (idx == -1) {
    cout << "OVER " << *jam << endl;
    exit(1);
  }
  for (int i = idx + 1; i < jam->size(); ++i) {
    jam->at(i) = '1';
  }
  // cout << "out=" << *jam << endl;
}

int GetDivisor(int64_t N, const vector<int64_t>& primes) {
  for (auto prime : primes) {
    if (N % prime == 0) return prime;
  }
  return -1;
}

int main() {
  int L = 50;
  vector<int64_t> primes;
  GeneratePrimes(10000, &primes);
  // cout << "Generated primes=" << primes.size() << endl;
  cout << "Case #1" << ": " << endl;
  std::string jam = "11111111111111";
  int count = 0;
  while (true) {
    // cout << "jam=" << jam << endl;
    vector<int64_t> divisors;
    auto in = "1" + jam + "1";
    for (int b = 2; b <= 10; ++b) {
      int64_t in_base = stol(in, nullptr, b);
      // cout << "in=" << in_base << endl;
      int64_t divisor = GetDivisor(in_base, primes);
      if (divisor == -1) {
        // cout << "in_base=" << in_base << " No divisor found." << endl;
        break;
      }
      divisors.push_back(divisor);
    }
    if (divisors.size() == 9) {
      cout << in;
      for (auto divisor : divisors) cout << " " << divisor;
      cout << endl;
      ++count;
      if (count == L) return 1;
    }
    Next(&jam);
  }
}
