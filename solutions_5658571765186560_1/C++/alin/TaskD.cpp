#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <search.h>

bool Solver(int X, int R, int C){
  int bigger, smaller, S;

  S = C * R;
  if( R > C ){
    bigger = R;
    smaller = C;
  }
  else{
    bigger = C;
    smaller = R;
  }

  if( S % X != 0 ){
    return false;
  }
  if( bigger < X ){
    return false;
  }
  switch( X ){
  case 1:
  case 2:
    return true;
  case 3:
    if( smaller < 2 ){
      return false;
    }
    return true;
  case 4:
    if( smaller < 3 ){
      return false;
    }
    return true;
  case 5:
    if( smaller < 3 ){
      return false;
    }
    if( (smaller == 3) && (bigger == 5) ){
      return false;
    }
    return true;
  case 6:
    if( smaller < 4 ){
      return false;
    }
    return true;
  }
  return false;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T, X, R, C;
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
    fscanf(filein, "%d %d %d\n", &X, &R, &C);
    printf("%d %d %d\n", X, R, C);

    // Solve & Output
    if( Solver(X, R, C) ){
      fprintf(fileout, "Case #%d: GABRIEL\n", t + 1);
    }
    else{
      fprintf(fileout, "Case #%d: RICHARD\n", t + 1);
    }
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
