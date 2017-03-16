#include <bits/stdc++.h>

using namespace std;

vector<int> v;

long long get(int a, int b) {
  long long res = 0;
  long long pw = 1;
  while (a) {
    res += pw * (a & 1);
    pw *= b;
    a >>= 1;
  }
  return res;
}

void print(long long a) {
  int fl = 0;
  for (int i = 16; i >= 0; --i) {
    if (a >> i & 1) {
      fl = 1;
      putchar('1');
    }
    else if (fl) {
      putchar('0');
    }
  }
}

int main() {
  int t, n, j;
  scanf("%d", &t);
  scanf("%d%d", &n, &j);
  printf("Case #1:\n");
  if (n == 16) {
    for (int i = 0; i < 1 << 6 && i < j; ++i) {
      int a = (i << 1) + 1 + (1 << 7);
      v.push_back(a);
    }
    for (int i = 0; i < j; ++i) {
      print(v[i]);
      print(v[i]);
      for (int b = 2; b <= 10; ++b) {
        printf(" %lld", get(v[i], b));
      }
      putchar('\n');
    }
  }
  else {
    for (int i = 0; i < 1 << 14 && i < j; ++i) {
      int a = (i << 1) + 1 + (1 << 15);
      v.push_back(a);
    }
    for (int i = 0; i < j; ++i) {
      print(v[i]);
      print(v[i]);
      for (int b = 2; b <= 10; ++b) {
        printf(" %lld", get(v[i], b));
      }
      putchar('\n');
    }
  }
  return 0;
}
