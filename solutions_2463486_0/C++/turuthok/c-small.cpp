#include <iostream>

using namespace std;

const int N = 10000000;

long long all[N];
int n = 0;

long long rev(long long x) {
  long long r = 0;
  while (x) {
    r = (r * 10) + (x % 10);
    x /= 10;
  }
  return r;
}

int main() {
  for (int i = 0; i <= N; i++) {
    if (i != rev(i)) continue;
    long long s = (long long)i * i;
    if (s == rev(s)) all[n++] = s;
  }

  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    long long a;
    long long b;
    cin >> a >> b;
    int res = 0;
    for (int i = 0; i < n; i++) if (a <= all[i] && all[i] <= b) res++;
    cout << "Case #" << caseNo << ": " << res << endl;
  }

  return 0;
}