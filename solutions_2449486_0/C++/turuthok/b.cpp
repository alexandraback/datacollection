#include <iostream>

using namespace std;

const int K = 100;
const int N = 100;

int a[N][N];
int rr[N];
int cc[N];

int main() {
  int cases; cin >> cases;
  for (int caseNo = 1; caseNo <= cases; caseNo++) {
    int rows, cols; cin >> rows >> cols;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        cin >> a[i][j];
      }
    }

    for (int i = 0; i < rows; i++) {
      rr[i] = 0;
      for (int j = 0; j < cols; j++) rr[i] = max(rr[i], a[i][j]);
    }

    for (int j = 0; j < cols; j++) {
      cc[j] = 0;
      for (int i = 0; i < rows; i++) cc[j] = max(cc[j], a[i][j]);
    }

    bool valid = true;
    for (int i = 0; valid && i < rows; i++) for (int j = 0; valid && j < cols; j++) {
      if (a[i][j] < rr[i] && a[i][j] < cc[j]) valid = false;
    }
    cout << "Case #" << caseNo << ": " << (valid ? "YES" : "NO") << endl;
  }
  return 0;
}