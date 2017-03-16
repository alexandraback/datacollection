#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

__int64 X, Y, XX, YY;
char Moves[1000000], D[4]={'N','W','S','E'};

void Check(void){
	__int64 len = strlen(Moves), X = 0, Y = 0;
	for( int i = 1; i <= len; i ++ ){
		switch( Moves[i-1] ){
		case 'N': Y+=i;break;
		case 'W': X-=i;break;
		case 'S': Y-=i;break;
		case 'E': X+=i;break;
		}
	}
	printf("X=%d, Y=%d\n", X, Y);
	if( (X!=XX)||(Y!=YY) ){
		printf("!!!!Incorrect!!!!\n");
	}
}

void Solver(void){
	__int64 i, Steps, XY;
	XX = X, YY = Y;

	for( Steps = 0, XY = 0; (abs(X)+abs(Y) > XY)||( (abs(X)+abs(Y)) % 2 == ((Steps-1)/2) % 2); Steps++, XY += Steps ){
		printf("Steps = %d, XY = %d, rest=%d\n", Steps, XY, ((Steps-1)/2) % 2);
	}
	printf("Steps = %d, XY = %d, rest=%d\n", Steps, XY, ((Steps-1)/2) % 2);
	Moves[Steps] = '\0';
	for( i = Steps; i > 0; i -- ){
		if( abs(X) > abs(Y) ){
			if( X > 0 ){
				X -= i;
				Moves[i-1] = D[3];
			}
			else{
				X += i;
				Moves[i-1] = D[1];
			}
		}	
		else{
			if( Y > 0 ){
				Y -= i;
				Moves[i-1] = D[0];
			}
			else{
				Y += i;
				Moves[i-1] = D[2];
			}
		}
	}
	printf("Moves = %s\n", Moves);
	Check();
	return;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t;

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
    fscanf(filein, "%I64d %I64d\n", &X, &Y);
    printf("%d %d\n", X, Y);

    // Solve & Output
    Solver();
    fprintf(fileout, "Case #%d: %s\n", t + 1, Moves);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
