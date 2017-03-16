#include <iostream>

using namespace std;

int main() {
  int T, N, S, p;

  cin >> T;

  for (int i=0; i<T; i++) {
    int definite = 0, possible = 0;
    
    cin >> N >> S >> p;

    for (int j=0; j<N; j++) {
      int score, definite_max, possible_max;
      cin >> score;

      int mod = score % 3;
      int n = score / 3;

      if (mod == 0) {
        definite_max = n;
        possible_max = n+1;
        if (n-1 < 0 || n+1 > 10) possible_max = definite_max;
      } else if (mod == 1) {
        definite_max = n+1;
        possible_max = n+1;
        if (n-1 < 0 || n+1 > 10) possible_max = definite_max;
      } else if (mod == 2) {
        definite_max = n+1;
        possible_max = n+2;
        if (n+2 > 10) possible_max = definite_max;
      }
      
      if (definite_max >= p) definite++;
      else if (possible_max >= p) possible++;
    }

    int out  = definite + ((possible < S) ? possible : S);

    cout << "Case #" << i+1 << ": " << out << endl;
  }
}

