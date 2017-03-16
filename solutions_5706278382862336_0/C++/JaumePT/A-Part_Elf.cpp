#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll gdc(ll a, ll b) {
  if (a == 0) return b;
  return gdc(b%a, a);
}

struct Rational {
  ll N, D;  
  
  Rational():N(0), D(1) {}
  Rational(ll n): N(n), D(1) {}
  Rational(ll n, ll d) :N(n), D(d) {}
  
  void normalize() {
    ll g = gdc(N, D);
    N /= g;
    D /= g;
  }
};

int pow_of_2(ll n) {
  int cont = 0;
  while (n%2 == 0) {
    n >>= 1;
    ++cont;
  }
  n >>= 1;
  if (n == 0) return cont;
  return -1;
}

int next_pow_of_2(ll n) {
  int cont = 0;
  while (n != 0) {
    n >>= 1;
    ++cont;
  }
  return cont;
}

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cout << "Case #" << cas << ": ";
    Rational R;
    char c;
    cin >> R.N >> c >> R.D;
//     if (R.N == 0) {
//       cerr << "(n == 0)";
//       cout << "impossible" << endl;
//       continue;
//     }
    R.normalize();
    int p = pow_of_2(R.D);
    if (p != -1 and p <= 40) {
      int p2 = next_pow_of_2(R.N);
      cout << p - p2 + 1 << endl;
    }
    else {
//       cerr << "(p == " << p << ")";
      cout << "impossible" << endl;
    }
  }
}