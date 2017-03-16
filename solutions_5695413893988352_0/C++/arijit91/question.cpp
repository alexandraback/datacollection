#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
  int n;
  cin>>n;
  for (int cas = 1; cas <= n; cas++) {
    string A, B;
    string candA, candB, bestA, bestB;
    cin >> A >> B;
    int best = 1000000;
    if (A.size() == 3) {
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          for (int k = 0; k < 10; k++) {
            for (int x = 0; x < 10; x++) {
              for (int y = 0; y < 10; y++) {
                for (int z = 0; z < 10; z++) {
                  candA = A;
                  candB = B;
                  if (A[0] == '?') candA[0] = '0' + i;
                  if (A[1] == '?') candA[1] = '0' + j;
                  if (A[2] == '?') candA[2] = '0' + k;
                  if (B[0] == '?') candB[0] = '0' + x;
                  if (B[1] == '?') candB[1] = '0' + y;
                  if (B[2] == '?') candB[2] = '0' + z;

                  int score = abs((100 * candA[0] + 10 * candA[1] + candA[2]) - 
                                  (100 * candB[0] + 10 * candB[1] + candB[2]));
                  if (score < best) {
                    best = score;
                    bestA = candA;
                    bestB = candB;
                  }
                }
              }
            }
          }
        }
      }
    } 
    else if (A.size() == 2) {
      for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
          for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
              candA = A;
              candB = B;
              if (A[0] == '?') candA[0] = '0' + i;
              if (A[1] == '?') candA[1] = '0' + j;
              if (B[0] == '?') candB[0] = '0' + x;
              if (B[1] == '?') candB[1] = '0' + y;

              int score = abs((10 * candA[0] + candA[1]) - (10 * candB[0] + candB[1]));
              if (score < best) {
                best = score;
                bestA = candA;
                bestB = candB;
              }
            }
          }
        }
      }
    }
    else if (A.size() == 1) {
      for (int i = 0; i < 10; i++) {
        for (int x = 0; x < 10; x++) {
          candA = A;
          candB = B;
          if (A[0] == '?') candA[0] = '0' + i;
          if (B[0] == '?') candB[0] = '0' + x;

          int score = abs((candA[0]) - (candB[0]));
          if (score < best) {
            best = score;
            bestA = candA;
            bestB = candB;
          }
        }
      }
    }

    cout << "Case #" << cas << ": " << bestA << " " << bestB << endl;
  }
}
