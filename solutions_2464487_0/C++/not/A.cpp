#include<iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

long long calc(long long a, long long b) {
  long long aa = 2 * a + 1;
  long long bb = 2 * b + 1;
  //cout << aa << " " << bb << endl;
  if (8e18 / ((aa + bb) / 2) < ((b - a) / 2 + 1)) return 8e18;
  return (aa + bb) / 2 * ((b - a) / 2 + 1);
}

int main() {
  int T;
  cin >> T;
  rep (iii, T) {
    long long r, t;
    cin >> r >> t;
    long long a = 0, b = 1e9;
    while (a < b - 1) {
      long long m = (a + b) / 2;
      if (m == 0) {
	a = m;
	break;
      }
      if (t >= calc(r, r + 2 * (m - 1))) a = m;
      else b = m;
    }
    cout << "Case #" << iii + 1 << ": " << a << endl;
  }
  return 0;
}
