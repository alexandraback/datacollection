#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int Smax, sum, res, t, i;
  char c;

  if( argc < 3 ){
    printf("Usage is: TaskA filein fileout\n");
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
    fscanf(filein, "%d\n", &Smax);
    printf("%d\n", Smax);
    res = 0;
    sum = 0;
    for( i = 0; i < Smax + 1; i ++){
      fscanf(filein, "%c", &c);
      printf("%c", c);
      sum += c - '0';
      if( sum < i + 1 ){
        res ++;
        sum ++;
      }
    }
    fscanf(filein, "\n");
    printf("\n");

    // Output
    fprintf(fileout, "Case #%d: %d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
