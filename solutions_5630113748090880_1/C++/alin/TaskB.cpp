#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>


int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i, j, k, N, h;
  char S[2501];

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
    fscanf(filein, "%d\n", &N);
    printf("%d\n", N);
	for( i = 0; i < 2501; i ++ ){
		S[i] = 0;
	}
	for( i = 0; i < 2 * N - 1; i ++ ){
		for( j = 0; j < N - 1; j ++ ){
		    fscanf(filein, "%d ", &h);
		    printf("%d ", h);
			S[h] = S[h] ^ 1;
		}
		fscanf(filein, "%d\n", &h);
		printf("%d\n", h);
		S[h] = S[h] ^ 1;
	}

    // Solve & Output
    fprintf(fileout, "Case #%d:", t + 1);
	for( i = 0; i < 2501; i ++ ){
		if( S[i] != 0 ){
		    fprintf(fileout, " %d", i);
		}
	}
	fprintf(fileout, "\n");
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
