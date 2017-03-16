#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>

char V[1000];
int Got[10000001], Spent[10000001];

__int64 Solver(int E, int R, int N){
	int i, j, e;
	__int64 res;

	for( i = 0; i < N; i ++ ){
		Got[i] = R;
		Spent[i] = 0;
	}
	Got[0] = E;

	for( i = N-1; i >= 0; i -- ){
		e = Got[i];
		for( j = i - 1; j >= 0; j -- ){
			if( V[j] > V[i] ){
				break;
			}
			if( e + Got[j] < E ){
				e += Got[j];
				Got[j] = 0;
			}
			else{
				Got[j] -= E - e;
				e = E;
			}
			if( e == E ){
				break;
			}
		}
		Spent[i] = e;
	}

	res = 0;
	for( i = 0; i < N; i ++ ){
		printf("%d ", Got[i]);
	}
	printf("\n");
	for( i = 0; i < N; i ++ ){
		res += Spent[i] * V[i];
		printf("%d ", Spent[i]);
	}
	printf("\n");

	return res;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i;
  int E, R, N;
  __int64 res;

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
    fscanf(filein, "%d %d %d\n", &E, &R, &N);
    printf("%d %d %d\n", E, R, N);
    for( i = 0; i < N-1; i ++){
      fscanf(filein, "%d ", V + i);
      printf("%d ", V[i]);
    }
    fscanf(filein, "%d\n", V + N - 1);
    printf("%d\n", V[N-1]);

    // Solve & Output
    res = Solver(E, R, N);
    fprintf(fileout, "Case #%d: %I64d\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
