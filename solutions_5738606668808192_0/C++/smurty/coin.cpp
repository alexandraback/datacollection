#include <iostream>
#include <vector>
#include <bitset>
#define REP(i, N) for (int i = 0; i < N; i++)
using namespace std;
int modpow(int b, int e, int m) {
  int a = 1;
  for(;e;e/=2, b = b*b%m) if (e & 1) a = a*b%m;
  return a;
}
const int NPRIMES = 30;
vector<int> primes;
int compos(unsigned x, int b) {
  for (int p : primes) {
    int s = 0;
    REP(j, 32) if (x >> j & 1) s = (s + modpow(b,j,p)) % p;
    if (s == 0) return p;
  }
  return 0;
}


int main() {
  //cout << modpow(2,12,10000) << endl;
  cout << "Case #1:" << endl;
  for (int i = 2; (int)primes.size() < NPRIMES; i++) {
    bool good = true;
    for (int j = 2; j < i; j++)
      if (i % j == 0) { good = false; break; }
    if (good) primes.push_back(i);
  }
  int cnt = 0;
  for (unsigned x = 0; x < (1 << 16) && cnt < 50; x++) {
    if ((x & 1) && (x >> 15 & 1)) {
      vector<int> v;
      for(int b = 2; b <= 10; b++) {
        int c = compos(x,b);
        if (c) v.push_back(c); else break;
      }
      if ((int)v.size() == 9) {
        cout << bitset<16>((unsigned short)x);
        for (int f : v) cout << " " << f;
        cout << endl;
        cnt++;
      }
    }
    
      
  }
    
  return 0;
}
