// by tmt514
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#define SZ(x) ((int)(x).size())
#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
typedef long long LL;

int primes[1000], np;

void gen() {
  for(int i=3;i<1000;i+=2) {
    int ok=1;
    for(int j=2;j*j<=i;j++)
      if(i%j==0) { ok=0; break; }
    if (ok) primes[np++] = i;
  }
}

bool divisable(int N, int b[], int base, int p) {
  int r=0;
  for(int i=0;i<N;i++) {
    r=(r*base+b[i])%p;
  }
  return r==0;
}

void solve() {
  static int cs=0;
  ++cs;
  printf("Case #%d:\n", cs);
  fprintf(stderr, "Case #%d:\n", cs);
  
  int N, J;
  scanf("%d%d", &N, &J);
  int b[40]={};
  for(int i=0;i<N;i++) b[i] = 0;
  b[0] = b[N-1] = 1;
  while(J>0) {
    
    int flag = 0;
    int s[11]={};
    for(int base=2;base<=10;base++) {
      for(int p=0;p<np;p++)
        if (divisable(N, b, base, primes[p])) {
          s[base] = primes[p];
          break;
        }
      if (s[base]==0) { flag = 1; break; }
    }
    if (!flag) {
      --J;
      for(int i=0;i<N;i++) printf("%d", b[i]);
      for(int base=2;base<=10;base++) printf(" %d", s[base]);
      printf("\n");
      
      for(int i=0;i<N;i++) fprintf(stderr, "%d", b[i]);
      for(int base=2;base<=10;base++) fprintf(stderr," %d", s[base]);
      fprintf(stderr,"\n");
    }

    int w = 1;
    while (b[w]==1) b[w++] = 0;
    b[w]=1;
    assert(w < N);
  }
}

int main(void) {
  int T;
  gen();
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}
