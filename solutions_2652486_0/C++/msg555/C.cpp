#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cstdlib>
#include <utility>
#include <cmath>

using namespace std;

int CNT[1110][1110];

int RES[1110][3];

int A[3];
double P[1110];

int main() {
  int T; cin >> T;

  for(int t = 1; t <= T; t++) {
    int R, N, M, K;
    cin >> R >> N >> M >> K;

    int rsz = 0;
    for(A[0] = 2; A[0] <= M; A[0]++)
    for(A[1] = A[0]; A[1] <= M; A[1]++)
    for(A[2] = A[1]; A[2] <= M; A[2]++) {
      for(int i = 0; i < N; i++) {
        RES[rsz][i] = A[i];
      }
      for(int i = 0; i < 1 << N; i++) {
        int m = 1;
        for(int j = 0; j < N; j++) {
          if(i & 1 << j) {
            m *= A[j];
          }
        }
        ++CNT[m][rsz];
      }
      rsz++;
    }

    cout << "Case #" << t << ":" << endl;
    for(int i = 0; i < R; i++) {
      memset(P, 0, sizeof(P));
      for(int j = 0; j < K; j++) {
        int m; cin >> m;
        for(int k = 0; k < rsz; k++) {
          if(CNT[m][k] == 0) {
            P[k] = -1e300;
          } else {
            P[k] += log(CNT[m][k]);
          }
        }
      }

      int mi = max_element(P, P + rsz) - P;
      for(int j = 0; j < N; j++) {
        cout << (char)('0' + RES[mi][j]);
      }
      cout << endl;
    }
  }
  return 0;
}
