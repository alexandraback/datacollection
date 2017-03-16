#include<iostream>
#include<cstdio>
using namespace std;

int extract(int x) {
  int ret = 0;
  while (x > 0) {
    int y = x % 10;
    ret |= (1 << y);
    x = x / 10;
  }
  return ret;
}

int main() {
  int t, n;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    cin >> n;
    if (n == 0) {
      cout << "INSOMNIA\n";
      continue;
    }
    int used = 0;
    int x = 0;
    int end = (1 << 10) - 1;
    while (used != end) {
      x += n;
      used |= extract(x);
    }
    cout << x << endl;
  }
  return 0;
}
