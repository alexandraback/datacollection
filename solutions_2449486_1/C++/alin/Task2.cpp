#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int A[100][100];
char Amax[2][100];

int Solver(int N, int M){
  int i, j;
  for( i = 0; i < 100; i ++){
    Amax[0][i] = 0;
    Amax[1][i] = 0;
  }
  for( i = 0; i < N; i ++ )
    for( j = 0; j < M; j ++ ){
      if( Amax[0][i] < A[i][j] )
        Amax[0][i] = A[i][j];
      if( Amax[1][j] < A[i][j] )
        Amax[1][j] = A[i][j];
    }
  for( i = 0; i < N; i ++ )
    for( j = 0; j < M; j ++ )
      if( (A[i][j] < Amax[0][i]) && (A[i][j] < Amax[1][j]) )
        return 0;

  return 1;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, N, M;
  int res, t, i, j;

  if( argc < 3 ){
    printf("Usage is: task1 filein fileout\n");
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
    fscanf(filein, "%d %d\n", &N, &M);
    printf("%d %d\n", N, M);
    for( i = 0; i < N; i ++){
      for( j = 0; j < M - 1; j ++ ){
        fscanf(filein, "%d ", &(A[i][j]));
        printf("%d ", (A[i][j]));
      }
      fscanf(filein, "%d\n", &(A[i][M-1]));
      printf("%d\n", (A[i][M-1]));
    }

    // Solve & Output
    if( res = Solver(N, M) )
      fprintf(fileout, "Case #%d: YES\n", t + 1);
    else
      fprintf(fileout, "Case #%d: NO\n", t + 1);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
