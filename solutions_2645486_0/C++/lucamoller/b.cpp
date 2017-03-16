#include <stdio.h>
#include <string.h>

long long int v[10010];
int T;
long long int N, E, R;

long long int menor(long long int a, long long int b) {
  if ( a < b) return a;
  return b;
}

int findmax(int a, int b) {
  int maxv = -1;
  int maxi = -1;
  for(int i=a; i<=b; i++) {
    if(v[i] > maxv) {
      maxv = v[i];
      maxi = i;
    }
  }
  return maxi;
}

long long int val;
long long int nec;
long long int lef;

long long int resp(long long int I, long long int F, long long int a, long long int b) {
  if(b < a) return 0;
  
  int m = findmax(a, b);
  int pa = m-a;
  int pd = b-m;
 
  if ((pd+1)*R - F < 0) {
    val = menor(E, I + pa*R) + (pd+1)*R - F;
    nec = val + F - (pd+1)*R;
    lef = F - pd*R;
  } else {
    val = menor(E, I+pa*R);
    nec = val;
    lef = R;
  }
  
  if(a == b) return v[m]*val;
  return v[m]*val + resp(I, nec, a , m-1) + resp(lef, F, m+1, b);
}

int main() {
  scanf(" %d", &T);
  for(int c=1; c<=T; c++) {
    scanf(" %lld %lld %lld", &E, &R, &N);
    for(int i = 0; i < N; i++) {
      scanf(" %lld", &v[i]);
    }
    printf("Case #%d: %lld\n", c, resp(E, 0, 0, N-1));
  }
}
