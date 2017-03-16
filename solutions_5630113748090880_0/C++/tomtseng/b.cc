#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int input[102][52];
int grid[52][52];
bool row[52];
bool col[52];
bool used[102];
int poss[52][2];

#define INF 5000

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  ll T, N;
  cin >> T;

  for (int t = 1; t <= T; t++) {
    memset(row, 0, sizeof(bool)*52);
    memset(col, 0, sizeof(bool)*52);
    memset(used, 0, sizeof(bool)*102);

    int missing = -1;

    cin >> N;
    const int inlen = 2*N-1;

    for (int i = 0; i < inlen; i++)
      for (int j = 0; j < N; j++)
        cin >> input[i][j];

    // find candidates for currdiag-th row/col
    for (int currdiag = 0; currdiag < N; currdiag++) {
      int minval = INF;
      int minidx = -1;
      int minidx2 = -1;
      for (int i = 0; i < inlen; i++) {
        if (!used[i]) {
          if (input[i][currdiag] < minval) {
            minval = input[i][currdiag];
            minidx = i;
            minidx2 = -1;
          } else if (input[i][currdiag] == minval) {
            minidx2 = i;
          }
        }
      }

      poss[currdiag][0] = minidx;
      poss[currdiag][1] = minidx2;
      used[minidx] = true;
      if (minidx2 >= 0)
        used[minidx2] = true;
      else
        missing = currdiag;
    }

    // brute force ughhhhhhhh
    // THIS WILL FAIL FOR LARGE INPUT
    for (int go = 0; go < (1LL << N); go++) {
      int gotmp = go;
      // assign brute force
      int success = true;
      int leave = false;
      for (int i = 0; i < N; i++) {
        int flip = gotmp & 1;
        gotmp >>= 1;

        if (poss[i][flip] == -1) { // invalid
          leave = true;
          break;
        }

        for (int j = 0; j < N; j++) {
          grid[i][j] = input[poss[i][flip]][j];
        }
      }
      if (leave) continue;

      /*
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
          cout << grid[i][j];
        }
        cout << "\n";
      }
      */

      gotmp = go;
      // check validity
      for (int i = 0; i < N; i++) {
        int flip2 = !(gotmp & 1);
        gotmp >>= 1;
        if (poss[i][flip2] == -1) continue; // skip missing row
        for (int j = 0; j < N; j++) {
          if (grid[j][i] != input[poss[i][flip2]][j]) {
            success = false;
            break;
          }
        }
      }

      if (success) {
        cout << "Case #" << t << ":";
        for (int i = 0; i < N; i++)
          cout << " " << grid[i][missing];
        cout << "\n";
        break;
      }
    }
  }

  return 0;
}
