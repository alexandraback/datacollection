#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, N, J;
  unsigned int a, aa;
  long long A[9],M[32];
  char s[33];
  int t, i, j, k, odd, even;

  if( argc < 3 ){
    printf("Usage is: TaskC filein fileout\n");
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
    fscanf(filein, "%d %d\n", &N, &J);
    printf("%d %d\n", N, J);

    a = (1 << (N-1)) + 1;
    printf("a=%d\n", a);
    // Solve & Output
    fprintf(fileout, "Case #%d:\n", t + 1);
    for( j = 0; j < J ; j ++ ){
      for( ; ; a = a + 2){
        odd = 0;
        even = 0;
        for( aa = a; aa > 0; ){
          if( aa % 2 != 0 ){
            even ++;
          }
          aa = aa / 2;
          if( aa % 2 != 0 ){
            odd ++;
          }
          aa = aa / 2;
        }
        if( odd == even ){
          break;
        }
      }
      for( i = N - 1; i >= 0; i -- ){
        fprintf(fileout, "%c", '0' + ((a >> i) & 1) );
      }
      fprintf(fileout, " 3 4 5 6 7 8 9 10 11\n");
      //for( k = 2; k <= 10; k ++ ){
      //  M[k-2] = 1;
      //  A[k-2] = 0;
      //}
      //for( i = 0; i < N; i ++ ){
      //  for( k = 2; k <= 10; k ++ ){
      //    A[k-2] += ((a >> i) & 1) * M[k-2];
      //    M[k-2] = M[k-2] * k;
      //  }
      //}
      //for( k = 2; k <= 10; k ++ ){
      //  printf("a with %2d = %d\n", k, A[k-2]);
      //  printf(" divided by %2d = %d\n", k+1, A[k-2]/(k+1));
      //}
      a = a + 2;
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
