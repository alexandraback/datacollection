#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i, Start, End;
  char S[1001], Res[2000];

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
    fscanf(filein, "%s\n", S);
    printf("%s\n", S);
    // Solve & Output

	memset(Res, '\0', 2000);
	Start = 999;
	Res[Start] = S[0];
	End = 1000;
	for( i = 1; i < strlen(S); i ++ ){
		if( S[i] < Res[Start] ){
			Res[End] = S[i];
			End ++;
		}
		else{
			Start --;
			Res[Start] = S[i];
		}
	}
	Res[End] = '\0';

    fprintf(fileout, "Case #%d: %s\n", t + 1, Res + Start);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
