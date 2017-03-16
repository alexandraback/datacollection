#include <iostream>
#include <random>
#include <unordered_set>
#include <vector>

using namespace std;

namespace {

const int kMaxBase = 10;
const vector<int> kPrimes = {2, 3, 5, 7};

vector<string> Solve(int N, int J) {
  auto divisor = [&](long long binary, int base) {
    for (int prime : kPrimes) {
      int rem = 0;
      int coeff = 1;
      for (int j = 0; j < N; ++j) {
        rem = (rem + ((binary >> j) & 1) * coeff) % prime;
        coeff = coeff * base % prime;
      }
      if (rem == 0) return prime;
    }
    return -1;
  };

  unordered_set<long long> checked;
  uniform_int_distribution<long long> dist(0LL, (1LL << (N - 2)) - 1);
  mt19937_64 rng(299792458);
  vector<string> res;
  while (res.size() < J) {
    long long binary = (1LL << (N - 1)) + (dist(rng) << 1) + 1;
    if (checked.count(binary)) continue;
    checked.insert(binary);
    vector<long long> witnesses;
    for (int base = 2; base <= kMaxBase; ++base) {
      witnesses.push_back(divisor(binary, base));
      if (witnesses.back() < 0) break;
    }
    if (witnesses.back() > 0) {
      string line;
      for (int i = N - 1; i >= 0; --i) {
        line += '0' + ((binary >> i) & 1);
      }
      for (int witness : witnesses) {
        line += " " + to_string(witness);
      }
      res.push_back(line);
    }
  }
  return res;
}

}

int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    int N, J;
    cin >> N >> J;
    cout << "Case #" << i << ":" << endl;
    for (const auto& line : Solve(N, J)) {
      cout << line << endl;
    }
  }

  return 0;
}
