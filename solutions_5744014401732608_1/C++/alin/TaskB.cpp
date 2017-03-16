#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>


int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, B, i, j, max, A[50][50];
  long long Count[50], M, tmp;

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

  //Count[1] = 1;
  //for( i = 2; i < 50; i++ ){
  //  Count[i] = 0;
  //  for( j = 1; j < i; j ++ ){
  //    Count[i] += Count[j];
  //  }
  //  printf("Count[%d]=%lld\n", i, Count[i]);
  //}

  fscanf(filein, "%d\n", &T);
  printf("%d\n", T);
  for( t = 0; t < T; t ++ ){
    printf("-------------\t=%d\n", t);
    fscanf(filein, "%d %lld\n", &B, &M);
    printf("%d %lld\n", B, M);

    // Solve & Output
    if( M > (1ull << (B-2)) ){
      fprintf(fileout, "Case #%d: IMPOSSIBLE\n", t + 1);
      continue;
    }
    if( M == (1ull << (B-2)) ){
      fprintf(fileout, "Case #%d: POSSIBLE\n", t + 1);
      for( i = 0; i < B; i ++ ){
        for( j = 0; j <= i; j ++ ){
          fprintf(fileout,"%c", '0');
        }
        for( ; j < B; j ++ ){
          fprintf(fileout,"%c", '1');
        }
        fprintf(fileout,"\n");
      }
      continue;
    }
    for( i = 0; i < B; i ++ ){
      for( j = 0; j < B; j ++ ){
        A[i][j] = 0;
      }
    }
    i = B - 2;
    while( M != 0 ){
      for( j = i + 1; j < B; j ++ ){
        A[i][j] = 1;
      }
      if( M % 2 != 0 ){
        A[0][i] = 1;
      }
      M = M / 2;
      i --;
    }
    fprintf(fileout, "Case #%d: POSSIBLE\n", t + 1);
    for( i = 0; i < B; i ++ ){
      for( j = 0; j < B; j ++ ){
        fprintf(fileout,"%c", '0' + A[i][j]);
      }
      fprintf(fileout,"\n");
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
