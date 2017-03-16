#include <cstdio>

typedef unsigned long long ullong;
typedef long long llong;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

const int nmax = 10000;
int *newton[nmax];

#define func(x) (2*(x)-1)*(x)

int abs(int x) {
  if (x < 0)
    return -x;
  return x;
}

int min(int a, int b) {
  if (a < b)
    return a;
  return b;
}

int bisect(int n) {
  int l = 0;
  int h = n;
  int m = n/2;
  while (h-l > 1) {
    int v = n-func(m);
    if (v == 0)
      return m;
    if (v < 0)
      h = m;
    else
      l = m;
    m = (l+h)/2;
  }
  if (n-func(h) < 0)
    return l;
  return h;
}

long long sil(int n, int s = 2) {
  long long res = 1;
  for (int i = s; i < n; ++i)
    res *= i;
  return res;
}


int newt(int n, int k) {
  if (n < nmax)
    return newton[n][k];
  if (n-k > k)
    return newt(n-k, k);
  return sil(n, n-k)/sil(k);
}

void newtonPre() {
  newton[0] = new int[1];
  newton[1] = new int[2];
  newton[0][0] = 1;
  newton[1][0] = 1;
  newton[1][1] = 1;
  for (int i = 2; i < nmax; ++i) {
    newton[i] = new int[i+1];
    newton[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      if (j != nmax)
	 newton[i][j] = newton[i-1][j]+newton[i-1][j-1];
      else
	 newton[i][j] = newton[i-1][j-1];
    }
  }
}


 
void solve() {
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  int full = bisect(n)-1;
  fprintf(stderr, "\tfull: %d\n", full);
  int pos = (abs(x)+abs(y))/2;
  if (pos > full+1) {
    puts("0.0");
    return;
  }
  if (pos <= full) {
    puts("1.0");
    return;
  }
  int rem = n-func(full+1);
  if (x == 0 || rem == 0) {
    puts("0.0");
    return;
  }
  int px = 2*(full+1)-abs(x)+1;
  int last = (full+1)*2;
  int can = min(rem, last-1);
  if (rem == last)
    can = rem;
  fprintf(stderr, "\tn: %d\n", n);
  fprintf(stderr, "\tfunc(full+1): %d\n", func(full+1));
  fprintf(stderr, "\trem: %d\n", rem);
  fprintf(stderr, "\tlast: %d\n", last);
  fprintf(stderr, "\tcan: %d\n", can);
  fprintf(stderr, "\tpx: %d\n", px);
  double prob = 0;
  for (int i = px; i <= can; ++i) {
    //fprintf(stderr, "+= newton[%d][%d] == %d\n", rem, i, newton[rem][i]);
    prob += newton[rem][i];
  }
  for (int i = 0; i < rem; ++i)
    prob /= 2;
  if (rem > last && px > rem-last)
    prob += 0.5;
  printf("%f\n", prob);
}

int main() {
  newtonPre();
  int numC;
  scanf("%i", &numC);
  for (int i = 1; i <= numC; ++i) {
    printf("Case #%i: ", i);
    solve();
  }
}