#include <cstdio>

const int MAXN = 1000005;
const int oo = (~0u) >> 1;

int d[MAXN];

void solve() {
  int n;
  scanf("%d", &n);
  printf("%d\n", d[n]);
}


int reverse(int num) {
  int now = 0;
  while(num!=0) {
    now = now * 10 + num % 10;
    num /= 10;
  }
  return now;
}

void Min(int &a, int b) {
  if (b < a)
    a = b;
}

void pre_solve() {
  for (int i = 0; i < MAXN; i++)
    d[i] = oo;
  d[1] = 1;
  for (int i = 1; i < MAXN; i++) {
    if (d[i] != oo) {
      Min(d[i+1], d[i]+1);
      int j = reverse(i);
      if (j < MAXN)
        Min(d[j], d[i]+1);
    }
  }
}

int main() {
  pre_solve();
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
