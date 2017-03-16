#include <iostream>
extern "C" {
#include <quadmath.h>
}

using namespace std;
typedef long long int int64;
typedef __float128 longdouble;

int main()
{
  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; ++case_num)
  {
    int64 r, t;
    cin >> r >> t;

    longdouble A = 2.0;
    longdouble B = 2.0 * r + 3.0;
    longdouble C = 2.0 * r + 1 - t;
    longdouble disc = B*B - 4*A*C;
    longdouble s1 = (-B - sqrtq(B*B - 4*A*C)) / (2*A);
    longdouble s2 = (-B + sqrtq(B*B - 4*A*C)) / (2*A);
    int64 rings = int64(floorq(s2) + 1.0);

    cout << "Case #" << case_num << ": " << rings << endl;
  }

  return 0;
}
