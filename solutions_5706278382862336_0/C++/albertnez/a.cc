#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  ll r = a%b;
  while (r) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}

struct frac {
  ll p;
  ll q;
  void red() {
    ll g = gcd(p,q);
    if (g != 1) {
      p /= g;
      q /= g;
    }
  }
  frac(ll _p, ll _q = 1) : p(_p), q(_q) {
    red();
  }
  double val() { return double(p)/double(q); }
  void mul(ll m) {
    p *= m;
    red();
  }
};


bool check(const frac& f) {
  for (int i = 0; i < 40; ++i) {
    if (1LL<<i >= f.q) {
      if (((1LL<<i) % f.q) == 0) return true;
    }
  }
  return false;
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    int p, q;
    cin >> p;
    cin.ignore();
    cin >> q;
    
    frac n = frac(p, q);
        
    bool pos = check(n);
    int ans = 1;
    if (pos) {
      while (n.val() < 0.5 and ans <= 40) {
        n.mul(2);
        ++ans;
      }
    }
    
//     for (int i = 0
    cout << "Case #" << ++ncase << ": ";
    if (ans <= 40 and pos) cout << ans << endl;
    else cout << "impossible" << endl;
  }
}