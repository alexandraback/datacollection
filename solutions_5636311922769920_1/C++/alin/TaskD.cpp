#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <search.h>


int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, K, C, S;
  int t, i, j;
  unsigned long long num;

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
    fscanf(filein, "%d %d %d\n", &K, &C, &S);
    printf("%d %d %d\n", K, C, S);

    // Solve & Output
    if( K > C * S ){
      fprintf(fileout, "Case #%d: IMPOSSIBLE\n", t + 1);
      continue;
    }

    fprintf(fileout, "Case #%d:", t + 1);
    i = 0;
    do{
      num = i;
      for( j = 1; j < C; j ++ ){
        if( i < K - 1 ){
          i ++;
        }
        num = num * K + i;
//        printf(" %lld", num + 1);
      }
//      printf("\n-------------------");
      fprintf(fileout, " %lld", num + 1);
      i ++;
    }while( i < K );
    fprintf(fileout, "\n");
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
