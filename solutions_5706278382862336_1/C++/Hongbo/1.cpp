#include <cstdio>
#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
  long long r = a % b;
  while(r) a = b, b = r, r = a % b;
  return b;
}

void work() {
  long long a, b;
  char tmp;
  cin >> a >>tmp>> b;
  long long d = 1;
  long long g = gcd(a, b);
  a /= g, b /= g;
  g = b;
  while(g > 1) {
    if(g & 1) {
      cout << "impossible" << endl;
      return;
    }
    else g /= 2;
  }
  for(int i = 1; i < 100; i ++) {
    d = d + d;
    if(a * d >= b) {
      cout << i << endl;
      return;
    }
  }
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int t;
  cin >> t;
  for(int i = 1; i <= t; i ++)
    printf("Case #%d: ", i), work();
  return 0;
}
