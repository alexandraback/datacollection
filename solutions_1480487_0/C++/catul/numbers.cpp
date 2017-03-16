#include <cstdio>
#include <iostream>
using namespace std;

int s[201];
int safe[201];
double yi[201];

int main() {
  int T, N, num=1;
  for (cin >> T; T--;) {
    int X = 0, i, effN;
    double avg;
    cin >> N;
    for (i = 0; i < N; i++) {
      cin >> s[i];
      X += s[i];
    }

    printf("Case #%d:", num++);

    memset(safe,0,sizeof(safe));
check_safe:
    effN = N;
    avg  = 2*X;
    for (i=0; i<N; i++) if (safe[i]) {
      effN--;
      avg -= s[i];
    }
    avg /= effN;
    for (i=0; i<N; i++) {
      if (s[i] < avg && safe[i]) {
        safe[i] = 0;
        goto check_safe;
      }
      if (s[i] > avg && safe[i] == 0) {
        safe[i] = 1;
        goto check_safe;
      }
    }

    for (i = 0; i < N; i++) {
      if (safe[i])
        yi[i] = 0;
      else
        yi[i] = max(0., (100.*avg - 100.*s[i])/X);
      printf(" %.6lf", yi[i]);
    }
    printf("\n");
  }
}
