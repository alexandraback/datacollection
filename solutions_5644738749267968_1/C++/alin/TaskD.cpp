#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <search.h>

double M1[1000], M2[1000];
int N;

int double_compare( const void *arg1, const void *arg2 ){
  if( *(double*)arg1 < *(double*)arg2 )
    return -1;
  if( *(double*)arg1 > *(double*)arg2 )
    return 1;
  return 0;
}

void Solver(FILE* fileout){
  int Max1 = N - 1, Min1 = 0, Max2 = N - 1, Min2 = 0, i, res1 = 0, res2 = 0;

  qsort( (void *) M1, (size_t) N, sizeof( double ), double_compare );
  qsort( (void *) M2, (size_t) N, sizeof( double ), double_compare );

  for( i = 0; i < N; i ++ ){
    if( M1[Min1] > M2[Min2] ){
      res1 ++;
      Min1 ++;
      Min2 ++;
    }
    else{
      Min1 ++;
      Max2 --;
    }
  }

  Max1 = N - 1;
  Min1 = 0;
  Max2 = N - 1;
  Min2 = 0;
  for( i = 0; i < N; i ++ ){
    if( M1[Max1] > M2[Max2] ){
      res2 ++;
      Max1 --;
      Min2 ++;
    }
    else{
      Max1 --;
      Max2 --;
    }
  }

  fprintf(fileout, "%d %d\n", res1, res2);
  return;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int res, t, i;

  if( argc < 3 ){
    printf("Usage is: TaskD filein fileout\n");
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
    fscanf(filein, "%d\n", &N);
    printf("%d\n", N);
    for( i = 0; i < N - 1; i ++){
      fscanf(filein, "%lf ", &(M1[i]));
      printf("%lf ", (M1[i]));
    }
    fscanf(filein, "%lf\n", &(M1[N-1]));
    printf("%lf\n", (M1[N-1]));
    for( i = 0; i < N - 1; i ++){
      fscanf(filein, "%lf ", &(M2[i]));
      printf("%lf ", (M2[i]));
    }
    fscanf(filein, "%lf\n", &(M2[N-1]));
    printf("%lf\n", (M2[N-1]));

    // Solve & Output
    fprintf(fileout, "Case #%d: ", t + 1);
    Solver(fileout);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
