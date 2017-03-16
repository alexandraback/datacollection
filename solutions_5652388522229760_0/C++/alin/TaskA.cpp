#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int N, NN, NNN, res, t, i;
  int flags[10], fcount;

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
    fscanf(filein, "%d\n", &N);
    printf("%d\n", N);
    if( N == 0 ){
      // Output
      fprintf(fileout, "Case #%d: INSOMNIA\n", t + 1);
      continue;
    }
    fcount = 0;
    for( i = 0; i < 10; i ++ ){
      flags[i] = 0;
    }
    for( NN = N; true; NN += N ){
      for( NNN = NN; NNN > 0; NNN = NNN / 10 ){
        flags[NNN%10] = 1;
      }
      fcount = 0;
      for( i = 0; i < 10; i ++ ){
        fcount += flags[i];
      }
      if( fcount == 10 ){
        break;
      }
    }

    // Output
    fprintf(fileout, "Case #%d: %d\n", t + 1, NN);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
