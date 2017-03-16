#include <bits/stdc++.h>
using namespace std;

int t;
long long x;
long long n;
char a[10005];

char mul(char x, char y) {
  bool minus = false;
  if ((x < 0) ^ (y < 0)) {
    minus = true;
  }
  if ( x < 0) {
    x = -x;
  }
  if (y < 0) {
    y = -y;
  }
  char ret = 1;
  if (minus) {
    ret = -1;
  }
  if (x == '1') {
    ret = ret * y;
  } else if ( y== '1') {
    ret = ret * x;
  } else if (x == 'i') {
    if (y == 'i') {
      ret = ret * (-'1');
    } else if (y == 'j') {
      ret = ret * ('k');
    } else if (y == 'k') {
      ret = ret * (-'j');
    }
  } else if (x == 'j') {
    if (y == 'i') {
      ret = ret * (-'k');
    } else if (y == 'j') {
      ret = ret * (-'1');
    } else if (y == 'k') {
      ret = ret * 'i';
    }
  } else if (x == 'k') {
    if (y == 'i') {
      ret = ret * ('j');
    } else if (y == 'j') {
      ret = ret * (-'i');
    } else if (y == 'k') {
      ret = ret * (-'1');
    }
  }
  return ret;
}

int main() {
  scanf("%d", &t);
  int cs = 0;
  while (t--) {
    scanf("%lld %lld", &n, &x);
    scanf("%s",a);
    char total = '1';
    char all = '1';
    for (long long i = 0; i < n; i++) {
      total = mul(total, a[i]);
    }
    for (long long i = 0; i < (x % 4); i++) {
      all = mul(all, total);
    }
    printf("Case #%d: ", ++cs);
    long long mini1 = 1000000000000000000LL;
    long long mini2 = 0;
    if (all != -'1') {
      printf("NO\n");
    } else {
      char tmp = '1';
      for (long long i = 0; i < n; i++) {
        tmp = mul(tmp, a[i]);
        char haha = tmp;
        for (long long j = 0;j < 4; j++) {
          if (haha == 'i') {
            mini1 = min(mini1, j * n + i);
          }
          haha = mul(total, haha);
        }
      }
      tmp = '1';
      for (long long i = n-1; i >= 0; --i) {
        tmp = mul(a[i], tmp);
        char haha = tmp;
        for (long long j = 0; j < 4; j++) {
          if (haha == 'k') {
            mini2 = max(mini2, (x - 1 - j)*n + i);
          }
          haha = mul(haha, total);
        }
      }
      if (mini1 < mini2) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
  }
}
