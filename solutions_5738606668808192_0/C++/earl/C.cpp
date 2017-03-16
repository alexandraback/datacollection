#include <bits/stdc++.h>
using namespace std;

unsigned Random(int N) {
  unsigned x = 1;
  x = x << N;
  x = x - 1;
  x = ((lrand48() << 10) + lrand48()) & x;
  x |= 1;
  x |= unsigned(1) << (N-1);
  return x;
}

long long ToBase(unsigned x, int b) {
  long long res = 0, q = 1;
  for (int i = 0; i < 32; ++i) {
    if ((x >> i) & 1)
      res += q;
    q = q * b;
  }
  return res;
}

long long Div(long long x) {
  for (long long a = 2; a * a <= x; ++a)
    if (x % a == 0)
      return a;
  return -1;
}

int main() {
  int N, J;
  cin >> N >> J;
  cout << "Case #1:" << endl;
  long long tries = 0;
  while (J--) {
    while (true) {
      ++tries;
      unsigned x = Random(N);
      vector<long long> out;
      bool ok = true;
      for (int b = 2; b <= 10; ++b) {
        out.push_back(Div(ToBase(x, b)));
        if (out.back() < 0) {
          ok = false;
          break;
        }
      }
      if (ok) {
        for (int i=N-1;i>=0;--i)
          cout << ((x >> i)&1);
        for (long long x : out)
          cout << " "  << x;
        cout << endl;
        break;
      }
    }
  }
  cerr << tries << endl;
}
