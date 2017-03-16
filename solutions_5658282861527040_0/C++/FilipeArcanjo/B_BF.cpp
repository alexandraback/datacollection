#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int ntc; cin >> ntc;
  for (int tc = 1; tc <= ntc; ++tc) {
    int A, B, K; cin >> A >> B >> K;
    int sol = 0;
    for (int a = 0; a < A; ++a) for (int b = 0; b < B; ++b) {
      if ((a & b) < K) sol++;
    }
    cout << "Case #" << tc << ": " << sol << endl;
  }
}
