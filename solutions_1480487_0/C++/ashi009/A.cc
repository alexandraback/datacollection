#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main (int argc, char const* argv[]) {

  int T, N;
  cin >> T;
  for (int Case = 1; Case <= T; Case++) {
    cin >> N;
    int s[N], X = 0;
    for (int i = 0; i < N; i++) {
      cin >> s[i];
      X += s[i];
    }
    cout << "Case #" << Case << ":";
    double fact = X * 2.0 / N;
    for (int i = 0; i < N; i++) 
      printf(" %.6f", max(0.0, 100 * (fact - s[i]) / X));
    cout << endl;
  }
  
  return 0;
}

