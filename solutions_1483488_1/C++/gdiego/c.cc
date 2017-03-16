#include <map>
#include <iostream>
using namespace std;
int pow10[] = {1,
               10,
               100,
               1000,
               10000,
               100000,
               1000000,
               10000000,
               100000000,
               1000000000};
int dig(int x) {
  if (!x) return 1;
  int y = 0;
  while (x) y++, x/=10;
  return y;
}
int am(int x, int b) {
  map<int, int> used;
  int mod = 1, d = dig(x), cc = 0;
  while (mod < d) {
    int y = (int)(x / pow10[mod]) + (x % pow10[mod]) * pow10[d - mod];
    if (dig(y) == d && y <= b && x < y && !used[y]) {
      used[y] = 1;
      cc++;
    }
    mod++;
  }
  return cc;
}
int compute() {
  int a, b, ret = 0;
  cin >> a >> b;
  for (int x = a; x <= b; x++) {
    ret += am(x, b);
  }
  return ret;
}
int main() {
  int cases;
  cin >> cases;
  for (int x = 0; x < cases; x++) {
    cout << "Case #" << (x + 1) << ": " << compute() << endl;
  }
  return 0;
}

