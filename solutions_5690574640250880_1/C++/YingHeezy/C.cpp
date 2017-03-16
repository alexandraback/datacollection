#include <cstdio>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)

int main() {
  int T, R, C, M;
  scanf("%d", &T);
  int arr[55][55];
  REP(iii, T) {
    scanf("%d%d%d", &R, &C, &M);
    M = R*C-M;
    printf("Case #%d:\n", iii+1);
    REP(i, R) REP(j, C) arr[i][j] = '*';
    bool OK = true;
    if (min(R,C) == 1) {
      if (R == 1) {
        REP(i, M) arr[0][i] = '.';
        arr[0][0] = 'c';
      }
      else {
        REP(i, M) arr[i][0] = '.';
        arr[0][0] = 'c';
      }
    }
    else if (min(R,C)==2) {
      if (M%2 && M > 1 || M==2)
        OK = false;
      else {
        if (R == 2) {
          REP(i, M/2) REP(j, 2) arr[j][i] = '.';
          arr[0][0] = 'c';
        }
        else {
          REP(i, M/2) REP(j, 2) arr[i][j] = '.';
          arr[0][0] = 'c';
        }
      }
    }
    else {
      if (M == 1) {
        arr[0][0] = 'c';
      }
      else if ((M<9 && M%2) || M==2) {
        OK = false;
      }
      else if (M < 2*C) {
        if (M%2) {
          REP(i, M/2-1) REP(j,2) arr[j][i] = '.';
          REP(i, 3) arr[2][i] = '.';
          arr[0][0] = 'c';
        }
        else {
          REP(i, M/2) REP(j, 2) arr[j][i] = '.';
          arr[0][0] = 'c';
        }
      }
      else {
        REP(i, M/C) REP(j, C) arr[i][j] = '.';
        if (M%C != 1) {
          REP(i, M%C) arr[M/C][i] = '.';
          arr[0][0] = 'c';
        }
        else {
          if (M/C == 2) {
            REP(i, 3) arr[2][i] = '.';
            REP(j, 2) arr[j][C-1] = '*';
            arr[0][0] = 'c';
          }
          else {
            REP(i, 2) arr[M/C][i] = '.';
            arr[M/C-1][C-1] = '*';
            arr[0][0] = 'c';
          }
        }
      }
    }
    if (!OK) printf("Impossible\n");
    else {
      REP(i, R) {
        REP(j, C) printf("%c", arr[i][j]);
        printf("\n");
     }
   }
  }
}
