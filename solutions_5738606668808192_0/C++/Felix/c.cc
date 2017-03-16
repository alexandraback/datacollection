#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX_BASE = 10;
const int MIN_BASE = 2;

vector<ll> jamcoin_divisors(const vector<ll>& primes, ll bm) {
  vector<ll> divs;
  for (ll b = MIN_BASE; b <= MAX_BASE; ++b) {
    int div = -1;
    for (int pi = 0; pi < int(primes.size()) && div == -1; ++pi) {
      const ll p = primes[pi];
      ll b_pow_mod_p = 1;
      ll k_mod_p = 0;
      for (ll k_bm = bm; k_bm > 0; k_bm >>= 1) {
        if ((k_bm&1) == 1) {
          k_mod_p += b_pow_mod_p;
          k_mod_p %= p;
        }
        b_pow_mod_p *= b;
        b_pow_mod_p %= p;
      }
      if (k_mod_p == 0) {
        div = p;
      }
    }
    if (div == -1) {
      return vector<ll>();
    }
    divs.push_back(div);
  }
  return divs;
}

string binary(ll n) {
  string s = "";
  for (; n > 0; n >>= 1) {
    s += char('0' + (n&1));
  }
  reverse(s.begin(), s.end());
  return s;
}

int main() {
  vector<char> is_prime(1000000, 1);
  is_prime[0] = is_prime[1] = 0;
  for (int i = 0; i * i < int(is_prime.size()); ++i) if (is_prime[i]) {
    for (int j = i * i; j < int(is_prime.size()); j += i) {
      is_prime[j] = 0;
    }
  }
  vector<ll> primes;
  const int NUM_PRIMES = 100;
  for (int i = 0; i < int(is_prime.size()) && int(primes.size()) < NUM_PRIMES; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }

  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    int n, j;
    cin >> n >> j;
    cout << "Case #" << ca << ":" << endl;

    int jamcoins = 0;
    for (ll bm = (1LL<<(n - 1)) + 1; bm < (1LL<<n) && jamcoins < j; bm += 2) {
      vector<ll> divs = jamcoin_divisors(primes, bm);
      if (int(divs.size()) > 0) {
        ++jamcoins;
        cout << binary(bm);
        for (int i = 0; i < int(divs.size()); ++i) {
          cout << " " << divs[i];
        }
        cout << endl;
      }
    }
  }
}
