#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int Sizes[100];
int Nums[100];

int intcmp(const void * A, const void * B){
	if( *(int*)A < *(int*)B )
		return -1;
	if( *(int*)A > *(int*)B )
		return 1;
	return 0;
}

int Solver(int A, int N){
	int i, cur, nums, sizes, last;

	if( A == 1 ){
		return N;
	}
	qsort(Sizes, N, sizeof(int), intcmp);
	//for( i = 0; i < N; i ++ ){
	//	printf("%d ",Sizes[i]);
	//}
	//printf("\n");

	cur = A;
	for( i = 0; i < N; i ++ ){
		Nums[i] = 0;
		while( Sizes[i] >= cur ){
			cur = cur + cur - 1;
			Nums[i] ++;
		}
		cur += Sizes[i];

		//if( Sizes[i] < cur ){
		//	Nums[i] = 0;
		//	cur += Sizes[i];
		//}
		//else{

		//	Nums[i] = (Sizes[i] - cur) / (cur - 1) + 1;
		//	cur += (cur - 1) * Nums[i] + Sizes[i];
		//}
	}
	nums = 0;
	sizes = 0;
	last = N - 1;
	for( i = N - 1; i >= 0; i -- ){
		nums += Nums[i];
		sizes ++;
		if( nums > sizes ){
			last = i - 1;
			nums = 0;
			sizes = 0;
		}
	}
	if( last == -1 ){
		return N;
	}

	return (N-1) - last + nums;
}

int main(int argc, char *argv[]){
  FILE* filein;
  FILE* fileout;
  int T;
  int t, i;
  int res;
  int A, N;

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
    fscanf(filein, "%d %d\n", &A, &N);
    printf("%d %d\n", A, N);
    for( i = 0; i < N-1; i ++){
      fscanf(filein, "%d ", Sizes + i);
      printf("%d ", Sizes[i]);
    }
    fscanf(filein, "%d\n", Sizes + N - 1);
    printf("%d\n", Sizes[N-1]);

    // Solve & Output
    res = Solver(A, N);
    fprintf(fileout, "Case #%d: %I64u\n", t + 1, res);
  }

  fclose(fileout);
  fclose(filein);

  return 0;
}
