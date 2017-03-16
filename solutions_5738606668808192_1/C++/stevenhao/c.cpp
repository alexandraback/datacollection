#include <cstdio>

typedef long long ll;

int N = 32;
int J = 500;

bool div(int a, ll x, int b) {
  int r = 0;
  int cur = 1;
  for(int i = 0; i < N; ++i) {
    if ((x >> i) & 1) {
      r += cur;
      r %= a;
    }
    cur *= b;
    cur %= a;
  }
  return !r;
}

int ok(ll k, int b) {
  for(int i = 2; i <= 20; ++i) {
    if (div(i, k, b)) {
      return i;
    }
  }
  return 0;
}

void disp(ll k) {
  for(int i = N - 1; i >= 0; --i) {
    printf("%d", (int)((k >> i) & 1));
  }
}

int main() {
  printf("Case #1:\n");
  ll start = (1L << (N - 1)) + 1;
  for(ll i = start, cnt = 0; cnt < J; i += 2) {
    bool good = true;
    for(int j = 2; j <= 10; ++j) {
      if (!ok(i, j)) {
        good = false;
      }
    }
    if (good) {
      ++cnt;
      disp(i);
      for(int j = 2; j <= 10; ++j) {
        printf(" %d", ok(i, j));
      }
      printf("\n");
    }
  }
}
