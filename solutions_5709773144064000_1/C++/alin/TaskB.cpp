#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

double Solver(double C, double F, double X){
  double res = 0.0, Time1, Time2, Time3;
  int N = 0;

  Time1 = X / (2.0 + N * F);
  Time2 = X / (2.0 + (N + 1) * F);
  Time3 = C / (2.0 + N * F);

  while( Time1 > Time2 + Time3 ){
    N ++;
    res += Time3;
    Time1 = X / (2.0 + N * F);
    Time2 = X / (2.0 + (N + 1) * F);
    Time3 = C / (2.0 + N * F);
  }
  res += Time1;

  return res;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t;
  double C, F, X, res;

  if( argc < 3 ){
    printf("Usage is: TaskB filein fileout\n");
    return 0;
  }

  // Input 

  filein = fopen(argv[1], "r");
  if( filein == NULL ){
    printf("Error open(); filein\n");
    return 0;
  }
  fileout = fopen(argv[2], "w");
  if( fileout == NULL ){
    printf("Error open(); fileout\n");
    return 0;
  }

  fscanf(filein, "%d\n", &T);
  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
    printf("-------------\t=%d\n", t);
    fscanf(filein, "%lf %lf %lf\n", &C, &F, &X);
    printf("%lf %lf %lf\n", C, F, X);

    // Solve & Output
    res = Solver(C, F, X);
    fprintf(fileout, "Case #%d: %.7f\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
