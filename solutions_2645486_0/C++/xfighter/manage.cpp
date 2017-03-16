#include <iostream>

using namespace std;

int A[20][20];
int V[20];

int main () {
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++) A[i][j] = 0;
    int E, R, N;
    cin >> E >> R >> N;
    for (int i = 0; i < N; ++i) cin>> V[i];

    for (int i = N - 1; i >= 0; i--) {
      for (int j = 0; j <= E; j++) {
        for (int k = 0; k <= j; k++) {
          A[i][j] = max (V[i] * k + A[i + 1][min (j - k + R, E)], A[i][j]);
          // cout << "i: " << i << " j: " << j << " k: "<< k << " v: " << A[i][j] << endl;
        }
      }
    }

    cout << "Case #" << c << ": " << A[0][E] << endl;
  }
}
