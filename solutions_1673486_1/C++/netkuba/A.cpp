#include <cstdio>

double min(double A, double B) {
  if (A < B) {
    return A;
  }
  return B;
}

int caseCount = 0;
void make() {
  int A, B; scanf(" %d %d", &A, &B);

  double * partRes = new double[A+1];
  partRes[0] = B + 1;
  double mult = 1;
  
  for (int i=0; i<A; ++i) {
    double p; scanf(" %lf", &p);
    mult *= p;
    partRes[i+1] = partRes[i] + 1;
    partRes[i+1] = min(partRes[i+1], (double)(B - i) +  (1 - mult) * partRes[0]);
    partRes[i+1] = min(partRes[i+1], 1 + partRes[0]);
  }
  /*
  for (int i=0; i<A+1; ++i) {
    printf("%.2lf ", partRes[i]);
  }
  printf("\n");
  */
  printf("Case #%d: %.7lf\n", ++caseCount, partRes[A]);
  return;
}

int main() {
  int t; scanf(" %d", &t);
  while(t--) {
    make();
  }
  return 0;
}
