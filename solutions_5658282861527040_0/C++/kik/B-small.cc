#include <iostream>
#include <iomanip>

using namespace std;

typedef unsigned long long ull;

ull top(ull x)
{
  for (ull y = 1ull << 63; y; y >>= 1) {
    if (x & y) return y;
  }
  return 0;
}
ull solve(ull A, ull B, ull K)
{
  ull r = 0;

  for (ull a = 0; a < A; a++) {
    for (ull b = 0; b < B; b++) {
      if ((a & b) < K) r++;
    }
  }
  return r;
}

int main()
{
  int T;

  cin >> T;

  for (int cas = 1; cas <= T; cas++) {
    ull A, B, K;
    cin >> A >> B >> K;

    ull r = solve(A, B, K);

    cout << "Case #" << cas << ": " << r << endl;
  }

  return 0;
}
