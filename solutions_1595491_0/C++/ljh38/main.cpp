#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int t = 0; t != T; ++t) {
    int N, S, p;
    cin >> N >> S >> p;

    if (p < 2) S = 0;

    int A = 0;
    int B = 0;
    
    for (int n = 0; n != N; ++n) {
      int total;
      cin >> total;
      if (total >= 3 * p - 2) ++A;
      else if (total >= 3 * p - 4) ++B;
    }

    cout << "Case #" << t + 1 << ": " << ((p == 0) ? N : (A + min(B, S))) << endl;
  }
  return 0;
}
