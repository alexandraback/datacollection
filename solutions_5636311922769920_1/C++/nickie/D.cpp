#include <cassert>
#include <iostream>

using namespace std;

int main (int argc, char *argv[])
{
  int tests;
  cin >> tests;
  for (int test = 1; test <= tests; test++) {
    int K, C, S;
    cin >> K >> C >> S;
    cout << "Case #" << test << ":";
    if (K > S*C)
      cout << " IMPOSSIBLE";
    else
      for (int k = 0; k < K; k += C) {
        long long int j = 0, p = 1;
        for (int i = 0, x = k; x < min(K, k+C); ++i, ++x) {
          j += x * p;
          p *= K;
        }
        cout << " " << 1+j;
      }
    cout << endl;
  }
  return 0;
}
