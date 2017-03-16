#include <algorithm>
#include <iostream>
using namespace std;

int A[20000];
int AE[100];

int main(void) {
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    cout << "Case #" << tt << ": ";
    int E, R, N;
    cin >> E >> R >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i <= E; ++i) AE[i] = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j <= E - 1; ++j) {
        for (int k = j + 1; k <= E; ++k) {
          AE[j] = max(AE[j], AE[k] + A[i] * (k - j));
        }
      }
      for (int j = E; j >= R; --j) {
        AE[j] = AE[j - R];
      }
      //for (int j = 0; j <= E; ++j) {
      //  cout << AE[j] << " ";
      //}
      //cout << endl;
    }
    cout << AE[0] << endl;
  }
}
