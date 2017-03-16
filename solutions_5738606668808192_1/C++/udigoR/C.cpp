#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <tuple>
#include <string>
#include <algorithm>
#include <bitset>
#include <iomanip>

using namespace std;

void calcPrimes(set<long long> &primes, long long x) {
  vector<bool> v(x + 1, false);
  for (long long i = 2; i < x + 1; ++i) {
    if (v[i] == false) {
      primes.insert(i);
      for (long long j = i; j < x + 1; j+=i)
        v[j] = true;
    }
  }
}

long long convert(long long x, int base) {
  long long ret = 0;
  long long s = 1;
  while (x != 0) {
    ret += (x % 2) * s;
    s *= base;
    x /= 2;
  }
  return ret;
}

long long findDelim(long long x, int base, set<long long> &primes, int count) {
  auto prime = primes.begin();
  for (int i = 0; i < count; ++i) {
    if (*prime >= x)
      break;
    long long bs = base % *prime;
    long long t = x / 2;
    long long ret = 1;
    long long s = bs;
    while (t != 0) {
      if (t % 2)
        ret += s % *prime;
      s = (s * bs) % *prime;
      t /= 2;
    }
    if (ret % *prime == 0)
      return *prime;
    ++prime;
  }
  return -1;
}

int main() {
  set<long long> primes;
  calcPrimes(primes, 1u << 24);
  const int maxPrime = 10000;

  int T;
  cin >> T;

  for (int testCase=0; testCase < T; ++testCase)
  {
    int N, J;
    cin >> N >> J;

    long long start = (1u << (N-1)) + 1;
    long long finish = 1u;
    finish = finish << N;

    cout << "Case #" << testCase + 1 << ":\n";

    long long prev = -1;

    for (long long i = start; i < finish; i+=2) {
      if (J==0)
        break;
      
      vector<long long> correct(9);
      bool isOk = true;
      for (int j = 2; j <= 10; ++j) {
        long long x = findDelim(i, j, primes, maxPrime);
        if (x == -1) {
          isOk = false;
          break;
        }
        correct[j-2] = x;
      }
      if (isOk) {
        bitset<32> ib(i);
        cout << ib << " ";

        for (auto k = 0; k < correct.size(); ++k)
          cout << correct[k] << " ";
        cout << endl;
        J--;
      }
    }
  }

  return 0;
}

/*
int main2() {
  set<long long> primes;
  calcPrimes(primes, 1u << 16);

  int T;
  cin >> T;

  for (int testCase=0; testCase < T; ++testCase)
  {
    int N, J;
    cin >> N >> J;

    long long start = (1u << (N-1)) + 1;
    long long finish = 1u;
    finish = finish << N;

    cout << "Case #" << testCase + 1 << ":\n";

    long long prev = -1;

    for (long long i = start; i < finish; i+=2) {
      if (J==0)
        break;
      if (primes.find(i) == primes.end()) {
        bool isOk = true;
        for (int j = 3; j <= 10; ++j) {
          long long x = convert(i, j);
          if (primes.find(x) != primes.end()) {
            isOk = false;
            break;
          }
        }
        if (isOk) {
          vector<long long> correct;
          for (int j = 2; j <= 10; ++j) {
            long long x = convert(i, j);
            long long top = sqrt(x) + 1;
            for (long long k = 2; k < top; ++k)
              if (x % k == 0) {
                correct.push_back(k);
                break;
              }
          }
          if (correct.size() == 9) {
            bitset<16> ib(i);
            cout << ib << " ";

            if (prev != -1) {
              cout << "[" << i - prev << "] ";
            }
            prev = i;

            for (auto k = 0; k < correct.size(); ++k)
              cout << correct[k] << " ";
            cout << endl;
            J--;
          }
        }
      }
    }
  }

  return 0;
}
*/