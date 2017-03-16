#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

double g_a[101];
double g_A[101];
double g_b[101];
double g_B[101];
int N, M;

double solve(double *a, double *A, double *b, double *B, int n, int m) {
  double max = 0, ship;
  int i,j;
  double *ap, *Ap, *bp, *Bp;

  for (i = 0; i < n; i++) {
    //for (long long k=0; k < (N-n); k++) printf("  "); printf("  %d\n", A[i]);
    for (j = 0; j < m; j++) {
      // loop to find the first tosy that match these boxes
      if (B[j] != A[i]) continue;

      if (b[j] < a[i]) {
        // We found toys, in lesser number than the boxes
        // Copy the tables, starting with next toys and with less boxes

        //printf(" %d of type %d \n", b[j], A[i]);

        double *p;
        p = (double*)malloc((2*(n-i)+2*(m-j-1)) * sizeof(double));
        ap = p;
        Ap = ap + (n-i);
        bp = Ap + (n-i);
        Bp = bp + (m-j-1);
        memcpy(ap, a + i    , (n-i)  *sizeof(double));
        memcpy(Ap, A + i    , (n-i)  *sizeof(double));
        memcpy(bp, b + j + 1, (m-j-1)*sizeof(double));
        memcpy(Bp, B + j + 1, (m-j-1)*sizeof(double));

        ap[0] -= b[j]; // expend boxes

        ship = b[j] + solve(ap,Ap,bp,Bp,n-i,m-j-1);
        if (ship > max)
          max = ship;

      } else if (b[j] > a[i]) {
        // We found toys, in greater number than the boxes
        // Copy the tables, starting with less toys and next boxes

        //printf(" %d of type %d \n", a[i], A[i]);

        double *p;
        p = (double*)malloc((2*(n-i-1)+2*(m-j  )) * sizeof(double));
        ap = p;
        Ap = ap + (n-i-1);
        bp = Ap + (n-i-1);
        Bp = bp + (m-j  );
        memcpy(ap, a + i + 1, (n-i-1)*sizeof(double));
        memcpy(Ap, A + i + 1, (n-i-1)*sizeof(double));
        memcpy(bp, b + j    , (m-j  )*sizeof(double));
        memcpy(Bp, B + j    , (m-j  )*sizeof(double));

        bp[0] -= a[i]; // expend boxes

        ship = a[i] + solve(ap,Ap,bp,Bp,n-i-1,m-j);
        if (ship > max)
          max = ship;

      } else {
        // We found toys, in equal number to the boxes
        // Copy the tables, starting with next boxes and toys

        //printf(" %d of type %d \n", a[i], A[i]);

        double *p;
        p = (double*)malloc((2*(n-i-1)+2*(m-j-1)) * sizeof(double));
        ap = p;
        Ap = ap + (n-i-1);
        bp = Ap + (n-i-1);
        Bp = bp + (m-j-1);
        memcpy(ap, a + i + 1, (n-i-1)*sizeof(double));
        memcpy(Ap, A + i + 1, (n-i-1)*sizeof(double));
        memcpy(bp, b + j + 1, (m-j-1)*sizeof(double));
        memcpy(Bp, B + j + 1, (m-j-1)*sizeof(double));

        ship = a[i] + solve(ap,Ap,bp,Bp,n-i-1,m-j-1);
        if (ship > max)
          max = ship;

      }

      // we found first matching toys, next box
      break;

    }
  }

  return max;
}

int main() {
  int T, num=1;
  int i;
  unsigned long long ship;
  for (cin >> T; T--;) {
    cin >> N >> M;
    for (i = 0; i < N; i++) cin >> g_a[i] >> g_A[i];
    for (i = 0; i < M; i++) cin >> g_b[i] >> g_B[i];

    ship = floor(solve(g_a,g_A,g_b,g_B,N,M));

    printf("Case #%d: %llu\n", num++, ship);
  }
}
