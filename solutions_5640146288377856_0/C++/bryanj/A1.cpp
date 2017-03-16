#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int S[21][21];
  for (int ci = 1; ci <= 20; ci++) {
    for (int wi = 1; wi <= ci; wi++) {
      if (wi == 1 || wi >= ci - 1)
        S[ci][wi] = ci;
      else if (ci <= wi * 2 - 1)
        S[ci][wi] = wi + 1;
      else
        S[ci][wi] = S[ci-wi][wi] + 1;
    }
  }
  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    int r, c, w;
    cin >> r >> c >> w;
    cout << "Case #" << ti << ": " << S[c][w] << endl;
  }
  return 0;
}
