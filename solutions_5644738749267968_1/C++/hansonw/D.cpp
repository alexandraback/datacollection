#include <iostream>
#include <algorithm>
using namespace std;

double A[1111];
double B[1111];

int main()
{
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> B[i];
    }

    sort(A, A+N);
    sort(B, B+N);

    int deceit = 0, real = 0;
    int j = 0;
    for (int i = 0; i < N; i++) {
      while (j < N && B[j] < A[i]) {
        j++;
      }
      if (j == N) real++;
      else j++;
    }

    int lj = 0, hj = N-1;
    for (int i = 0; i < N; i++) {
      if (A[i] < B[lj]) {
        // This weight can't possibly win anything. just use it to waste a high piece
        hj--;
      } else {
        // We can take the smallest one if we just bid astronomically high!
        deceit++;
        lj++;
      }
    }
    
    printf("Case #%d: %d %d\n", t, deceit, real);
  }
}
