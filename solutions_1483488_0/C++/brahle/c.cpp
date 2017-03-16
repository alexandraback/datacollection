#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int t;
int a, b, n;
int p[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

inline int broj(register int x) {
  register int ret = 0;
  set< int > S;
  for (register int i = 1; i < n; ++i) {
    register int o = x/p[i] + (x%p[i])*p[n-i];
    if (o < a || o > b || o <= x || S.count(o)) continue;
    S.insert(o);
    ++ret;
  }
  return ret;
}

int main() {
  cin >> t;
  for (int III = 0; III < t; ++III) {
    cout << "Case #" << III+1 << ": ";

    cin >> a >> b;
    int tmp = a;
    n = 0;
    while(tmp) {
      tmp /= 10;
      ++n;
    }

    int ret = 0;
    for (int i = a; i < b; ++i) {
      ret += broj(i);
    }

    cout << ret << endl;
  }

  return 0;
}


