#include <iostream>
using namespace std;

long long gcd (long long a, long long b) {
  while (b > 0) {
    long long tmp = a % b;
    a = b;
    b = tmp;
  }
  return a;
}
int main() {
  int T;
  cin >> T;
  for (int testcase = 1; testcase <= T; ++testcase) {
    long long p, q;
    cin >> p;
    {
      char ch;
      cin >> ch;
    }
    cin >> q;
    long long d = gcd(p, q);
    p /= d;
    q /= d;
    long long q_pow = 1;
    while ((((long long)(1)) << q_pow) < q)
      ++q_pow;
    if ((((long long)(1)) << q_pow) != q)
    {
      cout << "case #" << testcase << ": impossible" << endl;
      continue;
    }
    long long p_pow = 1;
    while ((((long long)(1)) << p_pow) <= p)
      ++p_pow;
    cout << "case #" << testcase << ": " << (q_pow - p_pow + 1) << endl;

  }
  return 0;
}