#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

long long int getFactor(long long int N) {
  long long int r;

  if(N%2 == 0) return 2;

  for(r = 3; r*r < N; r += 2) {
    if(N%r == 0) return r;
  }

  return 0;
}

long long int pots[11][17];

long long int interpret(long long int N, int base) {
  long long int res = 0;
  int p = 0;

  while(N != 0) {
    res += (N & 1) * pots[base][p];
    N = N / 2;
    p++;
  }

  return res;
}

void imprime(long long int N) {
  long long int mask = 0x8000;

  for(int i = 0; i < 16; i++) {
    if(N & mask) printf("1");
    else printf("0");
    mask = mask/2;
  }
}

int main() {
  long long int divs[11];

  for(int i = 2; i <= 10; i++) {
    pots[i][0] = 1;
    for(int j = 1; j < 16; j++) {
      pots[i][j] = pots[i][j-1]*i;
    }
  }

  printf("Case #1:\n");

  long long int N = 0x8001;

  int k = 0;
  bool found;
  long long int aux;
  while(k < 50 && N <= 0xFFFF) {
    found = true;

    for(int base = 2; base <= 10; base++) {
      divs[base] = getFactor(interpret(N, base));
      if(divs[base] == 0) {
        found = false;
        break;
      }
    }

    if(found) {
      k++;
      imprime(N);
      for(int base = 2; base<= 10; base++)
        printf(" %lld", divs[base]);
      printf("\n");
    }

    N = N+2;
  }

  return 0;
}
