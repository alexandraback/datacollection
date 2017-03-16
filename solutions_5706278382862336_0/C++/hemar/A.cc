#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long llong;

llong gcd(llong a, llong b) {
  while (b != 0) {
    llong r = a%b;
    a = b;
    b = r;
  }
  return a;
}

struct Fraction {
  Fraction (llong n, llong d) {num=n;den=d;}
  llong num;
  llong den;
  void simplify() {
    llong d = gcd(den,num);
    num /= d;
    den /= d;
  }
};

bool isPowerOf2(llong n) {
  llong r = n%2;
  while (r == 0) {
    n /= 2;
    r = n%2;
  }
  return n == 1;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    string PQ;
    llong P=0,Q=0;
    cin >> PQ;
    int i = 0;
    while (PQ[i] != '/') {
      P=P*10+PQ[i]-'0';
      ++i;
    }
    while (++i < PQ.length()) Q=Q*10+PQ[i]-'0';
    Fraction f(P,Q);
    f.simplify();
    cout << "Case #" << t << ": ";
    if (isPowerOf2(f.den))  cout << ceil(log2((double)Q/P)) << endl;
    else cout << "impossible" << endl;
  }
}
