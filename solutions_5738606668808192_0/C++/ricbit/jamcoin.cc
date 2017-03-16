#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

template<typename T>
class MillerRabin {
 public:
  bool prime(T n) {
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    static const unsigned long long minval[] = {
        2047, 1373653, 25326001, 3215031751ULL, 2152302898747ULL,
        3474749660383ULL, 341550071728321ULL, 341550071728321ULL,
        3825123056546413051ULL, 3825123056546413051ULL, 3825123056546413051ULL};
    static const int witness[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    int max_witness = 0;
    for (; max_witness < 11; max_witness++) {
      if (static_cast<unsigned long long>(n) < minval[max_witness]) {
        break;
      }
    }
    T d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
      s++; 
      d /= 2;
    }
    for (int i = 0; i <= max_witness; i++) {
      if (!miller_step(n, d, s, witness[i])) {
        return false;
      }
    }
    return true;
  }
 private:
  bool miller_step(T n, T d, int s, int witness) {
    T x = modpow(witness, d, n);
    if (x == 1 || x == n - 1) {
      return true;
    }
    for (int r = 1; r < s; r++) {
      x = modmul(x, x, n);
      if (x == 1) {
        return false;
      }
      if (x == n - 1) {
        return true;
      }
    }
    return false;
  }
  T modpow(T a, T d, T n) {
    if (d == 0) {
      return 1;
    }
    T half = modpow(a, d / 2, n);
    T full = modmul(half, half, n);
    if (d % 2) {
      return modmul(full, a, n);
    } else {
      return full;
    }
  }
  template<typename Q>
  Q modmul(Q a, Q b, Q n) {
     return (static_cast<unsigned long long>(a) * b) % n;
  }
  unsigned long long modmul(
      unsigned long long a, unsigned long long b, unsigned long long n) {
    return (__int128)a*b%n;
  }
};

MillerRabin<unsigned long long> MR;

unsigned long long convert(const vector<int>& coin, int base) {
  unsigned long long ans = 0;
  for (int c : coin) {
    ans = ans * base + c;
  }
  return ans;
}

bool isbaseprime(const vector<int>& coin, int i) {
  return MR.prime(convert(coin, i));
}

bool isjamcoin(const vector<int>& coin) {
  for (int i = 2; i < 11; i++) {
    if (isbaseprime(coin, i)) {
      return false;
    }
  }
  return true;
}

string dump(const vector<int>& coin) {
  string out = "";
  for (int c : coin) {
    out += char(c + 48);
  }
  return out;
}

int find_small_div(unsigned long long x) {
  for (int i = 2; i < 100000; i++) {
    if (x % i == 0) {
      return i;
    }
  }
  return 0;
}

pair<string, vector<int>> jamcoin(int j) {
  vector<int> coin(j, 1);
  do {
    for (int i = 1; i < j - 1; i++) {
      coin[i] = rand() < RAND_MAX / 2;
    }
  } while (!isjamcoin(coin));
  vector<int> divs(11);
  for (int i = 2; i <= 10; i++) {
    int d = find_small_div(convert(coin, i));
    if (!d) {
      return jamcoin(j);
    }
    divs[i] = d;
  }
  return make_pair(dump(coin), divs);
}

int main() {
  srand(time(NULL));
  int t,size,samples;
  cin >> t >> size >> samples;
  cout << "Case #1:\n";
  for (int i = 0; i < samples; i++) {
    auto ans = jamcoin(size);
    cout << ans.first;
    for (int i = 2; i <= 10; i++) {
      cout << " " << ans.second[i];
    }
    cout << "\n";
  }
  return 0;
}
