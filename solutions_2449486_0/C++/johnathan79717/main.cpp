#include <iostream>

using namespace std;

int N, M, i, j;
int mawn[100][100], rowmax[100], colmax[100];

bool check() {
  for(i = 0; i < N; i++)
    for(j = 0; j < M; j++)
      if(mawn[i][j] < rowmax[i] && mawn[i][j] < colmax[j])
        return false;
  return true;
}

int main() {
  int T;
  cin >> T;
  for(int t = 1; t <=T; t++) {
    cout << "Case #" << t << ": ";
    cin >> N >> M;
    for(i = 0; i < N; i++) {
      rowmax[i] = 0;
      for(j = 0; j < M; j++) {
        cin >> mawn[i][j];
        rowmax[i] = max(rowmax[i], mawn[i][j]);
      }
      // cout << rowmax[i] << endl;
    }

    for(j = 0; j < M; j++) {
      colmax[j] = 0;
      for(i = 0; i < N; i++)
        colmax[j] = max(colmax[j], mawn[i][j]);
      // cout << colmax[j] << endl;
    }

    if(check())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}