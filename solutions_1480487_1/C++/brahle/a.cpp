#include <cstdio>
const int MAXN = 220;

int n;
int J[MAXN];
double X;

bool provjeri(int t, double koliko) {
  double ostalo = 1 - koliko;
  double bodova = J[t] + koliko*X;

  for (int i = 0; i < n; ++i) {
    if (i == t) continue;
    if (J[i] > bodova) continue;
    double trebam = bodova - J[i];
    ostalo -= trebam / X;
  }

  //  printf("ako za %d dam %g, ostat ce mi %g.\n", t, koliko, ostalo);
  return ostalo <= 0.0;
}

double izracunaj(int t) {
  double L = 0.0, R = 1.0, M;
  for (int k = 0; k < 100; ++k) {
    M = (L+R)/2;
    if (provjeri(t, M)) {
      R = M;
    } else {
      L = M;
    }
  }

  return L*100.0;
}

int main() {
  int numCases = 1;
  scanf("%d", &numCases);
  for (int caseIt = 0; caseIt < numCases; ++caseIt) {
    printf("Case #%d:", caseIt+1);
    scanf("%d", &n);
    X = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &J[i]);
      X += J[i];
    }

    for (int i = 0; i < n; ++i) {
      printf(" %g", izracunaj(i));
    }
    printf("\n");
  }

  return 0;
}

