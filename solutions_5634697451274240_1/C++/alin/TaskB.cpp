#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, D;
  int t, i, len, res;
  char pc[102];

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
    fscanf(filein, "%s\n", pc);
    len = strlen(pc);
    printf("%d %s\n", len, pc);

    // Solve & Output
    res = 0;
    for( i = 0; i < len - 1; i ++ ){
      if( pc[i] != pc[i+1] ){
        res ++;
      }
    }
    if( pc[len-1] == '-' ){
      res ++;
    }
    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
