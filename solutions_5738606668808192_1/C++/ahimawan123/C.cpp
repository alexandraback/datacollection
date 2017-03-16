#include<iostream>
#include<cstdio>
using namespace std;

typedef long long LL;

int prime[] = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int nprime = sizeof(prime) / sizeof(int);

// need to reverse the bits for x
int notPrime(LL n, int base) {
  for (int i = 0; i < nprime; i++) {
    int r = 0;
    LL x = n;
    while (x > 0) {
      r *= base;
      if (x & 1) {
        r += 1;
      }
      r %= prime[i];
      x >>= 1;
    }
    if (r == 0) return prime[i];
  }
  return 0;
}

void printRevBinary(LL x) {
  while (x > 0) {
    if (x & 1) cout << '1';
    else cout << '0';
    x >>= 1;
  }
}

int main() {
  int N, J;
  if (0) {
    N = 16;
    J = 50;
  } else {
    N = 32;
    J = 500;
  }
  LL n = 1 << (N-2);
  int div[10];
  cout << "Case #1:\n";
  for (LL i = 0; i < n; i++) {
    LL x = (i << 1) | 1 | (1LL << (N-1));
    bool ok = true;
    for (int j = 2; j <= 10; j++) {
      div[j-2] = notPrime(x, j);
      if (div[j-2] == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      J--;
      // cout << "j " << J << " x " << x;
      printRevBinary(x);
      for (int j = 2; j <= 10; j++) {
        cout << ' ' << div[j-2];
      }
      cout << endl;
      if (J <= 0) break;
    }
  }
  return 0;
}
