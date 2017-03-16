#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2000000;

int m[N+1];

inline int rotate(int n, int m) {
  return (m * (n % 10)) + (n / 10);
}

int main() {
  int t; cin >> t;
  int iter = 0;
  for (int caseNo = 1; caseNo <= t; caseNo++) {
    int a, b; cin >> a >> b;
    char dummy[16];
    int len = sprintf(dummy, "%d", a);
    int mult = 1;
    for (int i = 1; i < len; i++) mult *= 10;
    int res = 0;
    while (a <= b) {
      int work = a;
      iter++;
      for (int i = 1; i < len; i++) {
        work = rotate(work, mult);
        if (a < work && work <= b && m[work] != iter) res++, m[work] = iter;
      }
      a++;
    }
    cout << "Case #" << caseNo << ": " << res << endl;
  }
  return 0;
}

