#include <algorithm>
#include <iostream>
using namespace std;

int AP[10]; // length K
int AN[10]; // length N
int ANW[10];
int R, N, M, K;

bool incr() {
  for (int i = 0; i < N; ++i) {
    AN[i]++;
    if (AN[i] > M) {
      AN[i] = 2;
    } else {
      return true;
    }
  }
  return false;
}

int main(void) {
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; ++tt) {
    cout << "Case #" << tt << ":" << endl;
    cin >> R >> N >> M >> K;
    for (int i = 0; i < R; ++i) {
      for (int j = 0; j < K; ++j) cin >> AP[j];
      for (int j = 0; j < N; ++j) AN[j] = ANW[j] = 2;
      int max_score = 0;
      for (; incr(); ) {
        int score = 1;
        for (int j = 0; j < K; ++j) {
          int count = 0;
          for (int k = 0; k < (1 << N); ++k) {
            int prod = 1;
            for (int l = 0; l < N; ++l)
              if (k & (1 << l))
                prod *= AN[l];
            if (prod == AP[j]) {
              count++;
            }
          }
          score *= count;
        }
        /*
        for (int j = 0; j < N; ++j) {
          cout << AN[j];
        }
        cout << " got " << score << endl;
        */
        if (score > max_score) {
          for (int j = 0; j < N; ++j) ANW[j] = AN[j];
          max_score = score;
        }
      }
      for (int j = 0; j < N; ++j) {
        cout << ANW[j];
      }
      cout << endl;
    }
  }
}
