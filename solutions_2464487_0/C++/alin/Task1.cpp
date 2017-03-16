#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

char A[1000][4][4];
char Answers[4][30] = {"X won", "O won", "Draw", "Game has not completed"};

__int64 Solver(__int64 r, __int64 t1){
	unsigned __int64 max, min = 1, cur, i, t3, t4;

	max = sqrt((long double)t1) + 1;
	if( max > t1 / r / 2 )
		max = t1 / r / 2 + 1;
	cur = (max+min)/2;
	t3 = cur * 2*r;
	t3 += cur * (2*cur - 1);
//	t3 = cur * (2*r + 2*cur - 1);
	t4 = (cur+1) * (2*r + 2*(cur+1) - 1);
	while( (t4 <= t1)||(t3 > t1) ){
		if( t4 <= t1 ){
			min = cur;
		}
		if( t3 > t1){
			max = cur;
		}
		cur = (max+min)/2;
		t3 = cur * 2*r;
		t3 += cur * (2*cur - 1);
//		t3 = cur * (2*r + 2*cur - 1);
		t4 = (cur+1) * (2*r + 2*(cur+1) - 1);
	}

//	N = -(2*r-1)/2+sqrt((long double)((2*(long double)r-1)*(2*(long double)r-1)/2/2)+t1);
	return cur;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i;
  __int64 res, r, t1;

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
    fscanf(filein, "%I64d %I64d\n", &r, &t1);
    printf("%I64d %I64d\n", r, t1);

    // Solve & Output
    res = Solver(r, t1);
    fprintf(fileout, "Case #%d: %I64d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
